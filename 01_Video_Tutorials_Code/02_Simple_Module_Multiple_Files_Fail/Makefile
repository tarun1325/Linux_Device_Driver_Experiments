# Check $ARCH and $CROSS_COMPILE before running make
# CROSS_COMPILE should not be set for native compiler
#
ifneq ($(KERNELRELEASE),)

obj-m := ex02_simple_module_init.o
obj-m += ex03_simple_module_exit.o

else
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules
clean:
	-rm *.mod.c *.o .*.cmd Module.symvers modules.order || :
	-rm -rf .tmp_versions || :

.PHONY: clean

endif
