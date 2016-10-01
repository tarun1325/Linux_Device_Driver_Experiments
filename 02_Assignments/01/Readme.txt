ESD 854 Device Driver Development

Fall 2016

Assignment 1

Summary

You will demonstrate mastery of building and operating kernel modules on a
Raspberry Pi board. You will prepare a report on your observations and
experience in compiling and using these modules

Source Files from LMS
	Notes Folder/
		Exercise1
			blinker/
				blinker.c
				Makefile
			digiout/
				digiout.c
				Makefile
Procedure

In this assignment, you will setup a Raspberry Pi for compiling modular device
driver. You will prepare a microSD card with the Raspbian distribution and boot
a Raspberry Pi with that card.

After a successful bootup, you will load all the packages essential for
compiling kernel modules on that card and build your first device driver module
natively.

You may also setup a cross-compilation environment on an x86 computer, build
and test the same driver as a cross-compiled module.

You will then proceed to build and demonstrate the operation of blinker and
digiout modules and prepare a report on your observations.

 1) Run make in blinker and digiout directories to build the modules successfully
 2) check the proper binary (x86 or ARM) format
 3) print module info for both modules and point out the parameter details
 4) load blinker module and show the registration of bln driver in sysfs
 5) load digiout module and show its sysfs entries including gpio group
 6) show and explain the automatic binding of digiout to bln driver
 7) unbind the led.4 device from the driver and show its effects in sysfs
 8) bind the device again to the driver and prove it in sysfs
 9) unload blinker module and show its effects on digiout in sysfs
 a) unload digiout module and show that it is no longer loaded
 b) reload the blinker with a different parameter and show its log entries

Study the following
 1) What happens if you load blinker a second time?
 2) What happens if you load digiout a second time?
 3) Rebuild the digiout module by changing led4 device name from "bln" to "led"
    When you load this module, does bln driver bind to the device automatically?
    How will you now bind this device to bln driver?
 4) What happens if you retain the name but change the id from 4 to 6?
 5) What happens if you try to load a module compiled for x86 kernel
    on Raspberry Pi?

Report

You may work in pairs during the experiments, but I expect separate report
from each one of you.  Your report should contain your observations, including
errors, the reason deduced by you for these errors. Include screenshots or text
clippings from your terminal as required.  The report should reach my mailbox
by 10am on 28 Sep 2016.

References

1. https://www.raspberrypi.org/documentation/linux/kernel/building.md
2. https://github.com/raspberrypi/firmware
3. http://lxr.free-electrons.com/source/?v=4.4
4. source code of rpi-source
5. source code of rpi-update

.oOo.
