/*
 * MATLAB Compiler: 2.1
 * Date: Sun May 25 20:21:25 2003
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on" "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O" "array_indexing:on" "-O" "optimize_conditionals:on" "-B" "C:\Documents and Settings\daniel\Application Data\MathWorks\MATLAB\R12\mccpath" "-I" "C:\matlabR12\toolbox\matlab\general" "-I" "C:\matlabR12\toolbox\matlab\ops" "-I" "C:\matlabR12\toolbox\matlab\lang" "-I" "C:\matlabR12\toolbox\matlab\elmat" "-I" "C:\matlabR12\toolbox\matlab\elfun" "-I" "C:\matlabR12\toolbox\matlab\specfun" "-I" "C:\matlabR12\toolbox\matlab\matfun" "-I" "C:\matlabR12\toolbox\matlab\datafun" "-I" "C:\matlabR12\toolbox\matlab\audio" "-I" "C:\matlabR12\toolbox\matlab\polyfun" "-I" "C:\matlabR12\toolbox\matlab\funfun" "-I" "C:\matlabR12\toolbox\matlab\sparfun" "-I" "C:\matlabR12\toolbox\matlab\graph2d" "-I" "C:\matlabR12\toolbox\matlab\graph3d" "-I" "C:\matlabR12\toolbox\matlab\specgraph" "-I" "C:\matlabR12\toolbox\matlab\graphics" "-I" "C:\matlabR12\toolbox\matlab\uitools" "-I" "C:\matlabR12\toolbox\matlab\strfun" "-I" "C:\matlabR12\toolbox\matlab\iofun" "-I" "C:\matlabR12\toolbox\matlab\timefun" "-I" "C:\matlabR12\toolbox\matlab\datatypes" "-I" "C:\matlabR12\toolbox\matlab\verctrl" "-I" "C:\matlabR12\toolbox\matlab\winfun" "-I" "C:\matlabR12\toolbox\matlab\demos" "-I" "C:\matlabR12\toolbox\local" "-I" "C:\matlabR12\toolbox\simulink\simulink" "-I" "C:\matlabR12\toolbox\simulink\blocks" "-I" "C:\matlabR12\toolbox\simulink\simdemos" "-I" "C:\matlabR12\toolbox\simulink\simdemos\aerospace" "-I" "C:\matlabR12\toolbox\simulink\simdemos\automotive" "-I" "C:\matlabR12\toolbox\simulink\simdemos\simfeatures" "-I" "C:\matlabR12\toolbox\simulink\simdemos\simgeneral" "-I" "C:\matlabR12\toolbox\simulink\simdemos\simnew" "-I" "C:\matlabR12\toolbox\simulink\dee" "-I" "C:\matlabR12\toolbox\stateflow\stateflow" "-I" "C:\matlabR12\toolbox\stateflow\sfdemos" "-I" "C:\matlabR12\toolbox\stateflow\coder" "-I" "C:\matlabR12\toolbox\rtw\rtw" "-I" "C:\matlabR12\toolbox\rtw\rtwdemos" "-I"
 * "C:\matlabR12\toolbox\rtw\targets\asap2\asap2" "-I" "C:\matlabR12\toolbox\rtw\targets\asap2\asap2\user" "-I" "C:\matlabR12\toolbox\rtw\accel" "-I" "C:\matlabR12\toolbox\rtw\ada" "-I" "C:\matlabR12\toolbox\cdma\cdma" "-I" "C:\matlabR12\toolbox\cdma\cdmamasks" "-I" "C:\matlabR12\toolbox\cdma\cdmamex" "-I" "C:\matlabR12\toolbox\cdma\cdmademos" "-I" "C:\matlabR12\toolbox\comm\comm" "-I" "C:\matlabR12\toolbox\comm\commdemos" "-I" "C:\matlabR12\toolbox\comm\commobsolete" "-I" "C:\matlabR12\toolbox\commblks\commblks" "-I" "C:\matlabR12\toolbox\commblks\commmasks" "-I" "C:\matlabR12\toolbox\commblks\commmex" "-I" "C:\matlabR12\toolbox\commblks\commblksdemos" "-I" "C:\matlabR12\toolbox\commblks\commblksobsolete" "-I" "C:\matlabR12\toolbox\compiler" "-I" "C:\matlabR12\toolbox\control\control" "-I" "C:\matlabR12\toolbox\control\ctrlguis" "-I" "C:\matlabR12\toolbox\control\ctrlobsolete" "-I" "C:\matlabR12\toolbox\control\ctrlutil" "-I" "C:\matlabR12\toolbox\control\ctrldemos" "-I" "C:\matlabR12\toolbox\daq\daq" "-I" "C:\matlabR12\toolbox\daq\daqdemos" "-I" "C:\matlabR12\toolbox\database\database" "-I" "C:\matlabR12\toolbox\database\dbdemos" "-I" "C:\matlabR12\toolbox\database\vqb" "-I" "C:\matlabR12\toolbox\datafeed\datafeed" "-I" "C:\matlabR12\toolbox\datafeed\dfgui" "-I" "C:\matlabR12\toolbox\dials" "-I" "C:\matlabR12\toolbox\dspblks\dspblks" "-I" "C:\matlabR12\toolbox\dspblks\dspmasks" "-I" "C:\matlabR12\toolbox\dspblks\dspmex" "-I" "C:\matlabR12\toolbox\dspblks\dspdemos" "-I" "C:\matlabR12\toolbox\dspblks\dsprtw\util_c" "-I" "C:\matlabR12\toolbox\rtw\targets\ecoder" "-I" "C:\matlabR12\toolbox\exlink" "-I" "C:\matlabR12\toolbox\filterdesign\filterdesign" "-I" "C:\matlabR12\toolbox\filterdesign\quantization" "-I" "C:\matlabR12\toolbox\filterdesign\filtdesdemos" "-I" "C:\matlabR12\toolbox\finance\finance" "-I" "C:\matlabR12\toolbox\finance\calendar" "-I" "C:\matlabR12\toolbox\finance\findemos" "-I" "C:\matlabR12\toolbox\finance\finsupport" "-I" "C:\matlabR12\toolbox\finderiv\finderiv" "-I"
 * "C:\matlabR12\toolbox\fixpoint" "-I" "C:\matlabR12\toolbox\fixpoint\fxpdemos" "-I" "C:\matlabR12\toolbox\fixpoint\obsolete" "-I" "C:\matlabR12\toolbox\ftseries\ftseries" "-I" "C:\matlabR12\toolbox\ftseries\ftsdemos" "-I" "C:\matlabR12\toolbox\ftseries\ftsdata" "-I" "C:\matlabR12\toolbox\ftseries\ftstutorials" "-I" "C:\matlabR12\toolbox\fuzzy\fuzzy" "-I" "C:\matlabR12\toolbox\fuzzy\fuzdemos" "-I" "C:\matlabR12\toolbox\garch\garch" "-I" "C:\matlabR12\toolbox\garch\garchdemos" "-I" "C:\matlabR12\toolbox\ident\ident" "-I" "C:\matlabR12\toolbox\ident\idobsolete" "-I" "C:\matlabR12\toolbox\ident\idguis" "-I" "C:\matlabR12\toolbox\ident\idutils" "-I" "C:\matlabR12\toolbox\ident\iddemos" "-I" "C:\matlabR12\toolbox\ident\idhelp" "-I" "C:\matlabR12\toolbox\images\images" "-I" "C:\matlabR12\toolbox\images\imdemos" "-I" "C:\matlabR12\toolbox\instrument\instrument" "-I" "C:\matlabR12\toolbox\instrument\instrumentdemos" "-I" "C:\matlabR12\toolbox\lmi\lmictrl" "-I" "C:\matlabR12\toolbox\lmi\lmilab" "-I" "C:\matlabR12\toolbox\map\map" "-I" "C:\matlabR12\toolbox\map\mapdisp" "-I" "C:\matlabR12\toolbox\map\mapproj" "-I" "C:\matlabR12\toolbox\simulink\mdldiff" "-I" "C:\matlabR12\toolbox\motdsp\motdsp" "-I" "C:\matlabR12\toolbox\motdsp\motdspmex" "-I" "C:\matlabR12\toolbox\motdsp\motdspasm\bin" "-I" "C:\matlabR12\toolbox\motdsp\motdspblks" "-I" "C:\matlabR12\toolbox\motdsp\motdspmasks" "-I" "C:\matlabR12\toolbox\motdsp\motdspdemos" "-I" "C:\matlabR12\toolbox\mpc\mpccmds" "-I" "C:\matlabR12\toolbox\mpc\mpcdemos" "-I" "C:\matlabR12\toolbox\mutools\commands" "-I" "C:\matlabR12\toolbox\mutools\subs" "-I" "C:\matlabR12\toolbox\ncd" "-I" "C:\matlabR12\toolbox\nnet\nnet" "-I" "C:\matlabR12\toolbox\nnet\nnutils" "-I" "C:\matlabR12\toolbox\nnet\nncontrol" "-I" "C:\matlabR12\toolbox\nnet\nndemos" "-I" "C:\matlabR12\toolbox\nnet\nnobsolete" "-I" "C:\matlabR12\toolbox\optim" "-I" "C:\matlabR12\toolbox\pde" "-I" "C:\matlabR12\toolbox\powersys\powersys" "-I" "C:\matlabR12\toolbox\powersys\powerdemo" "-I" "C:\matlabR12\toolbox\reqmgt" "-I"
 * "C:\matlabR12\toolbox\robust" "-I" "C:\matlabR12\toolbox\rptgen" "-I" "C:\matlabR12\toolbox\rptgenext" "-I" "C:\matlabR12\toolbox\sb2sl" "-I" "C:\matlabR12\toolbox\signal\signal" "-I" "C:\matlabR12\toolbox\signal\fdatoolgui" "-I" "C:\matlabR12\toolbox\signal\sptoolgui" "-I" "C:\matlabR12\toolbox\signal\sigdemos" "-I" "C:\matlabR12\toolbox\simulink\simcoverage" "-I" "C:\matlabR12\toolbox\splines" "-I" "C:\matlabR12\toolbox\stats" "-I" "C:\matlabR12\toolbox\symbolic" "-I" "C:\matlabR12\toolbox\wavelet\wavelet" "-I" "C:\matlabR12\toolbox\wavelet\wavedemo" "-I" "C:\matlabR12\toolbox\rtw\targets\xpc\xpc" "-I" "C:\matlabR12\toolbox\rtw\targets\xpc\target\build\xpcblocks" "-I" "C:\matlabR12\toolbox\rtw\targets\xpc\xpcdemos" "-I" "C:\matlabR12\toolbox\rtw\targets\xpc\target\kernel\embedded" "-I" "C:\matlabR12\work" "-I" "C:\matlabR12\daniel" "-I" "C:\matlabR12\daniel\bitoperations" "-I" "C:\matlabR12\daniel\geometria" "-L" "C" "libmmfile.mlib" "-A" "line:on" "-G" "-A" "debugline:on" "-O" "fold_scalar_mxarrays:off" "-O" "fold_non_scalar_mxarrays:off" "-O" "optimize_integer_for_loops:off" "-O" "array_indexing:off" "-O" "optimize_conditionals:off" "libmmfile.mlib" "-v" "-I" "E:\trabajos\daniel\practicasC++\conv" "-t" "-T" "codegen" "E:\trabajos\daniel\practicasC++\conv\MyFunc.m" 
 */
#include "MyFunc.h"
#include "libmatlbm.h"
#include "libmmfile.h"

void InitializeModule_MyFunc(void) {
}

void TerminateModule_MyFunc(void) {
}

static mxArray * MMyFunc(int nargout_, mxArray * In1, mxArray * In2);

_mexLocalFunctionTable _local_function_table_MyFunc = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfMyFunc" contains the normal interface for the "MyFunc" M-function from file "E:\trabajos\daniel\practicasC++\conv\MyFunc.m" (lines 1-4). This function processes any input arguments and passes them to the implementation version of the function, appearing above.
 */
mxArray * mlfMyFunc(mxArray * In1, mxArray * In2) {
    int nargout = 1;
    mxArray * out = mclGetUninitializedArray();
    mlfEnterNewContext(0, 2, In1, In2);
    out = MMyFunc(nargout, In1, In2);
    mlfRestorePreviousContext(0, 2, In1, In2);
    return mlfReturnValue(out);
}

/*
 * The function "mlxMyFunc" contains the feval interface for the "MyFunc" M-function from file "E:\trabajos\daniel\practicasC++\conv\MyFunc.m" (lines 1-4). The feval function calls the implementation version of MyFunc through this function. This function processes any input arguments and passes them to the implementation version of the function, appearing above.
 */
void mlxMyFunc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(mxCreateString("Run-time Error: File: MyFunc Line: 1 Column: 1 The function \"MyFunc\" was called with more than the declared number of outputs (1)."));
    }
    if (nrhs > 2) {
        mlfError(mxCreateString("Run-time Error: File: MyFunc Line: 1 Column: 1 The function \"MyFunc\" was called with more than the declared number of inputs (2)."));
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = mclGetUninitializedArray();
    }
    for (i = 0; i < 2 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 2; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 2, mprhs[0], mprhs[1]);
    mplhs[0] = MMyFunc(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "MMyFunc" is the implementation version of the "MyFunc" M-function from file "E:\trabajos\daniel\practicasC++\conv\MyFunc.m" (lines 1-4). It contains the actual compiled code for that M-function. It is a static function and must only be called from one of the interface functions, appearing below.
 */
/*
 * function out=MyFunc(In1,In2)
 */
#line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
static mxArray * MMyFunc(int nargout_, mxArray * In1, mxArray * In2) {
    #line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclMlineEnterFunction("E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m", "MyFunc")
    #line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mexLocalFunctionTable save_local_function_table_ = mclSetCurrentLocalFunctionTable(&_local_function_table_MyFunc);
    #line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mxArray * out = mclGetUninitializedArray();
    #line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclCopyArray(&In1);
    #line 1 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclCopyArray(&In2);
    /*
     * %Returns the convolution of vector IN1 and IN2
     * 
     * out=conv(In1,In2);
     */
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclMline(3);
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mlfAssign(&out, mlfConv(mclVa(In1, "In1"), mclVa(In2, "In2")));
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclValidateOutput(out, 1, nargout_, "out", "MyFunc");
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mxDestroyArray(In2);
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mxDestroyArray(In1);
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclMlineFunctionReturn()
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    return out;
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
    mclMlineExitFunctionReturn();
    #line 4 "E:\\trabajos\\daniel\\practicasC++\\conv\\MyFunc.m"
}
