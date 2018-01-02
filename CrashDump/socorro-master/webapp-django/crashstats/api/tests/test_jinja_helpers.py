from nose.tools import eq_

from crashstats.base.tests.testbase import TestCase
from crashstats.api.templatetags.jinja_helpers import pluralize


class TestPluralize(TestCase):

    def test_basics(self):
        eq_(pluralize(0), 's')
        eq_(pluralize(1), '')
        eq_(pluralize(59), 's')

    def test_overide_s(self):
        eq_(pluralize(59, 'ies'), 'ies')
