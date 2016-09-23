/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Building Simple Module to Attach to Kernel
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>

// Module Load Function
int ex01_simple_module_init(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return 0;
}

// Module Unload Function
void ex01_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
}

// Registering our load/unload function with Kernel
module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
MODULE_LICENSE("GPL");
