#include<linux/init.h>
#include<linux/module.h>

extern int count;
// Function Prototype
int ex01_exporting_function(void);
// Init Function
int ex02_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the %s Function", __FUNCTION__);
	printk(KERN_ALERT "Exported Variable is %d", count);
	ex01_exporting_function();
	return 0;
}
// Initialization Macro
module_init(ex02_simple_module_init);

// Exit Function
void ex02_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s Function", __FUNCTION__);
}
// Exit Macro
module_exit(ex02_simple_module_exit);

// Module License
MODULE_LICENSE("GPL");

