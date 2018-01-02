# Microsoft Developer Studio Project File - Name="Codejock.ToolkitPro.Static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ToolkitProStatic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ToolkitProStatic.mak" CFG="Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Static Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Static Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Static Unicode Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Static Unicode Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Dynamic Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Dynamic Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Static Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Static_Release/vc60"
# PROP Intermediate_Dir "Static_Release/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /W4 /GX /O2 /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "NDEBUG" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60S.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Static Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Static_Debug/vc60"
# PROP Intermediate_Dir "Static_Debug/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /W4 /GX /ZI /Od /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60SD.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Static Unicode Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Static_Unicode_Release/vc60"
# PROP Intermediate_Dir "Static_Unicode_Release/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /W4 /GX /O2 /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "NDEBUG" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60SU.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Static Unicode Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Static_Unicode_Debug/vc60"
# PROP Intermediate_Dir "Static_Unicode_Debug/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /W4 /GX /ZI /Od /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60SUD.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Dynamic Release"

# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Dynamic_Release/vc60"
# PROP Intermediate_Dir "Dynamic_Release/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W4 /GX /O2 /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "NDEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60DS.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Dynamic Debug"

# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dynamic_Debug/vc60"
# PROP Intermediate_Dir "Dynamic_Debug/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W4 /GX /ZI /Od /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60DSD.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Release"

# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Dynamic_Unicode_Release/vc60"
# PROP Intermediate_Dir "Dynamic_Unicode_Release/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W4 /GX /O2 /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "NDEBUG" /D "_UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60DSU.lib"

!ELSEIF  "$(CFG)" == "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Debug"

# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dynamic_Unicode_Debug/vc60"
# PROP Intermediate_Dir "Dynamic_Unicode_Debug/vc60"
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W4 /GX /ZI /Od /I "../../Source" /I "../../Source/Common" /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x419
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:"../../lib/vc60/ToolkitPro1121vc60DSUD.lib"

!ENDIF 

# Begin Target

# Name "Codejock.ToolkitPro.Static - Win32 Static Release"
# Name "Codejock.ToolkitPro.Static - Win32 Static Debug"
# Name "Codejock.ToolkitPro.Static - Win32 Static Unicode Release"
# Name "Codejock.ToolkitPro.Static - Win32 Static Unicode Debug"
# Name "Codejock.ToolkitPro.Static - Win32 Dynamic Release"
# Name "Codejock.ToolkitPro.Static - Win32 Dynamic Debug"
# Name "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Release"
# Name "Codejock.ToolkitPro.Static - Win32 Dynamic Unicode Debug"
# Begin Group "Source"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\Common\XTMaskEditT.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPColorManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPColorManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPCustomHeap.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPDrawHelpers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPDrawHelpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPImageManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPImageManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPIntel80Helpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPMacros.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPNotifyConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPNotifyConnection.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPOffice2007Image.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPOffice2007Image.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPPropExchange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPPropExchange.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPPropExchange.inc
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPResourceManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPResourceManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPRichRender.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPRichRender.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPSmartPtrInternalT.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPSystemHelpers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPSystemHelpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPToolTipContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPToolTipContext.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPVC50Helpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPVC80Helpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPWinThemeWrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Common\XTPWinThemeWrapper.h
# End Source File
# End Group
# Begin Group "CommandBars"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBarAnimation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBarAnimation.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBars.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBars.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBars.inl
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCommandBarsDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlButton.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlComboBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlComboBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlComboBoxExt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlComboBoxExt.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlCustom.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlCustom.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlExt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlExt.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlGallery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlGallery.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlPopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlPopup.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlPopupColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlPopupColor.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControls.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControls.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlScrollBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlScrollBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlSlider.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPControlSlider.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeCommandsPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeCommandsPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeKeyboardPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeKeyboardPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeMenusPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeMenusPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeOptionsPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeOptionsPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeToolbarsPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeToolbarsPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPCustomizeTools.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDefaultTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDialogBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDialogBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDialogBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockContext.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPDockState.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPFrameWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPFrameWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPHookManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPHookManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPImageEditor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPImageEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPMenuBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPMenuBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPMouseManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPMouseManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPNativeXPTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOffice2003Theme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOffice2007FrameHook.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOffice2007FrameHook.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOffice2007Theme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOffice2007Theme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPOfficeTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPPopupBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPPopupBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPReBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPReBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPScrollBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPScrollBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPShadowsManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPShadowsManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPShortcutManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPShortcutManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPSoundManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPSoundManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPStatusBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPStatusBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPTabClientWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPTabClientWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPTabToolBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPTabToolBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPToolBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\CommandBars\XTPToolBar.h
# End Source File
# End Group
# Begin Group "TabManager"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabManagerIncludes.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabPaintManager.inl
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabPaintManagerAppearance.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TabManager\XTPTabPaintManagerColors.cpp
# End Source File
# End Group
# Begin Group "DockingPane"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPane.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneAutoHidePanel.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneBaseContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneBaseContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneContext.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneIncludes.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneKeyboardHook.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneKeyboardHook.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneMiniWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneMiniWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPanePaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPanePaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneSplitterContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneSplitterContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneTabbedContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\DockingPane\XTPDockingPaneTabbedContainer.h
# End Source File
# End Group
# Begin Group "PropertyGrid"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGrid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGrid.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceButton.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridInplaceList.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemBool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemBool.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemColor.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemExt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemExt.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemFont.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemFont.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemNumber.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemNumber.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemSize.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridItemSize.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\PropertyGrid\XTPPropertyGridView.h
# End Source File
# End Group
# Begin Group "ReportControl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportColumn.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportColumn.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportColumns.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportColumns.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportDragDrop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportDragDrop.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportFilterEditControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportFilterEditControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportGroupRow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportGroupRow.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportHeader.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportHyperlink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportHyperlink.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportInplaceControls.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportInplaceControls.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportNavigator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportNavigator.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecord.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecord.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecordItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecordItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecordItemText.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecordItemText.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecords.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRecords.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRow.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRows.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportRows.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportSubListControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportSubListControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportTip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportTip.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ReportControl\XTPReportView.h
# End Source File
# End Group
# Begin Group "Controls"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\Controls\XTAnimationMemDC.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTAnimationMemDC.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTBrowseDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTBrowseDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTBrowseEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTBrowseEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTButton.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTButtonTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTButtonTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaption.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaption.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaptionPopupWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaptionPopupWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaptionTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCaptionTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCheckListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTCheckListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPageCustom.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPageCustom.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPageStandard.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPageStandard.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPicker.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPicker.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorPopup.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorRef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorRef.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorSelectorCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorSelectorCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorSelectorCtrlTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTColorSelectorCtrlTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTComboBoxEx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTComboBoxEx.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDateTimeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDateTimeCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDirWatcher.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDirWatcher.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDropSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTDropSource.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTEditListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTEditListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTExcelTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTExcelTabCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTExcelTabCtrlTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTExcelTabCtrlTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFlatComboBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFlatComboBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFlatControlsTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFlatControlsTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFontCombo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFontCombo.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTFunctions.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTGlobal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTGlobal.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHeaderCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHeaderCtrlTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHeaderCtrlTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHelpers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHelpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHexEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHexEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHtmlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHtmlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHyperLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTHyperLink.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListCtrlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTListCtrlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMaskEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMaskEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMDIWndTab.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMDIWndTab.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMemDC.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMemDC.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMemFile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMemFile.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMenuListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMenuListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMenuListBoxTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTMenuListBoxTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTNotify.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTOutBarCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTOutBarCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTOutBarCtrlTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTOutBarCtrlTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPagerCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPagerCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPopupPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertyPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertyPageNavigator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertyPageNavigator.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertySheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPPropertySheet.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogAPI.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogAPI.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogClient.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogClient.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogControls.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogControls.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTPTaskDialogFrame.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTRegistryManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTRegistryManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResize.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResize.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeFormView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeFormView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeGroupBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeGroupBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePoint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePoint.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePropertyPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePropertySheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizePropertySheet.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeRect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTResizeRect.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSearchOptionsCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSearchOptionsCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellListBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellListBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellListCtrlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellListCtrlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellPidl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellPidl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellSettings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellSettings.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellTreeBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellTreeBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellTreeCtrlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTShellTreeCtrlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSortClass.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSortClass.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSplitterWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSplitterWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSplitterWndTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTSplitterWndTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabBaseTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabBaseTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabCtrlButtons.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabCtrlButtons.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTabView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTThemeManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTThemeManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTipOfTheDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTipOfTheDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTipWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTipWindow.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTrayIcon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTrayIcon.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTreeBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTreeBase.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTreeCtrlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTTreeCtrlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTUtil.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTUtil.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTVC50Helpers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTVC50Helpers.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWindowList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWindowList.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWindowPos.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWindowPos.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWndHook.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWndHook.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWndShadow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Controls\XTWndShadow.h
# End Source File
# End Group
# Begin Group "Calendar"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarController.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarController.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarControlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarControlView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarCustomDataProvider.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarCustomDataProvider.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarCustomProperties.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarCustomProperties.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarData.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDatabaseDataProvider.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDatabaseDataProvider.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewTimeScale.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDayViewTimeScale.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventLabel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventLabel.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventRecurrenceDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEventRecurrenceDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMAPIDataProvider.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMAPIDataProvider.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMAPIWrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMAPIWrapper.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMemoryDataProvider.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMemoryDataProvider.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthViewDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthViewDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthViewEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarMonthViewEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarNotifications.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarOccurSeriesChooseDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarOccurSeriesChooseDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarOptions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarOptions.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarPtrCollectionT.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarPtrs.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRecurrencePattern.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRecurrencePattern.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRemindersDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRemindersDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRemindersManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarRemindersManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarResource.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarResourcesManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarResourcesManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTheme.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarThemeOffice2007.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarThemeOffice2007.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTimeZoneHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTimeZoneHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarTip.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarUtils.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarViewPart.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekViewDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekViewDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekViewEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPCalendarWeekViewEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerControl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerDaysCollection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerDaysCollection.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerItemDay.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerItemDay.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerItemMonth.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerItemMonth.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerList.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerNotifications.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPDatePickerPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPTopLevelWndMsgNotifier.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Calendar\XTPTopLevelWndMsgNotifier.h
# End Source File
# End Group
# Begin Group "TaskPanel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanel.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelAnimation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelAnimation.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelGroupItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelGroupItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelItems.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelItems.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\TaskPanel\XTPTaskPanelPaintManager.h
# End Source File
# End Group
# Begin Group "ShortcutBar"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBarPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBarPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBarPane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\ShortcutBar\XTPShortcutBarPane.h
# End Source File
# End Group
# Begin Group "SkinFramework"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinDrawTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinDrawTools.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinImage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinImage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerApiHook.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerApiHook.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerColorFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerColorFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerModuleList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerModuleList.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerResource.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerSchema.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinManagerSchema.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObject.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectButton.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectComboBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectComboBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectEdit.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectFrame.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectHeader.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectListBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectListView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectListView.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectMDI.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectMDI.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectMenu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectMenu.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectProgress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectProgress.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectScrollBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectScrollBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectSpin.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectSpin.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectStatusBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectStatusBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTab.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTab.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectToolBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectToolBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTrackBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTrackBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTreeView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SkinFramework\XTPSkinObjectTreeView.h
# End Source File
# End Group
# Begin Group "Ribbon"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonBar.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonControlTab.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonControlTab.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonCustomizeQuickAccessPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonCustomizeQuickAccessPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonGroups.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonGroups.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonPopups.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonPopups.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonQuickAccessControls.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonQuickAccessControls.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonSystemButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonSystemButton.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonTab.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonTab.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonTheme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\Ribbon\XTPRibbonTheme.h
# End Source File
# End Group
# Begin Group "GraphicLibrary"

# PROP Default_Filter ""
# Begin Group "zlib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\adler32.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\compress.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\crc32.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\crc32.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\deflate.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\deflate.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\gzio.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\infback.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inffast.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inffast.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inffixed.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inflate.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inflate.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inftrees.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\inftrees.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\readme.txt
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\trees.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\trees.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\uncompr.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\zconf.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\zlib.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\zutil.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\zlib\zutil.h
# End Source File
# End Group
# Begin Group "libpng"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\license.txt
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\png.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\png.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngconf.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngerror.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pnggccrd.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngget.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngmem.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngpread.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngread.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngrio.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngrtran.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngrutil.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngset.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngtrans.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngvcrd.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngwio.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngwrite.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngwtran.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\libpng\pngwutil.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\XTPGraphicBitmapPng.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\GraphicLibrary\XTPGraphicBitmapPng.h
# End Source File
# End Group
# Begin Group "SyntaxEdit"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditAutoCompleteWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditAutoCompleteWnd.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditBufferManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditBufferManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditColorComboBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditColorComboBox.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditColorSampleText.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditColorSampleText.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditDefines.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditDoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditDoc.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditDrawTextProcessor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditDrawTextProcessor.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditFindReplaceDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditFindReplaceDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditGoToLineDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditGoToLineDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexCfgFileReader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexCfgFileReader.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexClass.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexClass.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexClassSubObjDef.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexClassSubObjT.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexColorFileReader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexColorFileReader.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexParser.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLexPtrs.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLineMarksManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditLineMarksManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPaintManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPaintManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPropertiesPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditPropertiesPage.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditSectionManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditSectionManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditSelection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditSelection.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditStruct.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditStruct.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditTextIterator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditTextIterator.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditToolTipCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditToolTipCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditUndoManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditUndoManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Source\SyntaxEdit\XTPSyntaxEditView.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# End Target
# End Project
