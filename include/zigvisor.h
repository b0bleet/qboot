#ifndef KERNEL_ZIGVISOR_H
#define KERNEL_ZIGVISOR_H
#include "stdint.h"
struct zvisor_linuxboot_args {
    uint32_t cmdline_size;
    uint32_t initrd_size;
    uint32_t kernel_size;
    uint32_t vmlinuz_size;
    uint32_t setup_size;

    void *setup_addr;
    void *cmdline_addr;
    void *kernel_addr;

};

int boot_zigvisor_kernel(void);

#endif
