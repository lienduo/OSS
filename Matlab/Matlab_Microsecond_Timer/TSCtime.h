// TSCtime.h : header file for high-precision time library
//

// $Id: TSCtime.h,v 1.4 2003/09/25 17:07:23 kw217 Exp $

//
// Copyright (c) 2003, Keith Wansbrough
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//     * Redistributions of source code must retain the above
//       copyright notice, this list of conditions and the following
//       disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of the University of Cambridge nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//

// (for information only: this is the BSD license as found on
//  http://www.opensource.org/licenses/bsd-license.php)

#ifndef __TSC_TIME__
#define __TSC_TIME__

#include <windows.h>

// NB: epoch for hectonanotime is January 1, 1601 UTC,
//     so subtract 11644473600 seconds to get Unix time.
//     (369 years, 89 of which are leap years;
//      = 134774 days)
#define UNIX_EPOCH 116444736000000000ui64
#define nreps 5  // number of ticks to examine; we take the average.

// TSCtime function prototypes
//
__int64 gettsc();
__int64 hectonanotime_of_tsc(__int64);
__int64 gethectonanotime_first();
__int64 gethectonanotime_norecal();
__int64 gethectonanotime_last();
void    recalibrate();

#endif // __TSC_TIME__

// TSCtime.h


