MAKECMD         = "%MATLAB%\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = raptor.tlc
SHELL           = cmd

MODEL_NAME		= Accelerator
MODULES			= Accelerator_data.c Table_Functions.c XCP_App.c can_CAN1.c can_CAN2.c can_general.c data.c faultmanager.c hw_user.c raptorCRC.c raptor_delta_time.c raptor_time.c rtGetInf.c rtGetNaN.c rt_nonfinite.c time.c xcp_protocol.c
NUMST           = 
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS =
NCSTATES =

$(MODEL_NAME).mot: 
	@echo ### Created Makefile ...

DO_NOT_USE_CHECKSUMS = 1

# EOF: raptor.tmf