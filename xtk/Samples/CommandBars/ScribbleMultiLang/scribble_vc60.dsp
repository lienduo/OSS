# Microsoft Developer Studio Project File - Name="Scribble" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Scribble - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "scribble.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "scribble.mak" CFG="Scribble - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Scribble - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Scribble - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Scribble - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "Scribble - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Scribble - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release/vc60"
# PROP BASE Intermediate_Dir ".\Release/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release/vc60"
# PROP Intermediate_Dir ".\Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c /Zm200
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../../../bin/vc60/Scribble.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug/vc60"
# PROP BASE Intermediate_Dir ".\Debug/vc60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug/vc60"
# PROP Intermediate_Dir ".\Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/ScribbleD.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Scribble___Win32_Release_Unicode"
# PROP BASE Intermediate_Dir "Scribble___Win32_Release_Unicode"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release/vc60"
# PROP Intermediate_Dir "Unicode_Release/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "." /i "TargetRC" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "NDEBUG" /d "_AFXDLL" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /out:"../../../bin/vc60/ScribbleU.exe" /libpath:"../../../lib/vc60"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Scribble___Win32_Debug_Unicode"
# PROP BASE Intermediate_Dir "Scribble___Win32_Debug_Unicode"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug/vc60"
# PROP Intermediate_Dir "Unicode_Debug/vc60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm200
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../Source" /I "../../AboutDlg" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /Yu"stdafx.h" /FD /c /Zm200
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "." /i "TargetRC" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "../../../Source" /i "../../AboutDlg" /d "_DEBUG" /d "_AFXDLL" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"../../../bin/vc60/ScribbleUD.exe" /libpath:"../../../lib/vc60"

!ENDIF 

# Begin Target

# Name "Scribble - Win32 Release"
# Name "Scribble - Win32 Debug"
# Name "Scribble - Win32 Unicode Release"
# Name "Scribble - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\childfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\mainfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\pendlg.cpp
# End Source File
# Begin Source File

SOURCE=.\scribble.cpp
# End Source File
# Begin Source File

SOURCE=.\scribble.rc
# End Source File
# Begin Source File

SOURCE=.\scribdoc.cpp
# End Source File
# Begin Source File

SOURCE=.\scribitm.cpp
# End Source File
# Begin Source File

SOURCE=.\scribvw.cpp
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;inl;fi;fd"
# Begin Source File

SOURCE=.\childfrm.h
# End Source File
# Begin Source File

SOURCE=.\mainfrm.h
# End Source File
# Begin Source File

SOURCE=.\pendlg.h
# End Source File
# Begin Source File

SOURCE=.\scribble.h
# End Source File
# Begin Source File

SOURCE=.\scribdoc.h
# End Source File
# Begin Source File

SOURCE=.\scribitm.h
# End Source File
# Begin Source File

SOURCE=.\scribvw.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\cj_logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scribble.ico
# End Source File
# Begin Source File

SOURCE=.\res\scribble.rc2
# End Source File
# Begin Source File

SOURCE=.\res\scribdoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.png
# End Source File
# Begin Source File

SOURCE=.\RES\Usa.bmp
# End Source File
# End Group
# Begin Group "Translations"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceArSa.dll

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.dll
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.dll
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.dll
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.dll
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceArSa.xml

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.xml
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.xml
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.xml
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceArSa.xml
InputName=Scribble.ResourceArSa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceDe.dll

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.dll
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.dll
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.dll
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.dll
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceDe.xml

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.xml
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.xml
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.xml
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceDe.xml
InputName=Scribble.ResourceDe

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceJa.dll

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.dll
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.dll
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.dll
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.dll
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceJa.xml

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.xml
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.xml
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.xml
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceJa.xml
InputName=Scribble.ResourceJa

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceRu.dll

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.dll
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.dll
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.dll
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.dll
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Translations\Scribble.ResourceRu.xml

!IF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.xml
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.xml
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Release"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.xml
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Unicode Debug"

# Begin Custom Build
TargetDir=\Source\ToolkitRoot\ToolkitPro\bin
InputPath=.\Translations\Scribble.ResourceRu.xml
InputName=Scribble.ResourceRu

"$(TargetDir)\Translations\$(InputName).xml" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(InputPath)" "$(TargetDir)\Translations"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
