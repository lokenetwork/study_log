#include <asm/hwcap.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <asm/io.h>

#define rd_arm_reg(id) ({                                    \
              unsigned long __val;                            \
              asm("mrs %0, "#id : "=r" (__val));              \
              printk("%-20s: 0x%016lx\n", #id, __val);        \
      })
void ge_arm_sysregs(void)
{
      rd_arm_reg(ID_AA64ISAR0_EL1);
      rd_arm_reg(ID_AA64ISAR1_EL1);
      rd_arm_reg(ID_AA64MMFR0_EL1);
      rd_arm_reg(ID_AA64MMFR1_EL1);
      rd_arm_reg(ID_AA64PFR0_EL1);
      rd_arm_reg(ID_AA64PFR1_EL1);
      rd_arm_reg(ID_AA64DFR0_EL1);
      rd_arm_reg(ID_AA64DFR1_EL1);

      rd_arm_reg(MIDR_EL1);
      rd_arm_reg(MPIDR_EL1);
      rd_arm_reg(REVIDR_EL1);

      /* Unexposed register access causes SIGILL */
      rd_arm_reg(ID_MMFR0_EL1);
}

// switch JTAG signal for GDK8
#define GDK8_SYSCON_GRF_BASE    0xff100000
#define GDK8_SYSCON_GRF_SIZE    0x1000 // 1 page
#define RK3328_GRF_SOC_CON4		0x410
#define RK3328_GRF_GPIO1A_IOMUX 0x10

#define GRF_HIWORD_UPDATE(val, mask, shift) \
		((val) << (shift) | (mask) << ((shift) + 16))

int ge_arm_switch_jtag(int turn_on)
{
    int value;
    void* base = ioremap_nocache(GDK8_SYSCON_GRF_BASE, GDK8_SYSCON_GRF_SIZE);
    if (base == NULL) {
        printk(KERN_ERR "failed to map GRF memory at %x\n", GDK8_SYSCON_GRF_BASE);
        return -1;
    }
    value = readl(base + RK3328_GRF_SOC_CON4);
    printk("current value of SOC_CON4 = %x\n", value);
    value = GRF_HIWORD_UPDATE((turn_on == 0 ? 0 : 1), 1, 12);
    printk("value is set to = %x\n", value);
    writel(value, base + RK3328_GRF_SOC_CON4);
    value = readl(base + RK3328_GRF_SOC_CON4);
    printk("current value of SOC_CON4 = %x\n", value);
    //
    if(turn_on) 
    {
        value = readl(base + RK3328_GRF_GPIO1A_IOMUX);
        printk("current value of GPIO1A_IOMUX = %x\n", value);
        value = GRF_HIWORD_UPDATE(0, 1, 4); // bit 4 0
        value |= GRF_HIWORD_UPDATE(1, 1, 5); // bit 5 1
        value |= GRF_HIWORD_UPDATE(0, 1, 6); // bit 6 0
        value |= GRF_HIWORD_UPDATE(1, 1, 7); // bit 7 1
        printk("value is set to = %x\n", value);
        writel(value, base + RK3328_GRF_GPIO1A_IOMUX);
        value = readl(base + RK3328_GRF_GPIO1A_IOMUX);
        printk("current value of GPIO1A_IOMUX = %x\n", value);
    }
    iounmap(base);

    return 0;
}

#define GDK8_CRU_BASE 0xff440000
#define RK3328_CRU_CLKGATE_CON7 0x21c
int ge_arm_enable_jtag_clk(int turn_on)
{
    int value;
    void* base = ioremap_nocache(GDK8_CRU_BASE, GDK8_SYSCON_GRF_SIZE);
    if (base == NULL) {
        printk(KERN_ERR "failed to map CRU memory at %x\n", GDK8_CRU_BASE);
        return -1;
    }
    value = readl(base + RK3328_CRU_CLKGATE_CON7);
    printk("current value of CLKGATE_CON7 = %x\n", value);
    value = GRF_HIWORD_UPDATE((turn_on == 0 ? 1 : 0), 1, 2);
    printk("value is set to = %x\n", value);
    writel(value, base + RK3328_CRU_CLKGATE_CON7);
    value = readl(base + RK3328_CRU_CLKGATE_CON7);
    printk("current value of CLKGATE_CON7 = %x\n", value);

    iounmap(base);

    return 0;
}