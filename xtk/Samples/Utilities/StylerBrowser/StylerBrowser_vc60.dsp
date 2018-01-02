# Microsoft Developer Studio Project File - Name="StylerBrowser" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=StylerBrowser - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "StylerBrowser.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "StylerBrowser.mak" CFG="StylerBrowser - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "StylerBrowser - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "StylerBrowser - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "StylerBrowser - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "StylerBrowser - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

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
# ADD CPP /nologo /MD /W4 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c /Zm200
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/StylerBrowser.exe" /libpath:"..\..\lib" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /Zm200 /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/StylerBrowserD.exe" /pdbtype:sept /libpath:"..\..\Lib" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "StylerBrowser___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "StylerBrowser___Win32_Unicode_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\Source" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /Zm200 /c /Zm200
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "..\..\..\Source" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/StylerBrowser.exe" /pdbtype:sept /libpath:"..\..\Lib" /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/StylerBrowserUD.exe" /pdbtype:sept /libpath:"..\..\Lib" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "StylerBrowser___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "StylerBrowser___Win32_Unicode_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release/vc60"
# PROP Intermediate_Dir "Unicode_Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\Source" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fr /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MD /W4 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /FD /c /Zm200
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /i "..\..\..\Source" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"Bin/StylerBrowser.exe" /libpath:"..\..\lib" /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/StylerBrowserU.exe" /libpath:"..\..\lib" /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "StylerBrowser - Win32 Release"
# Name "StylerBrowser - Win32 Debug"
# Name "StylerBrowser - Win32 Unicode Debug"
# Name "StylerBrowser - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ComboBoxSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlFavorites.cpp
# End Source File
# Begin Source File

SOURCE=.\CustSite.CPP
# End Source File
# Begin Source File

SOURCE=.\CWebBrowser2.cpp
# End Source File
# Begin Source File

SOURCE=.\ExplorerBar.cpp
# End Source File
# Begin Source File

SOURCE=.\FilterContent.cpp
# End Source File
# Begin Source File

SOURCE=.\FilterDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryTree.cpp
# End Source File
# Begin Source File

SOURCE=.\HisTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\IndicatorStatusBar.cpp
# End Source File
# Begin Source File

SOURCE=.\InetTools.cpp
# End Source File
# Begin Source File

SOURCE=.\LinkProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MouseManager.cpp
# End Source File
# Begin Source File

SOURCE=.\NotepadCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsList.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsPage.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.cpp
# End Source File
# Begin Source File

SOURCE=.\PageKeyboard.cpp
# End Source File
# Begin Source File

SOURCE=.\PageMouse.cpp
# End Source File
# Begin Source File

SOURCE=.\pagesearch.cpp
# End Source File
# Begin Source File

SOURCE=.\PopupFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\SourceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Styler.cpp
# End Source File
# Begin Source File

SOURCE=.\Styler.rc
# End Source File
# Begin Source File

SOURCE=.\StylerDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\StylerView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\ComboBoxSearch.h
# End Source File
# Begin Source File

SOURCE=.\ControlFavorites.h
# End Source File
# Begin Source File

SOURCE=.\CWebBrowser2.h
# End Source File
# Begin Source File

SOURCE=.\ExplorerBar.h
# End Source File
# Begin Source File

SOURCE=.\FilterContent.h
# End Source File
# Begin Source File

SOURCE=.\FilterDialog.h
# End Source File
# Begin Source File

SOURCE=.\HistoryTree.h
# End Source File
# Begin Source File

SOURCE=.\HisTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\IndicatorStatusBar.h
# End Source File
# Begin Source File

SOURCE=.\InetTools.h
# End Source File
# Begin Source File

SOURCE=.\LinkProperties.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MouseManager.h
# End Source File
# Begin Source File

SOURCE=.\NotepadCtrl.h
# End Source File
# Begin Source File

SOURCE=.\OptionsDialog.h
# End Source File
# Begin Source File

SOURCE=.\OptionsList.h
# End Source File
# Begin Source File

SOURCE=.\OptionsPage.h
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.h
# End Source File
# Begin Source File

SOURCE=.\PageKeyboard.h
# End Source File
# Begin Source File

SOURCE=.\pagemouse.h
# End Source File
# Begin Source File

SOURCE=.\pagesearch.h
# End Source File
# Begin Source File

SOURCE=.\PopupFilter.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SourceCtrl.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Styler.h
# End Source File
# Begin Source File

SOURCE=.\StylerDoc.h
# End Source File
# Begin Source File

SOURCE=.\StylerView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Styler.ico
# End Source File
# Begin Source File

SOURCE=.\res\Styler.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Tabs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolbarStandard_a.bmp
# End Source File
# End Group
# Begin Group "Config"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\Encoding.ini

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Encoding.ini

"$(TargetDir)\Config\Encoding.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Encoding.ini

"$(TargetDir)\Config\Encoding.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Encoding.ini

"$(TargetDir)\Config\Encoding.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Encoding.ini

"$(TargetDir)\Config\Encoding.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\QuickSearch.ini

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\QuickSearch.ini

"$(TargetDir)\Config\QuickSearch.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\QuickSearch.ini

"$(TargetDir)\Config\QuickSearch.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\QuickSearch.ini

"$(TargetDir)\Config\QuickSearch.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\QuickSearch.ini

"$(TargetDir)\Config\QuickSearch.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Search.htm

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Search.htm

"$(TargetDir)\Config\Search.htm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Search.htm

"$(TargetDir)\Config\Search.htm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Search.htm

"$(TargetDir)\Config\Search.htm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Search.htm

"$(TargetDir)\Config\Search.htm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\Tables.css

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Tables.css

"$(TargetDir)\Config\Tables.css" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Tables.css

"$(TargetDir)\Config\Tables.css" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Tables.css

"$(TargetDir)\Config\Tables.css" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\Tables.css

"$(TargetDir)\Config\Tables.css" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Config\urlfilter.ini

!IF  "$(CFG)" == "StylerBrowser - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\urlfilter.ini

"$(TargetDir)\Config\urlfilter.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\urlfilter.ini

"$(TargetDir)\Config\urlfilter.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\urlfilter.ini

"$(TargetDir)\Config\urlfilter.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ELSEIF  "$(CFG)" == "StylerBrowser - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Config\urlfilter.ini

"$(TargetDir)\Config\urlfilter.ini" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Config"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
