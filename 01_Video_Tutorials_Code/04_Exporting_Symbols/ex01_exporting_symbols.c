#include<linux/init.h>
#include<linux/module.h>

// Exporting Global Variable
int count = 5;
EXPORT_SYMBOL(count);

// Function to be Exported
int ex01_exporting_function(void)
{
	printk(KERN_ALERT "Inside the %s Function\n", __FUNCTION__);
	return 0;
}

// Exporting Function
EXPORT_SYMBOL(ex01_exporting_function);

// Init Function
int ex01_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the %s Function\n", __FUNCTION__);
	return 0;
}
// Initialization Macro
module_init(ex01_simple_module_init);

// Exit Function
void ex01_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s Function\n", __FUNCTION__);
}
// Exit Macro
module_exit(ex01_simple_module_exit);

// Module License
MODULE_LICENSE("GPL");

