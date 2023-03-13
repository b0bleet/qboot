#ifndef KERNEL_ZIGVISOR_H
#define KERNEL_ZIGVISOR_H
#include "stdint.h"
#include "e820.h"

#define max_e820_entries 1

struct zvisor_linuxboot_args {
    uint32_t cmdline_size;
    uint32_t initrd_size;
    uint32_t kernel_size;
    uint32_t vmlinuz_size;
    uint32_t setup_size;
    uint32_t cpus_count;

    void *setup_addr;
    void *cmdline_addr;
    void *kernel_addr;
    void *initrd_addr;
    struct e820entry mem_map[max_e820_entries];
};

int boot_zigvisor_kernel(struct zvisor_linuxboot_args *config_area);

#endif
