/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Building Simple Module to Attach to Kernel
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

// Global Variable
int count=1;

// Specifying Module Parameter
module_param(count,int,0644);

// Module Load Function
int ex02_module_param_init(void)
{
	int index =0;
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	for(index = 0; index < count; index++)
		printk(KERN_ALERT "Parameter Index = %d\n", index);
	return 0;
}

// Module Unload Function
void ex02_module_param_exit(void)
{

	int index =0;
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	for(index = 0; index < count; index++)
		printk(KERN_ALERT "Good Bye Index = %d\n", index);
}
// Registering our load/unload function with Kernel
module_init(ex02_module_param_init);
module_exit(ex02_module_param_exit);
MODULE_LICENSE("GPL");
