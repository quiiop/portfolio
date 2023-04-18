#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>

#define MY_FILE "/home/kuo/Desktop/C/driver/file.txt"
#define DEMO_MAJOR 200
#define DEMO_NAME "demo"

static char DriverBuf[200]; 


static int demo_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "Character Driver : open successful \n");
    return 0;
}

static int demo_release(struct inode * inode, struct file *filp)
{
    printk(KERN_INFO "Character Driver : close successful \n");
    return 0;
}

ssize_t demo_read(struct file *filp, char __user *buf, size_t count, loff_t *offset)
{
    int ret;
    ret = copy_to_user(buf, DriverBuf, count);
    if (ret == 0) {
        printk(KERN_INFO "Character Driver : read successful\n");
    } else {
        printk(KERN_INFO "Character Driver : read failed \n");
    }
    return 0;
}

ssize_t demo_write(struct file *filp, const char __user *buf, size_t count, loff_t *offset)
{
    int ret = 0;
    ret = copy_from_user(DriverBuf, buf, count);
    if (ret == 0) {
        printk(KERN_INFO "Character Driver : write successful , %s\n",DriverBuf);
    } else{
         printk(KERN_INFO "Character Driver : write failed \n");
    }
    return 0;
}



struct file_operations demo_fops = {
    .owner = THIS_MODULE,
    .open = demo_open,
    .release = demo_release,
    .read = demo_read,
    .write = demo_write,
};

static int __init demo_init(void)
{
    int ret = 0;
    printk(KERN_INFO "demo init\n");
    ret = register_chrdev(DEMO_MAJOR, DEMO_NAME, &demo_fops);
    if (ret < 0) {
        printk(KERN_INFO "demo init failed \n");
    }
    return 0;
}

static void __exit demo_exit(void)
{
    printk(KERN_INFO "demo exit\n");
    unregister_chrdev(DEMO_MAJOR, DEMO_NAME);
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");
