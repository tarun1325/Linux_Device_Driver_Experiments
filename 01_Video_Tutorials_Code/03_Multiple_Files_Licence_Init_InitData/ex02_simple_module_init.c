/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Simple Module - Init Function File
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>

// Module License
MODULE_LICENSE("GPL");

// Module Load Function
int ex02_simple_module_init(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return 0;
}

module_init(ex02_simple_module_init);

