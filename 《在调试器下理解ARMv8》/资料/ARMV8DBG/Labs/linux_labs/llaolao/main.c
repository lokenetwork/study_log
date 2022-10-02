/*
 Example of a minimal character device driver 
 Usage examples:	
 kernel stack overflow:
 echo 200 > /sys/kernel/debug/llaolao/age
 
 Porbe
 echo probe > /proc/llaolao
  	
*/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/dcache.h>
#include <linux/debugfs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/timer.h>

#define DEVICE_NAME      "huadeng2"
#define MAJOR_NUM        88
#define NUM_DEVICES      6
#define DEV_DATA_LENGTH  100

static struct class *huadeng_class;
struct huadeng_dev {
  unsigned short current_pointer; /* Current pointer within the
                                     device data region */
  unsigned int size;              /* Size of the bank */
  int number;                     /* device number */
  struct cdev cdev;               /* The cdev structure */
  char name[10];                  /* Name of the device */
  char data[DEV_DATA_LENGTH];
  /* ... */                       /* Mutexes, spinlocks, wait
                                     queues, .. */
} *hd_devp[NUM_DEVICES];

struct lll_profile_struct {
    int             age;
    struct file *   file;
    // other stuffs
};

static struct proc_dir_entry *proc_lll_entry = NULL ;
int g_seed = 0;

// static varibales for debugfs
static struct dentry *df_dir = NULL, * df_dir;

static void wastestack(int recursive)
{
	int nothing;
	printk("wastestack %d\n",recursive);

	while(recursive--)
		wastestack(recursive);
}

long ge_probe_kernel_read(void *dst, const void *src, size_t size)
{
	long ret;
	mm_segment_t old_fs = get_fs();

	set_fs(KERNEL_DS);
	pagefault_disable();
	ret = __copy_from_user_inatomic(dst,
			(__force const void __user *)src, size);
	pagefault_enable();
	set_fs(old_fs);

	return ret ? -EFAULT : 0;
}

static void	ge_probe(void)
{
	char data[32] = {0};
	long addr = 0x880;

    long ret = ge_probe_kernel_read(data, addr, sizeof(data));
	printk("probe %lx got %ld\n", addr, ret);
}

static int
lll_age_set(void *data, u64 val)
{
    struct lll_profile_struct * lp = (struct lll_profile_struct *)data;
    lp->age = val;
	if(val==200)
		wastestack(val);

    return 0;
}
static int
lll_age_get(void *data, u64 *val)
{
    struct lll_profile_struct * lp = (struct lll_profile_struct *)data;
    *val = lp->age;

    return 0;
}

// macro from linux/fs.h
DEFINE_SIMPLE_ATTRIBUTE(df_age_fops, lll_age_get, lll_age_set, "%llu\n");

static ssize_t proc_lll_read(struct file *filp, char __user * buf, size_t count, loff_t * offp)
{
    int n = 0, ret;
    char secrets[100];

    printk(KERN_INFO "proc_lll_read is called file %p, buf %p count %d off %llx\n",
        filp, buf, count, *offp);
    sprintf(secrets, "kernel secrets balabala %s...\n", filp->f_path.dentry->d_iname);	

    n = strlen(secrets);
    if(*offp < n)
    {
	    copy_to_user(buf, secrets, n+1);
        *offp = n+1;
        ret = n+1;
    }
    else
        ret = 0;

    return ret; 
}
/* A timer list */
struct timer_list kt_timer;
 
/* Timer callback */
void ll_timer_callback(unsigned long arg)
{
    printk(KERN_INFO "Entering: %s\n", __FUNCTION__);
 
	*(int*)arg = 0xbad0bad0;
    //mod_timer(&kt_timer, jiffies + 10*HZ); /* restarting timer */
}

int ll_writenull_in_timer(void)
{
	/*init_timer(&kt_timer);
	kt_timer.function = ll_timer_callback;
	kt_timer.data = (unsigned long)0xbad;
	kt_timer.expires = jiffies + 5*HZ;  5 second

	add_timer(&kt_timer);// Starting the timer
*/
	printk(KERN_INFO "readnull_timer is started\n");
	return 0;
}

static ssize_t proc_lll_write(struct file *file, const char __user *buffer,
			 size_t count, loff_t *data)
{
    char cmd[100]={0x00};
	
    printk("proc_lll_write called legnth 0x%lx, %p\n", count, buffer);
    if (count < 1)
    {
       printk("count <=1\n");
       return -EBADMSG; /* runt */
    }
    if (count > sizeof(cmd))
    {
        printk("count > sizeof(cmd)\n");
        return -EFBIG;   /* too long */
    }

    if (copy_from_user(cmd, buffer, count))
        return -EFAULT;
    if(strncmp(cmd,"div0",4) == 0)
    {
		printk("going to divide %d/%d\n", g_seed, count-5);

        g_seed = g_seed/(count-5); 
    }
    else if(strncmp(cmd, "nullp", 5) == 0)
    {
        *(int*)(long)0x880 = 0x88888888;
    }
    else if(strncmp(cmd, "probe", 5) == 0)
    {
		ge_probe();
		ge_probe();
    }
    else if(strncmp(cmd,"timer0", 6) == 0)
	{
		ll_writenull_in_timer();
	}
	else
    {
        printk("unsupported cmd '%s'\n", cmd);
    }

    return count;	
}

static const struct file_operations proc_lll_fops = {
 .owner = THIS_MODULE,
 .read  = proc_lll_read,
 .write = proc_lll_write,
};

static int huadeng_open(struct inode *inode, struct file *file)
{
  struct huadeng_dev *hd_devp;
  pr_info("%s\n", __func__);

  /* Get the per-device structure that contains this cdev */
  hd_devp = container_of(inode->i_cdev, struct huadeng_dev, cdev);

  /* Easy access to cmos_devp from rest of the entry points */
  file->private_data = hd_devp;

  /* Initialize some fields */
  hd_devp->size = DEV_DATA_LENGTH;
  hd_devp->current_pointer = 0;

  return 0;
}

static int huadeng_release(struct inode *inode, struct file *file)
{
  struct huadeng_dev *hd_devp = file->private_data;
  pr_info("%s\n", __func__);

  /* Reset file pointer */
  hd_devp->current_pointer = 0;

  return 0;
}
int g_vfile_pecent = -1;

static ssize_t huadeng_read(struct file *file,
  char *buffer, size_t count, loff_t * offset)
{
  struct huadeng_dev *hd_devp = file->private_data;
  pr_info("%s %u, +%llx\n", __func__, count, *offset);

  if (*offset >= hd_devp->size) {
    return 0; /*EOF*/
  }
  /* Adjust count if its edges past the end of the data region */
  if (*offset + count > hd_devp->size) {
    count = hd_devp->size - *offset;
  }
  /* Copy the read bits to the user buffer */
  if (copy_to_user(buffer, (void *)(hd_devp->data + *offset), count) != 0) {
    return -EIO;
  }
    
  return count;
}


static ssize_t huadeng_write(struct file *file,
  const char *buffer, size_t length, loff_t * offset)
{
	int i;
	struct huadeng_dev *hd_devp = file->private_data;
	pr_info("%s %u +%llx\n", __func__, length, *offset);
	if(*offset >= hd_devp->size) {
		return 0;
	}  
	if (*offset + length > hd_devp->size) {
		length = hd_devp->size - *offset;
	}
	if(copy_from_user(hd_devp->data+*offset, buffer, length) !=0 ) {
		printk(KERN_ERR "copy_from_user failed\n");
		return -EFAULT;
	}  
	unsigned long percent = simple_strtoul(buffer, NULL, 0x10);

	printk("v_store: %s %d\n", buffer, length);
	for (i = 0; i < length; i++)
		printk(" %c ", buffer[i]);
	printk("\n");

	if (percent > 100)
		g_vfile_pecent = 100;
	else
		g_vfile_pecent = percent;

	//
	//	update the data buffer in dev's private data structure to ease geduers
	sprintf(hd_devp->data, "%d\%\n", g_vfile_pecent);
	//
 
	return length;
}

struct file_operations huadeng_fops = {
  .owner = THIS_MODULE,
  .open = huadeng_open,
  .release = huadeng_release,
  .read = huadeng_read,
  .write = huadeng_write,
};

static int __init llaolao_init(void)
{
    int n = 0x1937, ret = 0, i;
    static struct lll_profile_struct lll_profile;

    printk(KERN_INFO "Hi, I am llaolao at address: %p\n symbol: 0x%pF\n stack: 0x%p\n"
        " first 16 bytes: %*phC\n",
	    llaolao_init, llaolao_init, &n, 16, (char*)llaolao_init);
#ifdef CHRDRV_OLD_STYLE
    ret = register_chrdev(MAJOR_NUM, DEVICE_NAME, &huadeng_fops);
    if (ret != 0) {
        printk(KERN_ERR "register_chrdev failed %d\n", ret);
        return ret;
    }
#endif

    huadeng_class = class_create(THIS_MODULE, DEVICE_NAME);
    for (i = 0; i < NUM_DEVICES; i++) {
        /* Allocate memory for the per-device structure */
        hd_devp[i] = kmalloc(sizeof(struct huadeng_dev), GFP_KERNEL);
        if (!hd_devp[i]) {
            printk("allocate huadeng dev struct failed\n"); 
            return -ENOMEM;
        }
        /* Connect the file operations with the cdev */
        cdev_init(&hd_devp[i]->cdev, &huadeng_fops);
        hd_devp[i]->cdev.owner = THIS_MODULE;

        /* Connect the major/minor number to the cdev */
        ret = cdev_add(&hd_devp[i]->cdev, MKDEV(MAJOR_NUM, i), 1);
        if (ret) {
          printk(KERN_ERR "cdev_add failed for %d\n", i);
          return ret;
        }

        /* Send uevents to udev, so it'll create /dev nodes */
        device_create(huadeng_class, NULL,
            MKDEV(MAJOR_NUM, i), NULL, "huadeng%d", i);
    }

    /* Create /proc/llaolao */
    proc_lll_entry = proc_create("llaolao", 0, NULL, &proc_lll_fops);
    if (proc_lll_entry == NULL) {
        printk(KERN_ERR "create proc entry failed\n");
        return -1;
    }
    df_dir = debugfs_create_dir("llaolao", 0);
    if(!df_dir)
    {
        printk(KERN_ERR "create dir under debugfs failed\n");
        return -1;
    }

    debugfs_create_file("age", 0222, df_dir, &lll_profile, &df_age_fops);

    return 0;
}

static void __exit llaolao_exit(void)
{
    int i;
    printk("Exiting from 0x%p... Bye, GEDU friends\n", llaolao_exit);
    if(proc_lll_entry)
        proc_remove(proc_lll_entry);
    if(df_dir)
      // clean up all debugfs entries
      debugfs_remove_recursive(df_dir);
    if(huadeng_class) {
        for (i = 0; i < NUM_DEVICES; i++) {
            device_destroy(huadeng_class, MKDEV(MAJOR_NUM, i));
            cdev_del(&hd_devp[i]->cdev);
            kfree(hd_devp[i]);
        }
        class_destroy(huadeng_class);
#ifdef CHRDRV_OLD_STYLE
        unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
#endif
    }

    printk(KERN_EMERG "Testing message with KERN_EMERG severity level\n");
    printk(KERN_ALERT "Testing message with KERN_ALERT severity level\n");
    printk(KERN_CRIT "Testing message with KERN_CRIT severity level\n");
    printk(KERN_ERR "Testing message with KERN_ERR severity level\n");
    printk(KERN_WARNING "Testing message with KERN_WARNING severity level\n");
    printk(KERN_NOTICE "Testing message with KERN_NOTICE severity level\n");
    printk(KERN_INFO "Testing message with KERN_INFO severity level\n");
    printk(KERN_DEBUG "Testing message with KERN_DEBUG severity level\n");
}

module_init(llaolao_init);
module_exit(llaolao_exit);

MODULE_AUTHOR("GEDU lab");
MODULE_DESCRIPTION("LKM example - llaolao");
MODULE_LICENSE("GPL");
