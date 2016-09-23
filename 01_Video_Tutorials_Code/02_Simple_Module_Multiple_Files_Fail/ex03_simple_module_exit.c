/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Simple Module - Exit Function File
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>


// Module Unload Function
void ex03_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
}

module_exit(ex03_simple_module_exit);
