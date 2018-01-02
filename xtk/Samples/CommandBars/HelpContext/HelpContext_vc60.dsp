# Microsoft Developer Studio Project File - Name="HelpContext" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HelpContext - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HelpContext.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HelpContext.mak" CFG="HelpContext - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HelpContext - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HelpContext - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "HelpContext - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "HelpContext - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HelpContext - Win32 Release"

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
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Debug"

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
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "HelpContext___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "HelpContext___Win32_Unicode_Release"
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
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "HelpContext___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "HelpContext___Win32_Unicode_Debug"
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
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /pdbtype:sept /libpath:"../../../lib/vc60"
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/HelpContext.exe" /pdbtype:sept /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "HelpContext - Win32 Release"
# Name "HelpContext - Win32 Debug"
# Name "HelpContext - Win32 Unicode Release"
# Name "HelpContext - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpContext.cpp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\HelpContext.hpj

!IF  "$(CFG)" == "HelpContext - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__HELPC="WinHelp\AfxCore.rtf"	"WinHelp\AfxPrint.rtf"	"WinHelp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
TargetName=HelpContext
InputPath=.\WinHelp\HelpContext.hpj
InputName=HelpContext

"../../../bin/vc60/$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /c /E /M "WinHelp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "WinHelp\$(InputName).hlp" goto :Error 
	copy "WinHelp\$(InputName).hlp" "../../../bin/vc60/$(InputName).hlp" 
	goto :done 
	:Error 
	echo WinHelp\$(InputName).hpj(1) : error: 
	type "WinHelp\$(InputName).log" 
	:done 
	exit 0 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__HELPC="WinHelp\AfxCore.rtf"	"WinHelp\AfxPrint.rtf"	"WinHelp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
TargetName=HelpContext
InputPath=.\WinHelp\HelpContext.hpj
InputName=HelpContext

"../../../bin/vc60/$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /c /E /M "WinHelp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "WinHelp\$(InputName).hlp" goto :Error 
	copy "WinHelp\$(InputName).hlp" "../../../bin/vc60/$(InputName).hlp" 
	goto :done 
	:Error 
	echo WinHelp\$(InputName).hpj(1) : error: 
	type "WinHelp\$(InputName).log" 
	:done 
	exit 0 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
USERDEP__HELPC="WinHelp\AfxCore.rtf"	"WinHelp\AfxPrint.rtf"	"WinHelp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
TargetName=HelpContext
InputPath=.\WinHelp\HelpContext.hpj
InputName=HelpContext

"../../../bin/vc60/$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /c /E /M "WinHelp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "WinHelp\$(InputName).hlp" goto :Error 
	copy "WinHelp\$(InputName).hlp" "../../../bin/vc60/$(InputName).hlp" 
	goto :done 
	:Error 
	echo WinHelp\$(InputName).hpj(1) : error: 
	type "WinHelp\$(InputName).log" 
	:done 
	exit 0 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
USERDEP__HELPC="WinHelp\AfxCore.rtf"	"WinHelp\AfxPrint.rtf"	"WinHelp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
TargetName=HelpContext
InputPath=.\WinHelp\HelpContext.hpj
InputName=HelpContext

"../../../bin/vc60/$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /c /E /M "WinHelp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "WinHelp\$(InputName).hlp" goto :Error 
	copy "WinHelp\$(InputName).hlp" "../../../bin/vc60/$(InputName).hlp" 
	goto :done 
	:Error 
	echo WinHelp\$(InputName).hpj(1) : error: 
	type "WinHelp\$(InputName).log" 
	:done 
	exit 0 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\HelpContext.rc
# End Source File
# Begin Source File

SOURCE=.\HelpContextDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpContextView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
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

SOURCE=.\HelpContext.h
# End Source File
# Begin Source File

SOURCE=.\HelpContextDoc.h
# End Source File
# Begin Source File

SOURCE=.\HelpContextView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "HelpContext - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=HelpContext
InputPath=.\Resource.h

"WinHelp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"WinHelp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"WinHelp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"WinHelp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=HelpContext
InputPath=.\Resource.h

"WinHelp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"WinHelp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"WinHelp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"WinHelp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=HelpContext
InputPath=.\Resource.h

"WinHelp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"WinHelp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"WinHelp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"WinHelp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=HelpContext
InputPath=.\Resource.h

"WinHelp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"WinHelp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"WinHelp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"WinHelp\$(TargetName).hm" 
	echo. >>"WinHelp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"WinHelp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"WinHelp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\CjSample.ico
# End Source File
# Begin Source File

SOURCE=.\res\HelpContext.ico
# End Source File
# Begin Source File

SOURCE=.\res\HelpContext.rc2
# End Source File
# Begin Source File

SOURCE=.\res\HelpContextDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\WinHelp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\WinHelp\AfxPrint.rtf
# End Source File
# Begin Source File

SOURCE=.\WinHelp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\HelpContext.cnt

!IF  "$(CFG)" == "HelpContext - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
InputPath=.\WinHelp\HelpContext.cnt
InputName=HelpContext

"../../../bin/vc60/$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "WinHelp\$(InputName).cnt" "../../../bin/vc60/$(InputName).cnt"

# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
InputPath=.\WinHelp\HelpContext.cnt
InputName=HelpContext

"../../../bin/vc60/$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "WinHelp\$(InputName).cnt" "../../../bin/vc60/$(InputName).cnt"

# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
InputPath=.\WinHelp\HelpContext.cnt
InputName=HelpContext

"../../../bin/vc60/$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "WinHelp\$(InputName).cnt" "../../../bin/vc60/$(InputName).cnt"

# End Custom Build

!ELSEIF  "$(CFG)" == "HelpContext - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
InputPath=.\WinHelp\HelpContext.cnt
InputName=HelpContext

"../../../bin/vc60/$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "WinHelp\$(InputName).cnt" "../../../bin/vc60/$(InputName).cnt"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\WinHelp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\WinHelp\Scmin.bmp
# End Source File
# End Group
# End Target
# End Project
