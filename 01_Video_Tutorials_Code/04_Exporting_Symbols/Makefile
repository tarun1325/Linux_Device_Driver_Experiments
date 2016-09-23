ifneq ($(KERNELRELEASE),)

obj-m := ex01_exporting_symbols.o
obj-m += ex02_using_symbols.o

else

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules
clean:
	-rm *.ko *.mod.c *.o Module.symvers modules.order

.PHONY: clean
endif
