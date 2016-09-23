/*
	Author	: Tarun Jain
	Email	: Tarun.Jain@iiitb.org
	Program	: Building Simple Module to Attach to Kernel
	Credits	: Linux Device Drivers Training Lectures at Youtube by Kartik M of embeddedgyan.com
*/

// Header Files
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>		/*For Character Driver Support*/

// Functions for File_operations
/*
	Arguments name
	File pointer is 'pfile'
	Inode pointer is 'pinode'
	__user is 'buffer'
	size_t is 'length'
	loff_t is 'offset'
*/
// Open Function
int ex01_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return 0; /*To indicate success*/
}

// Read Function
ssize_t ex01_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return 0; /*To indicate we have nothing to read - File is empty*/
}

// Write Function
ssize_t ex01_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return length; /*we are returning the length of buffer */
}

// Release/Close Function
int ex01_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	return 0; /*To indicate success*/
}

// To hold the file operations performed on this device
struct file_operations ex01_file_operations = {
	.owner		= THIS_MODULE,
	.open		= ex01_open,	
	.read		= ex01_read,
	.write		= ex01_write,
	.release	= ex01_close
};
// Module Load Function
int ex01_simple_module_init(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	/*Register with the kernel and indicate that we are registering the character device driver*/
	register_chrdev( 240 /*Major Number*/,
			"Simple Char Drv" /*Name of the Driver*/,
			&ex01_file_operations /*File Operations*/
			);
	return 0;
}

// Module Unload Function
void ex01_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);
	/*Unregister Character Device Driver*/
	unregister_chrdev(240, "Simple Char Drv");	/*Must have same values as in register function*/
}

// Registering our load/unload function with Kernel
module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
MODULE_LICENSE("GPL");
