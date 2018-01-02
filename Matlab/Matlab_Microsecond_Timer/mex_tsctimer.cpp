// mex_tsctimer.cpp : Defines the entry point for the DLL application.

#include "mex.h"
#include "Matlab.h"    //MATLAB API
//#include "stdafx.h"
#include <windows.h>
#include "TSCtime.h"


char *msg[] = {"recalibrate()", "gethectonanotime_last()", "gethectonanotime_first()"};

#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmat.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libmatlb.lib")

void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  const char     str[]="Function 'mexeval' not defined for variables of class";
  char           errMsg[100];
  //
  const mxArray *in_data;
  int            select = 0;
  //
  ULONGLONG      t_meas = 0;
  double        *outArray;

  //mexPrintf("executing mex_tsctimer(%d)\n", nrhs);
  //
  if(nrhs==0) {
    sprintf(errMsg,"%s '%s'\n",str,"double");
    mexErrMsgTxt(errMsg);
  }
  else { // causes MATLAB to execute the string as an expression
    //
    in_data = prhs[0];
    select = (int)(mxGetScalar(prhs[0]));
    //mexPrintf("%d selects %s\n", select, msg[select]);
    //
         if (select == 0) recalibrate();
	  else if (select == 1) t_meas = gethectonanotime_first();
	  else if (select == 2) t_meas = gethectonanotime_last();
    //
    plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL);
    outArray = mxGetPr(plhs[0]);
    outArray[0] = ((double)t_meas)/1e7;
    //
    //mexPrintf("measured time %f = %f\n", outArray[0], ((double)t_meas)/1e7);
    //
  }
}

// mex_tsctimer.cpp