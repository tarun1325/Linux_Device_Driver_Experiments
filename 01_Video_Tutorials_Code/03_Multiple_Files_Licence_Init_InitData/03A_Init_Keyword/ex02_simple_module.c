/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Building Simple Module to Attach to Kernel
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>


__initdata int count = 5;

// Module Load Function
__init int ex02_simple_module_init(void)
{
	int index = 0;
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	for(index = 0; index < count; index++)
	{
		printk(KERN_ALERT "Index is %d\n", index);
	}
	return 0;
}

// Module Unload Function
void ex02_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
}

// Registering our load/unload function with Kernel
module_init(ex02_simple_module_init);
module_exit(ex02_simple_module_exit);
MODULE_LICENSE("GPL");
