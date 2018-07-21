#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/hid.h>

#define AUTHOR		"3adf6a67133f"
#define LICENSE		"GPL v2"
#define DESCRIPTION	"An USB Driver"

/*
 * HID: Human Interface Device: Keyboard and Mouse
 * USB_INTERFACE_INFO is a macro, which takes 3 parameter.
 * a) class b) subclass c) device, and assign them to a
 * structure members.
 */
static const struct usb_device_id id_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
			    USB_INTERFACE_SUBCLASS_BOOT,
			    USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{}
};

MODULE_DEVICE_TABLE(usb, id_table);

static int __init usb_skel_init(void)
{
	pr_alert("hello!! world\n");
	return (0);
}

static void __exit usb_skel_cleanup(void)
{
	pr_alert("bye!! world\n");
}

module_init(usb_skel_init);
module_exit(usb_skel_cleanup);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
