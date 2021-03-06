/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*jslint browser:true, regexp:false, plusplus:false, jQuery:false */
/*global window, $, BugLinks */

var Correlations = (function() {

    // a hash table (for uniqueness)
    var osnames = {};
    // the different types of correlation reports
    var correlations = ['core-counts', 'interesting-addons',
                        'interesting-modules'];

    // This DOM element has all the data attributes we need to transfer
    // from the rendering into this JavaScript.
    var $container = $('#mainbody');
    var sig_base = $container.data('correlations-sig-base');
    var base = $container.data('correlations-base');
    var product = $container.data('product');
    var version = $container.data('version');
    var loadingImage = $('<img/>')
        .attr('src', $container.data('loading-img'))
        .attr('width', 16)
        .attr('height', 17);

    function loadCorrelations(types, callback) {
        // If there is no osname, that means there is no results, and thus no
        // need to bother loading correlations.
        if (!Object.keys(osnames).length) {
            return;
        }
        var data = {
            correlation_report_types: types,
            product: product,
            version: version,
            platforms: [],
        };
        for (var platform in osnames) {
            data.platforms.push(platform);
        }
        $.getJSON(sig_base + '?' + Qs.stringify(data, { indices: false }))
        .done(function (json) {
            var all_signatures = {};
            $.each(json, function(type) {
                json[type].hits.forEach(function(sig) {
                    all_signatures[sig] = 1;
                });
            });
            callback(all_signatures);
        });
    }

    function expandCorrelation($element) {
        var row = $element.parents('tr');

        $('.correlation-cell .top span', row).empty().append(loadingImage);
        var osname = row.find('.osname').text();
        var signature = row.find('.signature').attr('title');
        var data = {
            platform: osname,
            signature: signature,
            product: product,
            version: version,
            correlation_report_types: correlations,
        };

        $.getJSON(base + '?' + Qs.stringify(data, { indices: false }))
        .done(function(json) {
            for (var i in correlations) {
                var type = correlations[i];
                var report = '<h3>' + json[type].reason + '</h3>';
                report += json[type].load.split('\n').join('<br>');
                row.find('.' + type).html(report);
            }

            $('.correlation-cell .top span', row).html('');
            $('.correlation-cell div div.complete', row).show();
            $element.text('Show Less');
        });


        return false;
    }

    function contractCorrelation($element) {
        var row = $element.parents('tr');
        $('.correlation-cell div div.complete', row).hide();
        $element.text('Show More');
        return false;
    }

    return {
        init: function() {
            // update the correlation-panel .top and .complete
            // FIXME surely we could get the osnames without trolling the DOM...
            $('td a.signature').each(function () {
                var row = $(this).parents('tr');
                var osname = row.find('.osname').text();
                // only need a set of unique names
                osnames[osname] = 1;
            });

            // set up an expander clicker
            $('.correlation-cell a.correlation-toggler').click(function() {
                var $element = $(this);
                var was_clicked = $element.hasClass('__clicked');
                // close all expanded
                $('.__clicked').each(function() {
                    contractCorrelation($(this).removeClass('__clicked'));
                });
                if (!was_clicked) {
                    expandCorrelation($element.addClass('__clicked'));
                }
                return false;
            });

            $.ajaxSetup({
                error: function() {
                    $('.correlation-cell .top span').html('Error loading correlation report');
                },
            });

            // prepare for AJAX loading
            $('.correlation-cell .top span').empty().append(loadingImage);

            // for each type of correlation start downloading all signatures that
            // have correlations
            function correlationsTypeLoaded(all_signatures) {
                // all correlation types have fully called back,
                // let's finish up things
                $('.signature').each(function() {
                    var signature = $(this).attr('title');
                    if (all_signatures[signature]) {
                        $(this).parents('tr')
                        .find('.correlation-toggler')
                        .show();
                    }
                });
                $('.correlation-cell .top span').html('');
            }
            loadCorrelations(correlations, correlationsTypeLoaded);
        },
    };
})();

$(document).ready(function () {
    var perosTbl = $('#peros-tbl');

    $('#signature-list').tablesorter({
        sortInitialOrder: 'desc',
        headers: {
            0: { sorter: 'digit' },
            1: { sorter: false },
            5: { sorter: 'digit' },
            6: { sorter: 'digit' },
            7: { sorter: 'digit' },
            8: { sorter: 'digit' },
            9: { sorter: 'date' },  // First Appearance
            11: { sorter: false },  // Bugzilla IDs
            12: { sorter: false },  // Correlation
        },
    });

    perosTbl.tablesorter({
        headers: {
            0: { sorter: 'digit' },
            1: { sorter: false },
            4: { sorter: 'text' },
            5: { sorter: 'digit' },
            6: { sorter: 'digit' },
            7: { sorter: 'digit' },
        },
    });

    $('#signature-list tr, #peros-tbl tr').each(function() {
        $.data(this, 'graphable', true);
    });

    // Enhance bug links.
    BugLinks.enhanceExpanded();

    /* Initialize things */
    Correlations.init();
});
