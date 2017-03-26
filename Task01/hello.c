#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#define AUTHOR "Nagesh"
#define DESC "A sample Driver"

static int __init hello2_init(void)
{
	printk(KERN_WARNING"hello!! world\n");
	return (0);
}

static void __exit hello2_cleanup(void)
{
	printk(KERN_WARNING"bye!! world\n");
}

module_init(hello2_init);
module_exit(hello2_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
