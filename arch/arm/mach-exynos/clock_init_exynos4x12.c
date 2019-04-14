#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include <asm/arch/clock.h>
#include "common_setup.h"
#include "exynos4x12_setup.h"

void system_clock_init(void)
{
    volatile struct exynos4x12_clock *clk =
        (struct exynos4x12_clock *)samsung_get_base_clock();

    /*Setup 1: Set PLL locktime */
    writel(APLL_LOCKTIME, &clk->apll_lock);
    writel(MPLL_LOCKTIME, &clk->mpll_lock);
    writel(EPLL_LOCKTIME, &clk->epll_lock);
    writel(VPLL_LOCKTIME, &clk->vpll_lock);

    /*Setup 2: Set PLL config */
    writel(APLL_CON1_VAL, &clk->apll_con1);
    writel(APLL_CON0_VAL, &clk->apll_con0);
    writel(MPLL_CON1_VAL, &clk->mpll_con1);
    writel(MPLL_CON0_VAL, &clk->mpll_con0);
    writel(EPLL_CON1_VAL, &clk->epll_con1);
    writel(EPLL_CON0_VAL, &clk->epll_con0);
    writel(VPLL_CON1_VAL, &clk->vpll_con1);
    writel(VPLL_CON0_VAL, &clk->vpll_con0);

    /*Setup 3: Set DIV config */
    writel(CLK_DIV_CPU0_VAL, &clk->div_cpu0);
    writel(CLK_DIV_CPU1_VAL, &clk->div_cpu1);
    writel(CLK_DIV_DMC0_VAL, &clk->div_dmc0);
    writel(CLK_DIV_DMC1_VAL, &clk->div_dmc1);
    writel(CLK_DIV_TOP_VAL, &clk->div_top);
    writel(CLK_DIV_LEFTBUS_VAL, &clk->div_leftbus);
    writel(CLK_DIV_RIGHTBUS_VAL, &clk->div_rightbus);
    writel(CLK_DIV_FSYS1_VAL, &clk->div_fsys1);
    writel(CLK_DIV_FSYS2_VAL, &clk->div_fsys2);
    writel(CLK_DIV_FSYS3_VAL, &clk->div_fsys3);
    writel(CLK_DIV_PERIL0_VAL, &clk->div_peril0);
    writel(CLK_DIV_CAM_VAL, &clk->div_cam);
    writel(CLK_DIV_MFC_VAL, &clk->div_mfc);
    writel(CLK_DIV_G3D_VAL, &clk->div_g3d);
    writel(CLK_DIV_LCD0_VAL, &clk->div_lcd);

    /*Setuo 4: wait locktime */
    while(!(clk->apll_con0 & (1 << 29)));
    while(!(clk->mpll_con0 & (1 << 29)));
    while(!(clk->epll_con0 & (1 << 29)));
    while(!(clk->vpll_con0 & (1 << 29)));

    /*Setup 5: set MUX config */
    writel(CLK_SRC_CPU_VAL, &clk->src_cpu);
    writel(CLK_SRC_DMC_VAL, &clk->src_dmc);
    writel(CLK_SRC_TOP0_VAL, &clk->src_top0);
    writel(CLK_SRC_TOP1_VAL, &clk->src_top1);
    writel(CLK_SRC_LEFTBUS_VAL, &clk->src_leftbus);
    writel(CLK_SRC_RIGHTBUS_VAL, &clk->src_rightbus);
    writel(CLK_SRC_FSYS_VAL, &clk->src_fsys);
    writel(CLK_SRC_PERIL0_VAL, &clk->src_peril0);
    writel(CLK_SRC_CAM_VAL, &clk->src_cam);
    writel(CLK_SRC_MFC_VAL, &clk->src_mfc);
    writel(CLK_SRC_G3D_VAL, &clk->src_g3d);
    writel(CLK_SRC_LCD0_VAL, &clk->src_lcd);
}
