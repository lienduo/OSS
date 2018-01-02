# Microsoft Developer Studio Project File - Name="TabbedToolbar" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TabbedToolbar - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TabbedToolbar.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TabbedToolbar.mak" CFG="TabbedToolbar - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TabbedToolbar - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TabbedToolbar - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "TabbedToolbar - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "TabbedToolbar - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TabbedToolbar - Win32 Release"

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
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/TabbedToolbar.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "TabbedToolbar - Win32 Debug"

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
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/TabbedToolbarD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "TabbedToolbar - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TabbedToolbar___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "TabbedToolbar___Win32_Unicode_Release"
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
# ADD BASE RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/TabbedToolbar.exe" /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/TabbedToolbarU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "TabbedToolbar - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "TabbedToolbar___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "TabbedToolbar___Win32_Unicode_Debug"
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
# ADD BASE RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/TabbedToolbarD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/TabbedToolbarUD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "TabbedToolbar - Win32 Release"
# Name "TabbedToolbar - Win32 Debug"
# Name "TabbedToolbar - Win32 Unicode Release"
# Name "TabbedToolbar - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbar.cpp
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbar.rc
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbarDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbarView.cpp
# End Source File
# Begin Source File

SOURCE=.\TabClientPage.cpp
# End Source File
# Begin Source File

SOURCE=.\ThemePage.cpp
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

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbar.h
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbarDoc.h
# End Source File
# Begin Source File

SOURCE=.\TabbedToolbarView.h
# End Source File
# Begin Source File

SOURCE=.\TabClientPage.h
# End Source File
# Begin Source File

SOURCE=.\ThemePage.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\11056.ico
# End Source File
# Begin Source File

SOURCE=.\res\20513.ico
# End Source File
# Begin Source File

SOURCE=.\res\7511.ico
# End Source File
# Begin Source File

SOURCE=.\res\7513.ico
# End Source File
# Begin Source File

SOURCE=.\res\7518.ico
# End Source File
# Begin Source File

SOURCE=.\res\7519.ico
# End Source File
# Begin Source File

SOURCE=.\res\7610.ico
# End Source File
# Begin Source File

SOURCE=.\res\7611.ico
# End Source File
# Begin Source File

SOURCE=.\res\7612.ico
# End Source File
# Begin Source File

SOURCE=.\res\7721.ico
# End Source File
# Begin Source File

SOURCE=.\res\8044.ico
# End Source File
# Begin Source File

SOURCE=.\res\8536.ico
# End Source File
# Begin Source File

SOURCE=.\res\9403.ico
# End Source File
# Begin Source File

SOURCE=.\res\9409.ico
# End Source File
# Begin Source File

SOURCE=.\res\9410.ico
# End Source File
# Begin Source File

SOURCE=.\res\9502.ico
# End Source File
# Begin Source File

SOURCE=.\res\9504.ico
# End Source File
# Begin Source File

SOURCE=.\res\9505.ico
# End Source File
# Begin Source File

SOURCE=.\res\9600.ico
# End Source File
# Begin Source File

SOURCE=.\res\9606.ico
# End Source File
# Begin Source File

SOURCE=.\res\9607.ico
# End Source File
# Begin Source File

SOURCE=.\res\9608.ico
# End Source File
# Begin Source File

SOURCE=.\res\9609.ico
# End Source File
# Begin Source File

SOURCE=.\res\9611.ico
# End Source File
# Begin Source File

SOURCE=.\res\9617.ico
# End Source File
# Begin Source File

SOURCE=.\res\9618.ico
# End Source File
# Begin Source File

SOURCE=.\res\9619.ico
# End Source File
# Begin Source File

SOURCE=.\res\9621.ico
# End Source File
# Begin Source File

SOURCE=.\res\9673.ico
# End Source File
# Begin Source File

SOURCE=.\res\9683.ico
# End Source File
# Begin Source File

SOURCE=.\res\9703.ico
# End Source File
# Begin Source File

SOURCE=.\res\9704.ico
# End Source File
# Begin Source File

SOURCE=.\res\9710.ico
# End Source File
# Begin Source File

SOURCE=.\res\9717.ico
# End Source File
# Begin Source File

SOURCE=.\res\9718.ico
# End Source File
# Begin Source File

SOURCE=.\res\9720.ico
# End Source File
# Begin Source File

SOURCE=.\res\9746.ico
# End Source File
# Begin Source File

SOURCE=.\res\9800.ico
# End Source File
# Begin Source File

SOURCE=.\res\9801.ico
# End Source File
# Begin Source File

SOURCE=.\res\9802.ico
# End Source File
# Begin Source File

SOURCE=.\res\9803.ico
# End Source File
# Begin Source File

SOURCE=.\res\9805.ico
# End Source File
# Begin Source File

SOURCE=.\res\9806.ico
# End Source File
# Begin Source File

SOURCE=.\res\9807.ico
# End Source File
# Begin Source File

SOURCE=.\res\9809.ico
# End Source File
# Begin Source File

SOURCE=.\res\TabbedToolbar.ico
# End Source File
# Begin Source File

SOURCE=.\res\TabbedToolbar.rc2
# End Source File
# Begin Source File

SOURCE=.\res\TabbedToolbarDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolbarUser.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
