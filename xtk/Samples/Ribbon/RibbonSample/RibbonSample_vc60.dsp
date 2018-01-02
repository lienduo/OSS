# Microsoft Developer Studio Project File - Name="RibbonSample" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=RibbonSample - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RibbonSample.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RibbonSample.mak" CFG="RibbonSample - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RibbonSample - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "RibbonSample - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "RibbonSample - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "RibbonSample - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RibbonSample - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /Zm200 /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /Zm200 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/RibbonSample.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "RibbonSample - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /Zm200 /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/RibbonSampleD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "RibbonSample - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "RibbonSample___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "RibbonSample___Win32_Unicode_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release/vc60"
# PROP Intermediate_Dir "Unicode_Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /Zm200 /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /Zm200 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/RibbonSampleU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "RibbonSample - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "RibbonSample___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "RibbonSample___Win32_Unicode_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /Zm200 /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/RibbonSampleUD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "RibbonSample - Win32 Release"
# Name "RibbonSample - Win32 Debug"
# Name "RibbonSample - Win32 Unicode Release"
# Name "RibbonSample - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CntrItem.cpp
# End Source File
# Begin Source File

SOURCE=.\GalleryItems.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\RibbonSample.cpp
# End Source File
# Begin Source File

SOURCE=.\RibbonSample.rc
# End Source File
# Begin Source File

SOURCE=.\RibbonSampleDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\RibbonSampleView.cpp
# End Source File
# Begin Source File

SOURCE=.\ScrollRichEditView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\WorkspaceView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CntrItem.h
# End Source File
# Begin Source File

SOURCE=.\GalleryItems.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RibbonSample.h
# End Source File
# Begin Source File

SOURCE=.\RibbonSampleDoc.h
# End Source File
# Begin Source File

SOURCE=.\RibbonSampleView.h
# End Source File
# Begin Source File

SOURCE=.\ScrollRichEditView.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\WorkspaceView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\BitmapChart.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BitmapGraphic.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BitmapPicture.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BitmapTable.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CJSample.ico
# End Source File
# Begin Source File

SOURCE=.\res\GroupCaptions.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupClipboard.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupDocumentViews.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupFind.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupFont.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupFootnotes.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupIcons.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupIndex.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupOptionToolTip.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupPageParagraph.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupParagraph.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupPopup.ico
# End Source File
# Begin Source File

SOURCE=.\res\GroupStyles.png
# End Source File
# Begin Source File

SOURCE=.\res\GroupTableOfContents.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupWindow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GroupZoom.bmp
# End Source File
# Begin Source File

SOURCE=.\res\InsertTab.png
# End Source File
# Begin Source File

SOURCE=.\res\LargeIcons.png
# End Source File
# Begin Source File

SOURCE=.\res\LayoutTab.png
# End Source File
# Begin Source File

SOURCE=.\res\LayoutTabLarge.png
# End Source File
# Begin Source File

SOURCE=.\res\RibbonSample.rc2
# End Source File
# Begin Source File

SOURCE=.\res\RibbonSampleDoc.ico
# End Source File
# Begin Source File

SOURCE=".\res\shiny-gear.png"
# End Source File
# Begin Source File

SOURCE=.\res\SmallIcons.png
# End Source File
# Begin Source File

SOURCE=.\res\SystemMenuLarge.png
# End Source File
# Begin Source File

SOURCE=.\res\TabPageLayout.png
# End Source File
# Begin Source File

SOURCE=.\res\TabReferences.png
# End Source File
# Begin Source File

SOURCE=.\res\TabView.png
# End Source File
# End Group
# End Target
# End Project
