#ifndef _EXYNOS4X12_TOOLS_H_
#define _EXYNOS4X12_TOOLS_H_

#include <config.h>

/**
 * 代码优化级别
 */
#define optimize(grade) __attribute__((__optimize__("O"#grade)))
#define optimize0       optimize(0)
#define optimize1       optimize(1)
#define optimize2       optimize(2)
#define optimize3       optimize(3)


#if defined(CONFIG_ITOP4412)

/**
 * LED的GPIO
 */
#define     LED_GPIO_CON      (0x11000100)
#define     LED_GPIO_DATA     (0x11000104)
#define     LED_INDEX         (0x0)

/**
 * 打开LED灯
 * @return  0
 */
int std_lamp_on(void);


/**
 * 关闭LED灯
 * @return  0
 */
int std_lamp_off(void);

/**
 * 让灯闪烁
 * @param count 闪烁次数
 * @param time  闪烁间隔
 */
int std_lamp_flash(unsigned count, unsigned time);


/**
 * LED按预定频率闪烁
 * @return  0
 */
int std_lamp_preflash(void);
#endif


/**
 * 内存重置，向内存中写入给定数据，按四字节为单位
 * @param  addr  起始地址
 * @param  count 字节数
 * @param  data  需要写入的数据
 * @return       0
 */
int std_mem_reset(void *addr, unsigned count, unsigned data);


/**
 * 测试内存区域中的数据是否为给定值，返回不相等内存单元的个数
 * @param  addr  起始地址
 * @param  count 区域
 * @param  data  数据
 * @return       不等数据元素个数
 */

/**
 * 测试内存区域中的数据是否为给定值，按照四字节比对
 * @param  addr  起始地址
 * @param  count 内存单元数(单位字节）
 * @param  data  需要比对的数据(四个字节)
 * @return       不等单元的个数
 */
int std_mem_compare(void *addr, unsigned count, unsigned data);



/**
 * 调用IROM中的函数，拷贝启动介质中的数据到内存
 * @param  addr   内存起始地址
 * @param  offset 起始扇区号(从零开始编号)
 * @param  count  需要拷贝的扇区数
 * @return        成功返回零，失败返回-1
 *
 * 注意： 时钟必须配置为20Mhz，否则结果未知
 */
int std_mmc_read(void *addr, unsigned offset, unsigned count);

#endif
