# File name: motor28335_2.mk
# Autogenerated on: 30-Jul-2015 16:49:11
# Copyright 2009-2011 The MathWorks, Inc.
#
# Model: MOTOR28335_2
# Template: gmake 
# Template Version: 1.0 
# Tool Chain Configuration: ticcs_c2000_ccsv5_clone
# Tool Chain Configuration Version: 2.0

THIS_MAKEFILE        := $(lastword $(MAKEFILE_LIST))
EMPTY                :=
SPACE                := $(EMPTY) $(EMPTY)
MODEL_NAME           := motor28335_2
HOST_PLATFORM        := windows
BUILD_CFG            := CustomMW
TARGET_EXT           := .out
OBJ_EXT              := .obj
TOOL_CHAIN_CFG       := ticcs_c2000_ccsv5_clone

FORMAT_PATH = $(if $(filter \\\\%,$(1)),"$(1)",$(subst $(SPACE),\$(SPACE),$(subst \,/,$(1))))

MATLAB_ROOT_RELATIVE := ..\..\..\..\..\Program Files\MATLAB\R2012b\#MATLAB_ROOT_RELATIVE_END
MATLAB_ROOT_ABSOLUTE := C:\Program Files\MATLAB\R2012b\#MATLAB_ROOT_ABSOLUTE_END
SOURCE_PATH          := $(call FORMAT_PATH,.\)
OUTPUT_PATH          := $(call FORMAT_PATH,$(SOURCE_PATH)$(BUILD_CFG)/)
DERIVED_PATH         := $(call FORMAT_PATH,$(SOURCE_PATH)derived/)
TARGET_NAME_PREFIX   := 
TARGET_NAME_POSTFIX  := 
TARGET_FILE          := $(TARGET_NAME_PREFIX)$(MODEL_NAME)$(TARGET_NAME_POSTFIX)$(TARGET_EXT)
TARGET               := $(OUTPUT_PATH)$(TARGET_FILE)

###########################################################################
# Code Generation Files
###########################################################################

SOURCE_FILES        := $(call FORMAT_PATH,.\DSP2833x_ADC_cal.asm) $(call FORMAT_PATH,.\DSP2833x_Adc.c) $(call FORMAT_PATH,.\DSP2833x_CodeStartBranch.asm) $(call FORMAT_PATH,.\DSP2833x_CpuTimers.c) $(call FORMAT_PATH,.\DSP2833x_DMA.c) $(call FORMAT_PATH,.\DSP2833x_DefaultIsr.c) $(call FORMAT_PATH,.\DSP2833x_GlobalVariableDefs.c) $(call FORMAT_PATH,.\DSP2833x_MemCopy.c) $(call FORMAT_PATH,.\DSP2833x_PieCtrl.c) $(call FORMAT_PATH,.\DSP2833x_PieVect.c) $(call FORMAT_PATH,.\DSP2833x_SysCtrl.c) $(call FORMAT_PATH,.\DSP2833x_usDelay.asm) $(call FORMAT_PATH,.\MW_c28xx_adc.c) $(call FORMAT_PATH,.\MW_c28xx_board.c) $(call FORMAT_PATH,.\MW_c28xx_csl.c) $(call FORMAT_PATH,.\MW_c28xx_pwm.c) $(call FORMAT_PATH,.\MW_c28xx_qep.c) $(call FORMAT_PATH,.\motor28335_2.c) $(call FORMAT_PATH,.\motor28335_2_data.c) $(call FORMAT_PATH,.\motor28335_2_main.c)
HEADER_FILES        := $(call FORMAT_PATH,.\motor28335_2.h)
LIBRARY_FILES       := $(call FORMAT_PATH,.\motor28335_2.cmd) $(call FORMAT_PATH,..\..\..\..\..\PROGRA~1\MATLAB\R2012b\toolbox\idelink\EXTENS~1\ticcs\rtlib\IQMATH~1.LIB)
OBJ_FILES           := $(addprefix $(DERIVED_PATH),$(addsuffix $(OBJ_EXT),$(basename $(notdir $(SOURCE_FILES)))))
SKIPPED_FILES       := 

###########################################################################
# Code Generation Information
###########################################################################

COMPILER_CODEGEN_ARGS := -I"C:/Program Files/MATLAB/R2012b/toolbox/idelink/extensions/ticcs/inc" -I"C:/Users/Krunal/Documents/MATLAB/motor28335_2_ticcs" -I"C:/Users/Krunal/Documents/MATLAB" -I"C:/Program Files/MATLAB/R2012b/extern/include" -I"C:/Program Files/MATLAB/R2012b/simulink/include" -I"C:/Program Files/MATLAB/R2012b/rtw/c/src" -I"C:/Program Files/MATLAB/R2012b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2012b/rtw/c/ert" -D"__TICCSC__" -D"RT" -D"USE_RTMODEL" -ml -v28 --float_support=fpu32 -D"MODEL=motor28335_2" -D"NUMST=2" -D"NCSTATES=0" -D"HAVESTDIO=" -D"ONESTEPFCN=1" -D"TERMFCN=1" -D"MAT_FILE=0" -D"MULTI_INSTANCE_CODE=0" -D"INTEGER_CODE=0" -D"MT=1" -D"CLASSIC_INTERFACE=0" -D"TID01EQ=0"
COMPILER_TCCFG_ARGS   := -I"include" -fr"$(DERIVED_PATH)"
COMPILER_ARGS         := $(COMPILER_CODEGEN_ARGS) $(COMPILER_TCCFG_ARGS)
LINKER_CODEGEN_ARGS   := -z -l"rts2800_fpu32.lib" -c -x -m"motor28335_2.map" -stack0x200
LINKER_TCCFG_ARGS     := -o $(TARGET)
LINKER_ARGS           := $(LINKER_CODEGEN_ARGS) $(LINKER_TCCFG_ARGS)
PREBUILD_ARGS         := 
POSTBUILD_ARGS        := 
EXECUTE_ARGS          := To customize the execute command, clone this configuration



COMPILER           ?= $(subst \,/,bin\cl2000)
LINKER             ?= $(subst \,/,bin\cl2000)
PREBUILD_TOOL      ?= 
POSTBUILD_TOOL     ?= 
EXECUTE_USES_TARGET = off

ifeq (on,$(EXECUTE_USES_TARGET))
 EXECUTE_TOOL ?= $(TARGET)
else
 EXECUTE_TOOL ?= $(subst \,/,echo)
endif

ifeq (windows,$(HOST_PLATFORM))
 RM ?= del /q
else
 RM ?= rm -f
endif

ifeq (windows,$(HOST_PLATFORM))
 MKDIR ?= mkdir
else
 MKDIR ?= mkdir -p
endif

###########################################################################
# Targets
###########################################################################

.DEFAULT_GOAL := all

.PHONY : all execute prebuild build postbuild info environment check clean

all : execute

ifneq (,$(strip $(EXECUTE_TOOL)))
execute : build
	$(info "Evaluating execute target...")
	"$(EXECUTE_TOOL)" $(EXECUTE_ARGS)
else
execute : build
endif

build : postbuild
	$(info "Evaluating build target...")

ifneq (,$(strip $(PREBUILD_TOOL)))
prebuild : | $(OUTPUT_PATH) $(DERIVED_PATH)
	$(info "Evaluating prebuild target...")
	"$(PREBUILD_TOOL)" $(PREBUILD_ARGS)
else
prebuild : | $(OUTPUT_PATH) $(DERIVED_PATH)
endif

ifneq (,$(strip $(POSTBUILD_TOOL)))
postbuild : $(TARGET)
	$(info "Evaluating postbuild target...")
	"$(POSTBUILD_TOOL)" $(POSTBUILD_ARGS)
else
postbuild : $(TARGET)
endif

ifneq (,$(strip $(LINKER)))
$(TARGET) : prebuild $(OBJ_FILES)
	"$(LINKER)" $(LINKER_ARGS) $(OBJ_FILES) $(LIBRARY_FILES)

$(OBJ_FILES) : $(SOURCE_FILES) $(HEADER_FILES)
	"$(COMPILER)" $(COMPILER_ARGS) $(SOURCE_FILES)
else
$(TARGET) : prebuild $(SOURCE_FILES) $(HEADER_FILES)
	"$(COMPILER)" $(COMPILER_ARGS) $(SOURCE_FILES)
endif

$(OUTPUT_PATH) :
ifeq (,$(wildcard $(OUTPUT_PATH)))
	@$(MKDIR) "$(OUTPUT_PATH)"
endif

$(DERIVED_PATH) :
ifeq (,$(wildcard $(DERIVED_PATH)))
	@$(MKDIR) "$(DERIVED_PATH)"
endif

clean :
	-@$(RM) $(TARGET) $(OBJ_FILES)

info : 
	$(info MODEL_NAME=$(MODEL_NAME))
	$(info HOST_PLATFORM=$(HOST_PLATFORM))
	$(info BUILD_CFG=$(BUILD_CFG))
	$(info TOOL_CHAIN_CFG=$(TOOL_CHAIN_CFG))
	$(info TARGET_EXT=$(TARGET_EXT))
	$(info OBJ_EXT=$(OBJ_EXT))
	$(info SOURCE_PATH=$(SOURCE_PATH))
	$(info OUTPUT_PATH=$(OUTPUT_PATH))
	$(info DERIVED_PATH=$(DERIVED_PATH))
	$(info TARGET_FILE=$(TARGET_FILE))
	$(info TARGET=$(TARGET))
	$(info COMPILER=$(COMPILER))
	$(info COMPILER_ARGS=$(COMPILER_ARGS))
	$(info COMPILER_CODEGEN_ARGS=$(COMPILER_CODEGEN_ARGS))
	$(info COMPILER_TCCFG_ARGS=$(COMPILER_TCCFG_ARGS))
	$(info LINKER=$(LINKER))
	$(info LINKER_ARGS=$(LINKER_ARGS))
	$(info LINKER_CODEGEN_ARGS=$(LINKER_CODEGEN_ARGS))
	$(info LINKER_TCCFG_ARGS=$(LINKER_TCCFG_ARGS))
	$(info PREBUILD_TOOL=$(PREBUILD_TOOL))
	$(info PREBUILD_ARGS=$(PREBUILD_ARGS))
	$(info POSTBUILD_TOOL=$(POSTBUILD_TOOL))
	$(info POSTBUILD_ARGS=$(POSTBUILD_ARGS))
	$(info EXECUTE_TOOL=$(EXECUTE_TOOL))
	$(info EXECUTE_ARGS=$(EXECUTE_ARGS))
	$(info SOURCE_FILES=$(SOURCE_FILES))
	$(info HEADER_FILES=$(HEADER_FILES))
	$(info LIBRARY_FILES=$(LIBRARY_FILES))
	$(info OBJ_FILES=$(OBJ_FILES))
	$(info SKIPPED_FILES=$(SKIPPED_FILES))
	$(info RM=$(RM))
	$(info MKDIR=$(MKDIR))

environment :
	$(if $(findstring windows,$(HOST_PLATFORM)),$(info ENVIRONMENT=$(shell set)),$(info ENVIRONMENT=$(shell env)))
