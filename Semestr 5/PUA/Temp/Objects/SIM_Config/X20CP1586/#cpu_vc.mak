export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_BIN_PATH := C:/BrAutomation/AS49/bin-en
export AS_INSTALL_PATH := C:/BrAutomation/AS49
export AS_PATH := C:/BrAutomation/AS49
export AS_VC_PATH := C:/BrAutomation/AS49/AS/VC
export AS_GNU_INST_PATH := C:/BrAutomation/AS49/AS/gnuinst/V4.1.2
export AS_STATIC_ARCHIVES_PATH := C:/projects/PUA_Lab1_Baranek/Temp/Archives/SIM_Config/X20CP1586
export AS_CPU_PATH := C:/projects/PUA_Lab1_Baranek/Temp/Objects/SIM_Config/X20CP1586
export AS_CPU_PATH_2 := C:/projects/PUA_Lab1_Baranek/Temp/Objects/SIM_Config/X20CP1586
export AS_TEMP_PATH := C:/projects/PUA_Lab1_Baranek/Temp
export AS_BINARIES_PATH := C:/projects/PUA_Lab1_Baranek/Binaries
export AS_PROJECT_CPU_PATH := C:/projects/PUA_Lab1_Baranek/Physical/SIM_Config/X20CP1586
export AS_PROJECT_CONFIG_PATH := C:/projects/PUA_Lab1_Baranek/Physical/SIM_Config
export AS_PROJECT_PATH := C:/projects/PUA_Lab1_Baranek
export AS_PROJECT_NAME := PUA_Lab1_Baranek
export AS_PLC := X20CP1586
export AS_TEMP_PLC := X20CP1586
export AS_USER_NAME := Liss_2
export AS_CONFIGURATION := SIM_Config
export AS_COMPANY_NAME := \ 
export AS_VERSION := 4.9.2.46
export AS_WORKINGVERSION := 4.9


default: \
	$(AS_CPU_PATH)/GUI_Te.br \
	vcPostBuild_GUI_Te \



include $(AS_CPU_PATH)/GUI_Te/GUI_Te.mak
