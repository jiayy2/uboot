#include <asm/arch/exynos4x12_tools.h>

#if defined(CONFIG_ITOP4412)
/**
 * 打开LED灯
 * @return  0
 */
int std_lamp_on(void)
{
    volatile unsigned *con = (unsigned *)LED_GPIO_CON;
    volatile unsigned *data = (unsigned *)LED_GPIO_DATA;

    *con &= ~(1 << (LED_INDEX * 4));
    *con |= (1 << (LED_INDEX * 4));

    *data |= (1 << LED_INDEX);

    return 0;
}

/**
 * 关闭LED灯
 * @return  0
 */
int std_lamp_off(void)
{
    volatile unsigned *con = (unsigned *)LED_GPIO_CON;
    volatile unsigned *data = (unsigned *)LED_GPIO_DATA;

    *con &= ~(1 << (LED_INDEX * 4));
    *con |= (1 << (LED_INDEX * 4));

    *data &= ~(1 << LED_INDEX);

    return 0;
}


/**
 * 让灯闪烁
 * @param count 闪烁次数
 * @param time  闪烁间隔
 */
optimize0 int std_lamp_flash(unsigned count, unsigned time)
{
    volatile unsigned delay;
    while(count--)
    {
        std_lamp_on();

        delay = time;
        while(delay--);

        std_lamp_off();

        delay = time;
        while(delay--);
    }

    return 0;
}


/**
 * LED按预定频率闪烁
 * @return  0
 */
int std_lamp_preflash(void)
{
    return std_lamp_flash(0x5, 0x5FFFF);
}

#endif

/**
 * 内存重置，向内存中写入给定数据，按四字节为单位
 * @param  addr  起始地址
 * @param  count 字节数
 * @param  data  需要写入的数据
 * @return       0
 */
optimize0 int std_mem_reset(void *addr, unsigned count, unsigned data)
{
    unsigned *buff = (unsigned *)addr;
    count /= 4;
    while(count--){
        *buff++ = data;
    }

    return 0;
}

/**
 * 测试内存区域中的数据是否为给定值，按照四字节比对
 * @param  addr  起始地址
 * @param  count 内存单元数(单位字节）
 * @param  data  需要比对的数据(四个字节)
 * @return       不等单元的个数
 */
optimize0 int std_mem_compare(void *addr, unsigned count, unsigned data)
{
    unsigned *buff = (unsigned *)addr;
    int ret = 0;
    count /= 4;
    while(count--)
    {
        if(*buff++ != data)
        {
            ++ret;
        }
    }
    return ret;
}

/**
 * 调用IROM中的函数，拷贝启动介质中的数据到内存
 * @param  addr   内存起始地址
 * @param  offset 起始扇区号(从零开始编号)
 * @param  count  需要拷贝的扇区数
 * @return        成功返回零，失败返回-1
 *
 * 注意： 时钟必须配置为20Mhz，否则结果未知
 */
int std_mmc_read(void *addr, unsigned offset, unsigned count)
{
    /**
     * 根据启动手册，得此函数
     */
    typedef int (*sdmmc_read_t)(unsigned, unsigned, void *);
    sdmmc_read_t read = *(sdmmc_read_t *)0x02020030;

    /*根据手册，须取反*/
    return !read(offset, count, addr);
}
