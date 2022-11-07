######################################################
#                                                    #
# Automatic generated Makefile for Visual Components #
#                                                    #
#                  Do NOT edit!                      #
#                                                    #
######################################################

VCC:=@'$(AS_BIN_PATH)/br.vc.pc.exe'
LINK:=@'$(AS_BIN_PATH)/BR.VC.Link.exe'
MODGEN:=@'$(AS_BIN_PATH)/BR.VC.ModGen.exe'
VCPL:=@'$(AS_BIN_PATH)/BR.VC.PL.exe'
VCHWPP:=@'$(AS_BIN_PATH)/BR.VC.HWPP.exe'
VCDEP:=@'$(AS_BIN_PATH)/BR.VC.Depend.exe'
VCFLGEN:=@'$(AS_BIN_PATH)/BR.VC.lfgen.exe'
VCREFHANDLER:=@'$(AS_BIN_PATH)/BR.VC.CrossReferenceHandler.exe'
VCXREFEXTENDER:=@'$(AS_BIN_PATH)/BR.AS.CrossRefVCExtender.exe'
RM=CMD /C DEL
PALFILE_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Palette.vcr
VCCFLAGS_GUI_Te=-server -proj GUI_Te -vc '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/VCObject.vc' -prj_path '$(AS_PROJECT_PATH)' -temp_path '$(AS_TEMP_PATH)' -cfg $(AS_CONFIGURATION) -plc $(AS_PLC) -plctemp $(AS_TEMP_PLC) -cpu_path '$(AS_CPU_PATH)'
VCFIRMWARE=4.72.2
VCFIRMWAREPATH=$(AS_VC_PATH)/Firmware/V4.72.2/SG4
VCOBJECT_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/VCObject.vc
VCSTARTUP='vcstart.br'
VCLOD='vclod.br'
VCSTPOST='vcstpost.br'
TARGET_FILE_GUI_Te=$(AS_CPU_PATH)/GUI_Te.br
OBJ_SCOPE_GUI_Te=Software/GUI
PRJ_PATH_GUI_Te=$(AS_PROJECT_PATH)
SRC_PATH_GUI_Te=$(AS_PROJECT_PATH)/Logical/$(OBJ_SCOPE_GUI_Te)/GUI_Test
TEMP_PATH_GUI_Te=$(AS_TEMP_PATH)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/GUI_Te
TEMP_PATH_Shared=$(AS_TEMP_PATH)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared
TEMP_PATH_ROOT_GUI_Te=$(AS_TEMP_PATH)
VC_LIBRARY_LIST_GUI_Te=$(TEMP_PATH_GUI_Te)/libraries.vci
VC_XREF_BUILDFILE_GUI_Te=$(AS_TEMP_PATH)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/vcxref.build
VC_XREF_CLEANFILE=$(AS_TEMP_PATH)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/vcxref.clean
VC_LANGUAGES_GUI_Te=$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr
CPUHWC='$(TEMP_PATH_GUI_Te)/cpuhwc.vci'
VC_STATIC_OPTIONS_GUI_Te='$(TEMP_PATH_GUI_Te)/vcStaticOptions.xml'
VC_STATIC_OPTIONS_Shared='$(TEMP_PATH_Shared)/vcStaticOptions.xml'
# include Shared and Font Makefile (only once)
	include $(AS_TEMP_PATH)/objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCFntDat/Font_GUI_Te.mak
ifneq ($(VCINC),1)
	VCINC=1
	include $(AS_TEMP_PATH)/objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared/VCShared.mak
endif

DEPENDENCIES_GUI_Te=-d vcgclass -profile 'False'
DEFAULT_STYLE_SHEET_GUI_Te='Source[local].StyleSheet[Color]'
SHARED_MODULE=$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/vcshared.br
LFNTFLAGS_GUI_Te=-P '$(AS_PROJECT_PATH)' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)'
BDRFLAGS_GUI_Te=-P '$(AS_PROJECT_PATH)' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)'

# Local Libs
LIB_LOCAL_OBJ_GUI_Te=$(TEMP_PATH_GUI_Te)/localobj.vca

# Hardware sources
PANEL_HW_OBJECT_GUI_Te=$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/GUI_Te/dis.Hardware.vco
PANEL_HW_VCI_GUI_Te=$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/GUI_Te/dis.Hardware.vci
PANEL_HW_SOURCE_GUI_Te=C:/projects/PUA_Lab1_Baranek/Physical/SIM_Config/Hardware.hw 
DIS_OBJECTS_GUI_Te=$(PANEL_HW_OBJECT_GUI_Te) $(KEYMAP_OBJECTS_GUI_Te)

# KeyMapping flags
$(TEMP_PATH_GUI_Te)/dis.PS2-Keyboard.vco: $(AS_PROJECT_PATH)/Physical/SIM_Config/X20CP1586/VC/PS2-Keyboard.dis $(PANEL_HW_SOURCE_GUI_Te)
	$(VCHWPP) -f '$(PANEL_HW_SOURCE_GUI_Te)' -o '$(subst .vco,.vci,$(TEMP_PATH_GUI_Te)/dis.PS2-Keyboard.vco)' -n GUI_Test -d GUI_Te -pal '$(PALFILE_GUI_Te)' -c '$(AS_CONFIGURATION)' -p '$(AS_PLC)' -ptemp '$(AS_TEMP_PLC)' -B 'C4.90' -L '' -hw '$(CPUHWC)' -warninglevel 2 -so $(VC_STATIC_OPTIONS_GUI_Te) -sos $(VC_STATIC_OPTIONS_Shared) -keyboard '$(AS_PROJECT_PATH)/Physical/SIM_Config/X20CP1586/VC/PS2-Keyboard.dis' -fp '$(AS_VC_PATH)/Firmware/V4.72.2/SG4' -prj '$(AS_PROJECT_PATH)' -apj 'PUA_Lab1_Baranek' -sfas -vcob '$(VCOBJECT_GUI_Te)'
	$(VCC) -f '$(subst .vco,.vci,$@)' -o '$@' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -k '$(VCVK_SOURCES_GUI_Te)' $(VCCFLAGS_GUI_Te) -p GUI_Te -sfas

KEYMAP_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Physical/SIM_Config/X20CP1586/VC/PS2-Keyboard.dis 
KEYMAP_OBJECTS_GUI_Te=$(TEMP_PATH_GUI_Te)/dis.PS2-Keyboard.vco 

# All Source Objects
FNINFO_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/DefaultFont.fninfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/Arial9px.fninfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/Arial9pxBold.fninfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/Arial10pxBold.fninfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/Arial12px.fninfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Fonts/Arial9pxValue.fninfo 

BMINFO_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AcknowledgeReset.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmActive.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassOFF.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassON.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmInactive.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmLatched.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmNotQuit.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmQuit.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Reset.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ResetAcknowledge.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Triggered.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_active.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ProgressBorder.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active_control.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed_control.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active_control.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_upside.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_downside.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/frame_header.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed_control.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA2_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA3_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditpadQVGA2_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadQVGA3_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_released.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_pressed.bminfo \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_pressed.bminfo 

BMGRP_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlphaPadQVGA.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/NumPad.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlphaPad.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlarmEvent.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlarmState.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/BypassState.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AcknowledgeState.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/NavigationPad.bmgrp \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/Borders.bmgrp 

PAGE_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Pages/Init_Page.page 

VCS_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/StyleSheets/Gray.vcs \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/StyleSheets/Color.vcs 

BDR_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Raised.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Sunken.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Etched.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Bump.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/SunkenOuter.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/RaisedInner.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Flat_black.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Flat_grey.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/BackwardActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/BackwardPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ControlActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ControlPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/DownActiveControl.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/DownPressedControl.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ForwardActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ForwardPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/GlobalAreaActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/GlobalAreaPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollDownActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollDownPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollUpActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollUpPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ProgressBarBorder.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollDownActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollDownPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollUpActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollUpPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollLeftActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollLeftPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollRightActive.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollRightPressed.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/UpActiveControl.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/UpPressedControl.bdr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/FrameHeader.bdr 

TPR_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NumPad.tpr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/AlphaPadQVGA.tpr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/AlphaPad.tpr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NavigationPad_ver.tpr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NavigationPad_hor.tpr \
	$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/EditPad.tpr 

TDC_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Trends/TrendData.tdc 

VCVK_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/VirtualKeys.vcvk 

VCR_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Palette.vcr 

# Runtime Object sources
VCR_OBJECT_GUI_Te=$(TEMP_PATH_GUI_Te)/vcrt.vco
VCR_SOURCE_GUI_Te=$(SRC_PATH_GUI_Te)/package.vcp
# All Source Objects END

#Panel Hardware
$(PANEL_HW_VCI_GUI_Te): $(PANEL_HW_SOURCE_GUI_Te) $(VC_LIBRARY_LIST_GUI_Te) $(KEYMAP_SOURCES_GUI_Te) $(PALFILE_GUI_Te)
	$(VCHWPP) -f '$<' -o '$@' -n GUI_Test -d GUI_Te -pal '$(PALFILE_GUI_Te)' -c '$(AS_CONFIGURATION)' -p '$(AS_PLC)' -ptemp '$(AS_TEMP_PLC)' -B 'C4.90' -L '' -verbose 'False' -profile 'False' -hw '$(CPUHWC)' -warninglevel 2 -so $(VC_STATIC_OPTIONS_GUI_Te) -sos $(VC_STATIC_OPTIONS_Shared) -fp '$(AS_VC_PATH)/Firmware/V4.72.2/SG4' -sfas -prj '$(AS_PROJECT_PATH)' -apj 'PUA_Lab1_Baranek' -vcob '$(VCOBJECT_GUI_Te)'

$(PANEL_HW_OBJECT_GUI_Te): $(PANEL_HW_VCI_GUI_Te) $(VC_LIBRARY_LIST_GUI_Te)
	$(VCC) -f '$(subst .vco,.vci,$@)' -o '$@' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -k '$(VCVK_SOURCES_GUI_Te)' $(VCCFLAGS_GUI_Te) -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


# Pages
PAGE_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/page., $(notdir $(PAGE_SOURCES_GUI_Te:.page=.vco)))

$(TEMP_PATH_GUI_Te)/page.Init_Page.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Pages/Init_Page.page $(VC_LANGUAGES_GUI_Te)
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -P '$(AS_PROJECT_PATH)' -ds '$(SRC_PATH_GUI_Te)/StyleSheets/Color.vcs' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#Pages END




# Stylesheets
VCS_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/vcs., $(notdir $(VCS_SOURCES_GUI_Te:.vcs=.vco)))

$(TEMP_PATH_GUI_Te)/vcs.Gray.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/StyleSheets/Gray.vcs
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -P '$(AS_PROJECT_PATH)' -ds $(DEFAULT_STYLE_SHEET_GUI_Te) -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/vcs.Color.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/StyleSheets/Color.vcs
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -P '$(AS_PROJECT_PATH)' -ds $(DEFAULT_STYLE_SHEET_GUI_Te) -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#Stylesheets END




# Virtual Keys
VCVK_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/vcvk., $(notdir $(VCVK_SOURCES_GUI_Te:.vcvk=.vco)))

$(TEMP_PATH_GUI_Te)/vcvk.VirtualKeys.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/VirtualKeys.vcvk
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas

$(VCVK_OBJECTS_GUI_Te): $(VC_LANGUAGES_GUI_Te)

#Virtual Keys END




# Touch Pads
TPR_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/tpr., $(notdir $(TPR_SOURCES_GUI_Te:.tpr=.vco)))

$(TEMP_PATH_GUI_Te)/tpr.NumPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NumPad.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/tpr.AlphaPadQVGA.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/AlphaPadQVGA.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/tpr.AlphaPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/AlphaPad.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/tpr.NavigationPad_ver.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NavigationPad_ver.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/tpr.NavigationPad_hor.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/NavigationPad_hor.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/tpr.EditPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/TouchPads/EditPad.tpr
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te) -prj 'C:/projects/PUA_Lab1_Baranek/Logical/Software/GUI/GUI_Test' -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#Touch Pads END




# BitmapGroups
BMGRP_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/bmgrp., $(notdir $(BMGRP_SOURCES_GUI_Te:.bmgrp=.vco)))

$(TEMP_PATH_GUI_Te)/bmgrp.AlphaPadQVGA.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlphaPadQVGA.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.NumPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/NumPad.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.AlphaPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlphaPad.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.AlarmEvent.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlarmEvent.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.AlarmState.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AlarmState.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.BypassState.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/BypassState.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.AcknowledgeState.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/AcknowledgeState.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.NavigationPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/NavigationPad.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bmgrp.Borders.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/BitmapGroups/Borders.bmgrp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#BitmapGroups END




# Bitmaps
BMINFO_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/bminfo., $(notdir $(BMINFO_SOURCES_GUI_Te:.bminfo=.vco)))

$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA1.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA2.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA3.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadVGA_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA2_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA2_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA3_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA3_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadQVGA1_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadQVGA1_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlphaPadVGA.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlphaPadVGA.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.NumPad_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.NumPad.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/NumPad.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AcknowledgeReset.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AcknowledgeReset.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AcknowledgeReset.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmActive.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmActive.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmActive.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmBypassOFF.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassOFF.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassOFF.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmBypassON.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassON.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmBypassON.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmInactive.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmInactive.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmInactive.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmLatched.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmLatched.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmLatched.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmNotQuit.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmNotQuit.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmNotQuit.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.AlarmQuit.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmQuit.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/AlarmQuit.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.Reset.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Reset.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Reset.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ResetAcknowledge.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ResetAcknowledge.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ResetAcknowledge.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.Triggered.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Triggered.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/Triggered.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ListPadHor.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ListPadHor_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadHor_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ListPadVer.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ListPadVer_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ListPadVer_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.backward_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.backward_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/backward_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.global_area_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.global_area_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.forward_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.forward_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/forward_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.control_button_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.control_button_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/control_button_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.right_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.right_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/right_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.left_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.left_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/left_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.up_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.up_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.down_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.down_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.multi_up_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.multi_up_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_up_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.multi_down_active.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_active.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_active.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.multi_down_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/multi_down_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.ProgressBorder.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ProgressBorder.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/ProgressBorder.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.down_active_control.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active_control.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_active_control.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.down_pressed_control.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed_control.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/down_pressed_control.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.up_active_control.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active_control.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_active_control.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.global_area_gradient_upside.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_upside.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_upside.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.global_area_gradient_downside.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_downside.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/global_area_gradient_downside.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.frame_header.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/frame_header.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/frame_header.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.up_pressed_control.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed_control.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/up_pressed_control.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.EditPadVGA.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.EditPadVGA_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/EditPadVGA_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneNumPad_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneListPadVer_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPad_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPad_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPad_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPadQVGA1_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPadQVGA1_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA1_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPadQVGA2_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA2_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA2_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneAlphaPadQVGA3_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA3_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneAlphaPadQVGA3_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneEditpadQVGA2_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditpadQVGA2_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditpadQVGA2_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneEditPadQVGA3_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadQVGA3_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadQVGA3_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneEditPadVga_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneEditPadVga_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneEditPadVga_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneListPadHor_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneListPadHor_released.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_released.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadHor_released.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneListPadVer_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneListPadVer_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


$(TEMP_PATH_GUI_Te)/bminfo.zuneNumPad_pressed.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_pressed.bminfo $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Bitmaps/zuneNumPad_pressed.bmp
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#Bitmaps END




# Trend Data Configuration
TDC_OBJECTS_GUI_Te = $(addprefix $(TEMP_PATH_GUI_Te)/tdc., $(notdir $(TDC_SOURCES_GUI_Te:.tdc=.vco)))

$(TEMP_PATH_GUI_Te)/tdc.TrendData.vco: $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Trends/TrendData.tdc
	 $(VCC) -f '$<' -o '$@' -l '$(AS_PROJECT_PATH)/Logical/VCShared/Languages.vcr' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -pal '$(PALFILE_GUI_Te)' $(VCCFLAGS_GUI_Te)  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas


#Trend Data Configuration END


#
# Borders
#
BDR_SOURCES_GUI_Te=$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Raised.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Sunken.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Etched.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Bump.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/SunkenOuter.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/RaisedInner.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Flat_black.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/Flat_grey.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/BackwardActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/BackwardPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ControlActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ControlPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/DownActiveControl.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/DownPressedControl.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ForwardActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ForwardPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/GlobalAreaActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/GlobalAreaPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollDownActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollDownPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollUpActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/MultiScrollUpPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ProgressBarBorder.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollDownActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollDownPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollUpActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollUpPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollLeftActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollLeftPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollRightActive.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/ScrollRightPressed.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/UpActiveControl.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/UpPressedControl.bdr $(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Borders/FrameHeader.bdr 
BDR_OBJECTS_GUI_Te=$(TEMP_PATH_GUI_Te)/bdr.Bordermanager.vco
$(TEMP_PATH_GUI_Te)/bdr.Bordermanager.vco: $(BDR_SOURCES_GUI_Te)
	$(VCC) -f '$<' -o '$@' -pkg '$(SRC_PATH_GUI_Te)' $(BDRFLAGS_GUI_Te) $(VCCFLAGS_GUI_Te) -p GUI_Te$(SRC_PATH_GUI_Te)
#
# Logical fonts
#
$(TEMP_PATH_GUI_Te)/lfnt.en.vco: $(TEMP_PATH_GUI_Te)/en.lfnt $(VC_LANGUAGES_GUI_Te)
	 $(VCC) -f '$<' -o '$@' $(LFNTFLAGS_GUI_Te) $(VCCFLAGS_GUI_Te) -p GUI_Te -sfas
$(TEMP_PATH_GUI_Te)/lfnt.de.vco: $(TEMP_PATH_GUI_Te)/de.lfnt $(VC_LANGUAGES_GUI_Te)
	 $(VCC) -f '$<' -o '$@' $(LFNTFLAGS_GUI_Te) $(VCCFLAGS_GUI_Te) -p GUI_Te -sfas
LFNT_OBJECTS_GUI_Te=$(TEMP_PATH_GUI_Te)/lfnt.en.vco $(TEMP_PATH_GUI_Te)/lfnt.de.vco 

#Runtime Object
$(VCR_OBJECT_GUI_Te) : $(VCR_SOURCE_GUI_Te)
	$(VCC) -f '$<' -o '$@' -cv '$(AS_PROJECT_PATH)/Logical/VCShared/ControlVersion.cvinfo' -sl en $(VCCFLAGS_GUI_Te) -rt  -p GUI_Te -so $(VC_STATIC_OPTIONS_GUI_Te) -vcr 4722 -sfas
# Local resources Library rules
LIB_LOCAL_RES_GUI_Te=$(TEMP_PATH_GUI_Te)/localres.vca
$(LIB_LOCAL_RES_GUI_Te) : $(TEMP_PATH_GUI_Te)/GUI_Te02.ccf

# Bitmap Library rules
LIB_BMP_RES_GUI_Te=$(TEMP_PATH_GUI_Te)/bmpres.vca
$(LIB_BMP_RES_GUI_Te) : $(TEMP_PATH_GUI_Te)/GUI_Te03.ccf
$(BMGRP_OBJECTS_GUI_Te) : $(PALFILE_GUI_Te) $(VC_LANGUAGES_GUI_Te)
$(BMINFO_OBJECTS_GUI_Te) : $(PALFILE_GUI_Te)

BUILD_FILE_GUI_Te=$(TEMP_PATH_GUI_Te)/BuildFiles.arg
$(BUILD_FILE_GUI_Te) : BUILD_FILE_CLEAN_GUI_Te $(BUILD_SOURCES_GUI_Te)
BUILD_FILE_CLEAN_GUI_Te:
	$(RM) /F /Q '$(BUILD_FILE_GUI_Te)' 2>nul
#All Modules depending to this project
PROJECT_MODULES_GUI_Te=$(AS_CPU_PATH)/GUI_Te01.br $(AS_CPU_PATH)/GUI_Te02.br $(AS_CPU_PATH)/GUI_Te03.br $(FONT_MODULES_GUI_Te) $(SHARED_MODULE)

# General Build rules

$(TARGET_FILE_GUI_Te): $(PROJECT_MODULES_GUI_Te) $(TEMP_PATH_GUI_Te)/GUI_Te.prj
	$(MODGEN) -so $(VC_STATIC_OPTIONS_GUI_Te) -fw '$(VCFIRMWAREPATH)' -m $(VCSTPOST) -v V1.00.0 -f '$(TEMP_PATH_GUI_Te)/GUI_Te.prj' -o '$@' -vc '$(VCOBJECT_GUI_Te)' $(DEPENDENCIES_GUI_Te) $(addprefix -d ,$(notdir $(PROJECT_MODULES_GUI_Te:.br=)))

$(AS_CPU_PATH)/GUI_Te01.br: $(TEMP_PATH_GUI_Te)/GUI_Te01.ccf
	$(MODGEN) -so $(VC_STATIC_OPTIONS_GUI_Te) -fw '$(VCFIRMWAREPATH)' -m $(VCLOD) -v V1.00.0 -b -vc '$(VCOBJECT_GUI_Te)' -f '$<' -o '$@' $(DEPENDENCIES_GUI_Te)

$(AS_CPU_PATH)/GUI_Te02.br: $(TEMP_PATH_GUI_Te)/GUI_Te02.ccf
	$(MODGEN) -so $(VC_STATIC_OPTIONS_GUI_Te) -fw '$(VCFIRMWAREPATH)' -m $(VCLOD) -v V1.00.0 -b -vc '$(VCOBJECT_GUI_Te)' -f '$<' -o '$@' $(DEPENDENCIES_GUI_Te)

$(AS_CPU_PATH)/GUI_Te03.br: $(TEMP_PATH_GUI_Te)/GUI_Te03.ccf
	$(MODGEN) -so $(VC_STATIC_OPTIONS_GUI_Te) -fw '$(VCFIRMWAREPATH)' -m $(VCLOD) -v V1.00.0 -b -vc '$(VCOBJECT_GUI_Te)' -f '$<' -o '$@' $(DEPENDENCIES_GUI_Te)

# General Build rules END
$(LIB_LOCAL_OBJ_GUI_Te) : $(TEMP_PATH_GUI_Te)/GUI_Te01.ccf

# Main Module
$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared/GUI_Te.vcm:
$(TEMP_PATH_GUI_Te)/GUI_Te.prj: $(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared/GUI_Te.vcm
	$(VCDEP) -m '$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared/GUI_Te.vcm' -s '$(AS_CPU_PATH)/VCShared/Shared.vcm' -p '$(AS_PATH)/AS/VC/Firmware' -c '$(AS_CPU_PATH)' -fw '$(VCFIRMWAREPATH)' -hw '$(CPUHWC)' -so $(VC_STATIC_OPTIONS_GUI_Te) -o GUI_Te -proj GUI_Te
	$(VCPL) $(notdir $(PROJECT_MODULES_GUI_Te:.br=,4)) GUI_Te,2 -o '$@' -p GUI_Te -vc 'GUI_Te' -verbose 'False' -fl '$(TEMP_PATH_ROOT_GUI_Te)/Objects/$(AS_CONFIGURATION)/$(AS_TEMP_PLC)/VCShared/GUI_Te.vcm' -vcr '$(VCR_SOURCE_GUI_Te)' -prj '$(AS_PROJECT_PATH)' -warningLevel2 -sfas

# 01 Module

DEL_TARGET01_LFL_GUI_Te=$(TEMP_PATH_GUI_Te)\GUI_Te01.ccf.lfl
$(TEMP_PATH_GUI_Te)/GUI_Te01.ccf: $(LIB_SHARED) $(SHARED_CCF) $(LIB_BMP_RES_GUI_Te) $(TEMP_PATH_GUI_Te)/GUI_Te03.ccf $(LIB_LOCAL_RES_GUI_Te) $(TEMP_PATH_GUI_Te)/GUI_Te02.ccf $(DIS_OBJECTS_GUI_Te) $(PAGE_OBJECTS_GUI_Te) $(VCS_OBJECTS_GUI_Te) $(VCVK_OBJECTS_GUI_Te) $(VCRT_OBJECTS_GUI_Te) $(TPR_OBJECTS_GUI_Te) $(TXTGRP_OBJECTS_GUI_Te) $(LAYER_OBJECTS_GUI_Te) $(VCR_OBJECT_GUI_Te) $(TDC_OBJECTS_GUI_Te) $(TRD_OBJECTS_GUI_Te) $(TRE_OBJECTS_GUI_Te) $(PRC_OBJECTS_GUI_Te) $(SCR_OBJECTS_GUI_Te)
	-@CMD /Q /C if exist "$(DEL_TARGET01_LFL_GUI_Te)" DEL /F /Q "$(DEL_TARGET01_LFL_GUI_Te)" 2>nul
	@$(VCFLGEN) '$@.lfl' '$(LIB_SHARED)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(LIB_BMP_RES_GUI_Te)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(LIB_LOCAL_RES_GUI_Te)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(DIS_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .page -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(VCS_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .vcvk -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(VCRT_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(TPR_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .txtgrp -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .layer -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(VCR_OBJECT_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .tdc -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .trd -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(SCR_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	$(LINK) '$@.lfl' -o '$@' -p GUI_Te -lib '$(LIB_LOCAL_OBJ_GUI_Te)' -P '$(AS_PROJECT_PATH)' -m 'local objects' -profile 'False' -warningLevel2 -vcr 4722 -sfas
# 01 Module END

# 02 Module

DEL_TARGET02_LFL_GUI_Te=$(TEMP_PATH_GUI_Te)\GUI_Te02.ccf.lfl
$(TEMP_PATH_GUI_Te)/GUI_Te02.ccf: $(LIB_SHARED) $(SHARED_CCF) $(LIB_BMP_RES_GUI_Te) $(TEMP_PATH_GUI_Te)/GUI_Te03.ccf $(BDR_OBJECTS_GUI_Te) $(LFNT_OBJECTS_GUI_Te) $(CLM_OBJECTS_GUI_Te)
	-@CMD /Q /C if exist "$(DEL_TARGET02_LFL_GUI_Te)" DEL /F /Q "$(DEL_TARGET02_LFL_GUI_Te)" 2>nul
	@$(VCFLGEN) '$@.lfl' '$(LIB_SHARED)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(LIB_BMP_RES_GUI_Te)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(BDR_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(LFNT_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' '$(CLM_OBJECTS_GUI_Te:.vco=.vco|)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	$(LINK) '$@.lfl' -o '$@' -p GUI_Te -lib '$(LIB_LOCAL_RES_GUI_Te)' -P '$(AS_PROJECT_PATH)' -m 'local resources' -profile 'False' -warningLevel2 -vcr 4722 -sfas
# 02 Module END

# 03 Module

DEL_TARGET03_LFL_GUI_Te=$(TEMP_PATH_GUI_Te)\GUI_Te03.ccf.lfl
$(TEMP_PATH_GUI_Te)/GUI_Te03.ccf: $(LIB_SHARED) $(SHARED_CCF) $(BMGRP_OBJECTS_GUI_Te) $(BMINFO_OBJECTS_GUI_Te) $(PALFILE_GUI_Te)
	-@CMD /Q /C if exist "$(DEL_TARGET03_LFL_GUI_Te)" DEL /F /Q "$(DEL_TARGET03_LFL_GUI_Te)" 2>nul
	@$(VCFLGEN) '$@.lfl' '$(LIB_SHARED)' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .bmgrp -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	@$(VCFLGEN) '$@.lfl' -mask .bminfo -vcp '$(AS_PROJECT_PATH)/Logical/Software/GUI/GUI_Test/Package.vcp' -temp '$(TEMP_PATH_GUI_Te)' -prj '$(PRJ_PATH_GUI_Te)' -sfas
	$(LINK) '$@.lfl' -o '$@' -p GUI_Te -lib '$(LIB_BMP_RES_GUI_Te)' -P '$(AS_PROJECT_PATH)' -m 'bitmap resources' -profile 'False' -warningLevel2 -vcr 4722 -sfas
# 03 Module END

# Post Build Steps

.PHONY : vcPostBuild_GUI_Te

vcPostBuild_GUI_Te :
	$(VCC) -pb -vcm '$(TEMP_PATH_GUI_Te)/MODULEFILES.vcm' -fw '$(VCFIRMWAREPATH)' $(VCCFLAGS_GUI_Te) -p GUI_Te -vcr 4722 -sfas

# Post Build Steps END
