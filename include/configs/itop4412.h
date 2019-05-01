#ifndef __CONFIG_ITOP4412_H
#define __CONFIG_ITOP4412_H

#include <configs/exynos4-common.h>

/**
 * 内存相关的配置
 */
#define CONFIG_SDRAM_SIZE       2   /*1G，则为1，2G，则为2*/

/* itop4412 has 4 bank of DRAM */
#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM_1			    CONFIG_SYS_SDRAM_BASE

/*mem size*/
#define CONFIG_NR_DRAM_BANKS        4
#if CONFIG_SDRAM_SIZE == 1
#define SDRAM_BANK_SIZE				(256 << 20)	/* 256 MB */
#else
#define SDRAM_BANK_SIZE				(512 << 20)	/* 512 MB */
#endif

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START    CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x6000000)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x3E00000)

/*隐藏顶部*/
#define CONFIG_SYS_MEM_TOP_HIDE     (1 << 20)

/*stack*/
#define CONFIG_SYS_INIT_SP_ADDR		0x02040000

/*SDRAM init*/
#define CONFIG_MIU_4KBIT_INTERLEAVED
#define DRAM_CLK_400


/**
 * 环境变量相关的配置
 */
#define CONFIG_ENV_SIZE             (16 << 10) /* 16k */
#define CONFIG_SYS_MMC_ENV_DEV		0


/**
 * SPL相关配置信息
 */
#define CONFIG_EXYNOS4X12		1
#define CONFIG_ITOP4412			1

/*SPL代码段基地址*/
#define CONFIG_SPL_TEXT_BASE	0x02023400

/*组件大小*/
#define CONFIG_SPL_MAX_FOOTPRINT	(14 * 1024)
#define BL1_SIZE					((8 << 10))		/* 8K */
#define BL2_SIZE 					((16 << 10))	/* 16K */
#define UBOOT_SIZE					((300 << 10))	/* 300K */

/* U-BOOT位置 */
#define BL2_START_OFFSET		((512 + BL1_SIZE + BL2_SIZE)/512)
#define BL2_SIZE_BLOC_COUNT		((UBOOT_SIZE / 512))

/* Power Down Modes */
#define S5P_CHECK_SLEEP			0x00000BAD
#define S5P_CHECK_DIDLE			0xBAD00000
#define S5P_CHECK_LPA			0xABAD0000

/**
 * 启动USB支持
 */
#define CONFIG_USB_EHCI_EXYNOS

#endif	/* __CONFIG_H */
