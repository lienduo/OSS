all : bin_target

MyFunc.c : E:\trabajos\daniel\practicasC++\conv\MyFunc.m
	c:\matlabr12\bin\win32\mcc -L C libmmfile.mlib -A line:on -G -A debugline:on -O fold_scalar_mxarrays:off -O fold_non_scalar_mxarrays:off -O optimize_integer_for_loops:off -O array_indexing:off -O optimize_conditionals:off libmmfile.mlib -v -I E:\trabajos\daniel\practicasC++\conv -t -T codegen E:\trabajos\daniel\practicasC++\conv\MyFunc.m

MyFunc_main.c : E:\trabajos\daniel\practicasC++\conv\MyFunc.m
	c:\matlabr12\bin\win32\mcc  -L C libmmfile.mlib -A line:on -G -A debugline:on -O fold_scalar_mxarrays:off -O fold_non_scalar_mxarrays:off -O optimize_integer_for_loops:off -O array_indexing:off -O optimize_conditionals:off libmmfile.mlib -v -I E:\trabajos\daniel\practicasC++\conv -W main  E:\trabajos\daniel\practicasC++\conv\MyFunc.m

bin_target : MyFunc.exe

MyFunc.obj : MyFunc.c
	cl  -c -Zp8 -G5 -W3 -nologo /FoMyFunc.obj -IC:\matlabR12\extern\include -IC:\matlabR12\simulink\include -Zi -Fd"MyFunc.pdb" MyFunc.c

MyFunc_main.obj : MyFunc_main.c
	cl  -c -Zp8 -G5 -W3 -nologo /FoMyFunc_main.obj -IC:\matlabR12\extern\include -IC:\matlabR12\simulink\include -Zi -Fd"MyFunc.pdb" MyFunc_main.c

MyFunc.exe : MyFunc.obj MyFunc_main.obj
	link "/out:MyFunc.exe" /debug kernel32.lib user32.lib gdi32.lib /LIBPATH:"C:\matlabR12\extern\lib\win32\microsoft\msvc60" libmmfile.lib libmatlb.lib /nologo libmx.lib libmat.lib sgl.lib libmwsglm.lib  @MyFunc_master.rsp 
	if exist _lib414.def del _lib414.def
	if exist "mexversion.res" del "mexversion.res"

