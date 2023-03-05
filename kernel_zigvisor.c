#include "zigvisor.h"
#include "stdio.h"
#include "linuxboot.h"
#include "stddef.h"
#include "bios.h"

int boot_zigvisor_kernel(void)
{
    struct linuxboot_args args = { 0 };
    struct zvisor_linuxboot_args *config_area;

    config_area = (struct zvisor_linuxboot_args *)0x30000;
    args.cmdline_size = config_area->cmdline_size;
    args.initrd_size = config_area->initrd_size;
    args.kernel_size = config_area->kernel_size;
    args.vmlinuz_size = args.kernel_size + config_area->setup_size;
    args.setup_addr = config_area->setup_addr;

    if (!parse_bzimage(&args)) {
        panic();
    }
    boot_bzimage(&args);
    return 0;
}
