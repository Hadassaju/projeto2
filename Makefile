APP_EXE  = projeto2
APP_SRC  = projeto2.c $(STARTUP)
LDSCRIPT = ../common/soc.ld
RISCV_GCC_OPTS = -nostartfiles -T $(LDSCRIPT) -march=$(MARCH) -mabi=$(MABI) -O2

include ../common/common.mk
