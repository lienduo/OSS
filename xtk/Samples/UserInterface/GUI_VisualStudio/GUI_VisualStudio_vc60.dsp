# Microsoft Developer Studio Project File - Name="GUI_VisualStudio" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GUI_VisualStudio - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GUI_VisualStudio.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GUI_VisualStudio.mak" CFG="GUI_VisualStudio - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GUI_VisualStudio - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GUI_VisualStudio - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "GUI_VisualStudio - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "GUI_VisualStudio - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

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
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudio.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

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
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudioD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "GUI_VisualStudio___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "GUI_VisualStudio___Win32_Unicode_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release/vc60"
# PROP Intermediate_Dir "Unicode_Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudio.exe" /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudioU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "GUI_VisualStudio___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "GUI_VisualStudio___Win32_Unicode_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudioD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/GUI_VisualStudioUD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "GUI_VisualStudio - Win32 Release"
# Name "GUI_VisualStudio - Win32 Debug"
# Name "GUI_VisualStudio - Win32 Unicode Release"
# Name "GUI_VisualStudio - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassViewPane.cpp
# End Source File
# Begin Source File

SOURCE=.\DynamicHelpView.cpp
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudio.cpp
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudio.rc
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudioDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudioView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputPane.cpp
# End Source File
# Begin Source File

SOURCE=.\PropertiesPane.cpp
# End Source File
# Begin Source File

SOURCE=.\ResourceViewPane.cpp
# End Source File
# Begin Source File

SOURCE=.\SolutionExplorerPane.cpp
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

SOURCE=.\ClassViewPane.h
# End Source File
# Begin Source File

SOURCE=.\DynamicHelpView.h
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudio.h
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudioDoc.h
# End Source File
# Begin Source File

SOURCE=.\GUI_VisualStudioView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OutputPane.h
# End Source File
# Begin Source File

SOURCE=.\PropertiesPane.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ResourceViewPane.h
# End Source File
# Begin Source File

SOURCE=.\SolutionExplorerPane.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\clear.gif
# End Source File
# Begin Source File

SOURCE=.\res\ctxhelp_hide.gif
# End Source File
# Begin Source File

SOURCE=.\res\ctxhelp_show.gif
# End Source File
# Begin Source File

SOURCE=.\res\ctxsample_hide.gif
# End Source File
# Begin Source File

SOURCE=.\res\ctxsample_show.gif
# End Source File
# Begin Source File

SOURCE=.\res\dynamic_help.htm
# End Source File
# Begin Source File

SOURCE=.\res\FullScreen.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GUI_VisualStudio.ico
# End Source File
# Begin Source File

SOURCE=.\res\GUI_VisualStudio.rc2
# End Source File
# Begin Source File

SOURCE=.\res\GUI_VisualStudioDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\img_classtree.bmp
# End Source File
# Begin Source File

SOURCE=.\res\img_filetree.bmp
# End Source File
# Begin Source File

SOURCE=.\res\img_restree.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MenuBar.png
# End Source File
# Begin Source File

SOURCE=.\res\PaneProperties.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SolutionExplorerPane.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ThemeBar.png
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.png
# End Source File
# Begin Source File

SOURCE=.\res\Toolbox.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Web.png
# End Source File
# End Group
# Begin Group "EditConfig"

# PROP Default_Filter ""
# Begin Group "Schemas"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\Schemas\_cpp.schclass

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_cpp.schclass

"$(TargetDir)\EditConfig\Schemas\_cpp.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_HTML_ASP.schclass

"$(TargetDir)\EditConfig\Schemas\_HTML_ASP.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_ini.schclass

"$(TargetDir)\EditConfig\Schemas\_ini.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Schemas\_nsi.schclass

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_nsi.schclass

"$(TargetDir)\EditConfig\Schemas\_nsi.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_pascal.schclass

"$(TargetDir)\EditConfig\Schemas\_pascal.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_schclass.schclass

"$(TargetDir)\EditConfig\Schemas\_schclass.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Schemas\_sql.schclass

"$(TargetDir)\EditConfig\Schemas\_sql.schclass" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Schemas"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Themes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\Themes\colorSchema0.ini

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema0.ini

"$(TargetDir)\EditConfig\Themes\colorSchema0.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\Themes\colorSchema1.ini

"$(TargetDir)\EditConfig\Themes\colorSchema1.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig\Themes"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

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

!IF  "$(CFG)" == "GUI_VisualStudio - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ELSEIF  "$(CFG)" == "GUI_VisualStudio - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\Bin
InputPath=.\Config\SyntaxEdit.ini

"$(TargetDir)\EditConfig\SyntaxEdit.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\EditConfig"

# End Custom Build

!ENDIF 

# End Source File
# End Group

# End Target
# End Project
