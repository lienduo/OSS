# Microsoft Developer Studio Project File - Name="MDITextEditor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MDITextEditor - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MDITextEditor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDITextEditor.mak" CFG="MDITextEditor - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDITextEditor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MDITextEditor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MDITextEditor - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "MDITextEditor - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release/vc60"
# PROP BASE Intermediate_Dir "Release/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release/vc60"
# PROP Intermediate_Dir "Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/MDITextEditor.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug/vc60"
# PROP BASE Intermediate_Dir "Debug/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug/vc60"
# PROP Intermediate_Dir "Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/MDITextEditorD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "MDITextEditor___Win32_Dynamic_Unicode_Release"
# PROP BASE Intermediate_Dir "MDITextEditor___Win32_Dynamic_Unicode_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release/vc60"
# PROP Intermediate_Dir "Unicode_Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/MDITextEditorU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "MDITextEditor___Win32_Dynamic_Unicode_Debug"
# PROP BASE Intermediate_Dir "MDITextEditor___Win32_Dynamic_Unicode_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/MDITextEditorUD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "MDITextEditor - Win32 Release"
# Name "MDITextEditor - Win32 Debug"
# Name "MDITextEditor - Win32 Unicode Release"
# Name "MDITextEditor - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MDITextEditor.cpp
# End Source File
# Begin Source File

SOURCE=.\MDITextEditor.rc
# End Source File
# Begin Source File

SOURCE=.\MDITextEditorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MDITextEditorView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MDITextEditor.h
# End Source File
# Begin Source File

SOURCE=.\MDITextEditorDoc.h
# End Source File
# Begin Source File

SOURCE=.\MDITextEditorView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\MDITextEditor.ico
# End Source File
# Begin Source File

SOURCE=.\res\MDITextEditor.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MDITextEditorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "EditConfig"

# PROP Default_Filter ""
# Begin Group "Schemas"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\Schemas\_cpp.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_HTML_ASP.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_ini.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_LUA.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_LUA.schclass

"$(TargetDir)\EditConfig\Schemas\_LUA.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_LUA.schclass

"$(TargetDir)\EditConfig\Schemas\_LUA.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_LUA.schclass

"$(TargetDir)\EditConfig\Schemas\_LUA.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_LUA.schclass

"$(TargetDir)\EditConfig\Schemas\_LUA.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_nsi.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_pascal.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_schclass.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_sql.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_VBScript.schclass

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_VBScript.schclass

"$(TargetDir)\EditConfig\Schemas\_VBScript.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_VBScript.schclass

"$(TargetDir)\EditConfig\Schemas\_VBScript.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_VBScript.schclass

"$(TargetDir)\EditConfig\Schemas\_VBScript.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_VBScript.schclass

"$(TargetDir)\EditConfig\Schemas\_VBScript.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Themes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\Themes\colorSchema0.ini

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Themes\colorSchema1.ini

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\Config\SyntaxEdit.ini

!IF  "$(CFG)" == "MDITextEditor - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "MDITextEditor - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
