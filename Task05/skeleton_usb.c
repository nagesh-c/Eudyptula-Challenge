#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

#define AUTHOR "Nagesh"
#define DESC "An USB Driver"

static int skel_usb_probe(struct usb_interface *intf,
			  const struct usb_device_id *id)
{
	pr_alert("USB connected to system.\n");
	return (0);
}

static void skel_usb_disconnect(struct usb_interface *intf)
{
	pr_alert("USB disconnected from system.\n");
}

static const struct usb_device_id id_table[] = {
	{.driver_info = 42},
	{}
};

static struct usb_driver skel_usb_driver = {
	.name = "skeleton_usb_driver",
	.id_table = id_table,
	.probe = skel_usb_probe,
	.disconnect = skel_usb_disconnect,
};

static int __init usb_skel_init(void)
{
	int ret;

	pr_alert(KERN_WARNING"hello!! world\n");
	/* register this driver with USB subsystem. */
	ret = usb_register(&skel_usb_driver);
	if (ret)
		pr_alert("usb_register failed: %d\n", ret);

	return (0);
}

static void __exit usb_skel_cleanup(void)
{
	pr_alert(KERN_WARNING"bye!! world\n");
	/* deregister this driver from USB subsystem. */
	usb_deregister(&skel_usb_driver);
}

module_init(usb_skel_init);
module_exit(usb_skel_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
