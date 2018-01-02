# Microsoft Developer Studio Project File - Name="SmartLayout" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SmartLayout - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SmartLayout.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SmartLayout.mak" CFG="SmartLayout - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SmartLayout - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SmartLayout - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "SmartLayout - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "SmartLayout - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SmartLayout - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release/vc60"
# PROP BASE Intermediate_Dir "Release/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
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
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/SmartLayout.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "SmartLayout - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug/vc60"
# PROP BASE Intermediate_Dir "Debug/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
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
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/SmartLayoutD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "SmartLayout - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "SmartLayout___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "SmartLayout___Win32_Unicode_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
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
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/SmartLayout.exe"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/SmartLayoutU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "SmartLayout - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "SmartLayout___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "SmartLayout___Win32_Unicode_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/SmartLayoutD.exe" /pdbtype:sept
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/SmartLayoutUD.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "SmartLayout - Win32 Release"
# Name "SmartLayout - Win32 Debug"
# Name "SmartLayout - Win32 Unicode Release"
# Name "SmartLayout - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\CntrItem.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlSelector.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\SmartLayout.cpp
# End Source File
# Begin Source File

SOURCE=.\SmartLayout.rc
# End Source File
# Begin Source File

SOURCE=.\SmartLayoutDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\SmartLayoutView.cpp
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

SOURCE=.\CntrItem.h
# End Source File
# Begin Source File

SOURCE=.\ControlSelector.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SmartLayout.h
# End Source File
# Begin Source File

SOURCE=.\SmartLayoutDoc.h
# End Source File
# Begin Source File

SOURCE=.\SmartLayoutView.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\borders.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Edit_Undo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FormatBar_Alpha.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FormatbarLarge.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LargeIcons_Alpha.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Main_Alpha.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SmartLayout.rc2
# End Source File
# Begin Source File

SOURCE=.\res\SmartLayoutDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# End Target
# End Project
