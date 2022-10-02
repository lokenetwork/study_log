#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x944af4ac, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x8ef52731, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x9d882c0, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x16f0355d, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x197c478a, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0xbb2bb984, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x4715f478, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x8fdf772a, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x7a83892f, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xdea31ab9, __VMLINUX_SYMBOL_STR(debugfs_remove_recursive) },
	{ 0x26948d96, __VMLINUX_SYMBOL_STR(copy_user_enhanced_fast_string) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x8c86479c, __VMLINUX_SYMBOL_STR(proc_remove) },
	{ 0xf69c5056, __VMLINUX_SYMBOL_STR(simple_attr_read) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xbce27e33, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xafb8c6ff, __VMLINUX_SYMBOL_STR(copy_user_generic_string) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xf0ca96da, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x85825898, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0xe32fa855, __VMLINUX_SYMBOL_STR(simple_attr_release) },
	{ 0x4f525275, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x72a98fdb, __VMLINUX_SYMBOL_STR(copy_user_generic_unrolled) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x419a2b83, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe545fbe1, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x754ea03f, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x2ea1373, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xe4d97eb7, __VMLINUX_SYMBOL_STR(simple_attr_open) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0x251f7fe8, __VMLINUX_SYMBOL_STR(simple_attr_write) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "3D5DCAF040745B52EE39AAF");
