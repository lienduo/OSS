# Microsoft Developer Studio Generated NMAKE File, Based on mex_tsctimer.dsp
!IF "$(CFG)" == ""
CFG=mex_tsctimer - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mex_tsctimer - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mex_tsctimer - Win32 Release" && "$(CFG)" != "mex_tsctimer - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mex_tsctimer.mak" CFG="mex_tsctimer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mex_tsctimer - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mex_tsctimer - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mex_tsctimer - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mex_tsctimer.dll"


CLEAN :
	-@erase "$(INTDIR)\mex_tsctimer.obj"
	-@erase "$(INTDIR)\TSCtime.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mex_tsctimer.dll"
	-@erase "$(OUTDIR)\mex_tsctimer.exp"
	-@erase "$(OUTDIR)\mex_tsctimer.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MEX_TSCTIMER_EXPORTS" /Fp"$(INTDIR)\mex_tsctimer.pch" /YX"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mex_tsctimer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\mex_tsctimer.pdb" /machine:I386 /def:".\mex_tsctimer.def" /out:"$(OUTDIR)\mex_tsctimer.dll" /implib:"$(OUTDIR)\mex_tsctimer.lib" 
DEF_FILE= \
	".\mex_tsctimer.def"
LINK32_OBJS= \
	"$(INTDIR)\mex_tsctimer.obj" \
	"$(INTDIR)\TSCtime.obj"

"$(OUTDIR)\mex_tsctimer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mex_tsctimer - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mex_tsctimer.dll"


CLEAN :
	-@erase "$(INTDIR)\mex_tsctimer.obj"
	-@erase "$(INTDIR)\TSCtime.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mex_tsctimer.dll"
	-@erase "$(OUTDIR)\mex_tsctimer.exp"
	-@erase "$(OUTDIR)\mex_tsctimer.ilk"
	-@erase "$(OUTDIR)\mex_tsctimer.lib"
	-@erase "$(OUTDIR)\mex_tsctimer.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MEX_TSCTIMER_EXPORTS" /D "MATLAB_MEX_FILE" /Fp"$(INTDIR)\mex_tsctimer.pch" /YX"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mex_tsctimer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\mex_tsctimer.pdb" /debug /machine:I386 /def:".\mex_tsctimer.def" /out:"$(OUTDIR)\mex_tsctimer.dll" /implib:"$(OUTDIR)\mex_tsctimer.lib" /pdbtype:sept 
DEF_FILE= \
	".\mex_tsctimer.def"
LINK32_OBJS= \
	"$(INTDIR)\mex_tsctimer.obj" \
	"$(INTDIR)\TSCtime.obj"

"$(OUTDIR)\mex_tsctimer.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mex_tsctimer.dep")
!INCLUDE "mex_tsctimer.dep"
!ELSE 
!MESSAGE Warning: cannot find "mex_tsctimer.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mex_tsctimer - Win32 Release" || "$(CFG)" == "mex_tsctimer - Win32 Debug"
SOURCE=.\mex_tsctimer.cpp

"$(INTDIR)\mex_tsctimer.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\TSCtime.cpp

"$(INTDIR)\TSCtime.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

