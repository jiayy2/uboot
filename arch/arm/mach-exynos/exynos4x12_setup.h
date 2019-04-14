#ifndef _EXYNOS4X12_SETUP_H
#define _EXYNOS4X12_SETUP_H

#include <config.h>
#include <asm/arch/cpu.h>

/**
 * 时钟配置信息
 */
/* CLK_SRC_CPU */
#define MUX_MPLL_USER_SEL_C_FILPLL              0x0
#define MUX_MPLL_USER_SEL_C_MOUTMPLLFOUT        0x1
#define MUX_HPM_SEL_MOUTAPLL        0x0
#define MUX_HPM_SEL_SCLKMPLL        0x1
#define MUX_CORE_SEL_MOUTAPLL       0x0
#define MUX_CORE_SEL_SCLKMPLL       0x1
#define MUX_APLL_SEL_FILPLL             0x0
#define MUX_APLL_SEL_MOUTMPLLFOUT       0x1
#define CLK_SRC_CPU_VAL                 ((MUX_MPLL_USER_SEL_C_MOUTMPLLFOUT << 24) \
        | (MUX_HPM_SEL_MOUTAPLL << 20) \
        | (MUX_CORE_SEL_MOUTAPLL << 16) \
        | (MUX_APLL_SEL_MOUTMPLLFOUT << 0))


/* CLK_DIV_CPU0 */
#define CORE2_RATIO             0x0
#define APLL_RATIO              0x1
#define PCLK_DBG_RATIO          0x1
#define ATB_RATIO               0x4
#define PERIPH_RATIO            0x3
#define COREM1_RATIO            0x7
#define COREM0_RATIO            0x3
#define CORE_RATIO              0x0
#define CLK_DIV_CPU0_VAL       ((CORE2_RATIO << 28) \
        | (APLL_RATIO << 24) \
        | (PCLK_DBG_RATIO << 20) \
        | (ATB_RATIO << 16) \
        | (PERIPH_RATIO << 12) \
        | (COREM1_RATIO << 8) \
        | (COREM0_RATIO << 4) \
        | (CORE_RATIO << 0))

/* CLK_DIV_CPU1 */
#define CORES_TATIO             0x0
#define HPM_RATIO               0x0
#define COPY_RATIO              0x4
#define CLK_DIV_CPU1_VAL        ((CORES_TATIO << 8) \
        | (HPM_RATIO << 4) \
        | (COPY_RATIO))


/* CLK_SRC_DMC */
#define MUX_G2D_ACP_S_SEL_MOUTG2D_ACP_0         0x0
#define MUX_G2D_ACP_S_SEL_MOUTG2D_ACP_1         0x1
#define MUX_G2D_ACP_1_SEL_SCLKEPLL              0x0
#define MUX_G2D_ACP_1_SEL_SCLKVPLL              0x1
#define MUX_G2D_ACP_0_SEL_SCLKMPLL              0x0
#define MUX_G2D_ACP_0_SEL_SCLKAPLL              0x1
#define MUX_PWI_SEL_XXTI                0x0
#define MUX_PWI_SEL_XUSBXTI             0x1
#define MUX_PWI_SEL_SCLK_HDMI24M        0x2
#define MUX_PWI_SEL_SCLK_USBPHY0        0x3
#define MUX_PWI_SEL_SCLK_USBPHY1        0x4
#define MUX_PWI_SEL_SCLK_HDMIPHY        0x5
#define MUX_PWI_SEL_SCLKMPLL            0x6
#define MUX_PWI_SEL_SCLKEPLL            0x7
#define MUX_PWI_SEL_SCLKVPLL            0x8
#define MUX_MPLL_SEL_FINPL              0x0
#define MUX_MPLL_SEL_MOUTMPLLFOUT       0x1
#define MUX_DPHY_SEL_SCLKMPLL           0x0
#define MUX_DPHY_SEL_SCLKAPLL           0x1
#define MUX_DMC_BUS_SEL_SCLKMPLL        0x0
#define MUX_DMC_BUS_SEL_SCLKAPLL        0x1
#define MUX_C2C_SEL_SCLKMPLL    0x0
#define MUX_C2C_SEL_SCLKAPLL    0x1
#define CLK_SRC_DMC_VAL         ((MUX_G2D_ACP_S_SEL_MOUTG2D_ACP_0 << 28) \
        | (MUX_G2D_ACP_1_SEL_SCLKEPLL << 24) \
        | (MUX_G2D_ACP_0_SEL_SCLKMPLL << 20) \
        | (MUX_PWI_SEL_XUSBXTI << 16) \
        | (MUX_MPLL_SEL_MOUTMPLLFOUT << 12) \
        | (MUX_DPHY_SEL_SCLKMPLL << 8) \
        | (MUX_DMC_BUS_SEL_SCLKMPLL << 4) \
        | (MUX_C2C_SEL_SCLKMPLL << 0))

/* CLK_DIV_DMC0 */
#define DMCP_RATIO      0x1
#define DMCD_RATIO      0x1
#define DMC_RATIO       0x1
#define DPHY_RATIO      0x1
#define ACP_PCLK_RATIO  0x1
#define ACP_RATIO       0x3
#define CLK_DIV_DMC0_VAL        ((DMCP_RATIO << 20) \
        | (DMCD_RATIO << 16) \
        | (DMC_RATIO << 12) \
        | (DPHY_RATIO << 8) \
        | (ACP_PCLK_RATIO << 4) \
        | (ACP_RATIO << 0))


/* CLK_DIV_DMC1 */
#define DPM_RATIO               0x1
#define DVSEM_RATIO             0x1
#define C2C_ACLK_RATIO          0x1
#define PWI_RATIO       0x1
#define C2C_RATIO       0x1
#define G2D_ACP_RATIO   0x3
#define CLK_DIV_DMC1_VAL        ((DPM_RATIO << 24) \
        | (DVSEM_RATIO << 16) \
        | (C2C_ACLK_RATIO << 12) \
        | (PWI_RATIO << 8) \
        | (C2C_RATIO << 4) \
        | (G2D_ACP_RATIO << 0))

/* CLK_SRC_TOP0 */
#define MUX_ONENAND_SEL_ACLK_133	0x0
#define MUX_ONENAND_SEL_ACLK_160	0x1
#define MUX_ACLK_133_SEL_SCLKMPLL	0x0
#define MUX_ACLK_133_SEL_SCLKAPLL	0x1
#define MUX_ACLK_160_SEL_SCLKMPLL	0x0
#define MUX_ACLK_160_SEL_SCLKAPLL	0x1
#define MUX_ACLK_100_SEL_SCLKMPLL	0x0
#define MUX_ACLK_100_SEL_SCLKAPLL	0x1
#define MUX_ACLK_200_SEL_SCLKMPLL	0x0
#define MUX_ACLK_200_SEL_SCLKAPLL	0x1
#define MUX_VPLL_SEL_FINPLL		    0x0
#define MUX_VPLL_SEL_FOUTVPLL		0x1
#define MUX_EPLL_SEL_FINPLL		    0x0
#define MUX_EPLL_SEL_FOUTEPLL		0x1
#define MUX_ONENAND_1_SEL_MOUTONENAND	0x0
#define MUX_ONENAND_1_SEL_SCLKVPLL	0x1
#define CLK_SRC_TOP0_VAL		((MUX_ONENAND_SEL_ACLK_133 << 28) \
        | (MUX_ACLK_133_SEL_SCLKMPLL << 24) \
        | (MUX_ACLK_160_SEL_SCLKMPLL << 20) \
        | (MUX_ACLK_100_SEL_SCLKMPLL << 16) \
        | (MUX_ACLK_200_SEL_SCLKMPLL << 12) \
        | (MUX_VPLL_SEL_FOUTVPLL << 8) \
        | (MUX_EPLL_SEL_FOUTEPLL << 4) \
        | (MUX_ONENAND_1_SEL_MOUTONENAND << 0))

/* CLK_SRC_TOP1 */
#define MUX_ACLK_400_MCUISP_SUB_SEL_FINPLL                      0x0
#define MUX_ACLK_400_MCUISP_SUB_SEL_DIVOUT_ACLK_400_MCUISP      0x1
#define MUX_ACLK_200_SUB_SEL_FINPLL             0x0
#define MUX_ACLK_200_SUB_SELL_DIVOUT_ACLK_200   0x1
#define MUX_ACLK_266_GPS_SUB_SEL_FINPLL                 0x0
#define MUX_ACLK_266_GPS_SUB_SEL_DIVOUT_ACLK_266_GPS    0x1
#define MUX_MPLL_USER_SEL_T_FINPLL      0x0
#define MUX_MPLL_USER_SEL_T_SCLKMPLL    0x1
#define MUX_ACLK_400_MCUISP_SEL_SCLKMPLL_USER_T 0x0
#define MUX_ACLK_400_MCUISP_SEL_SCLKAPLL        0x1
#define MUX_ACLK_266_GPS_SELL_SCLKMPLL_USER_T   0x0
#define MUX_ACLK_266_GPS_SEL_SCLKAPPLL          0x1

#define CLK_SRC_TOP1_VAL    ((MUX_ACLK_400_MCUISP_SUB_SEL_DIVOUT_ACLK_400_MCUISP << 24) \
        | (MUX_ACLK_200_SUB_SELL_DIVOUT_ACLK_200 << 20) \
        | (MUX_ACLK_266_GPS_SUB_SEL_DIVOUT_ACLK_266_GPS << 16) \
        | (MUX_MPLL_USER_SEL_T_SCLKMPLL << 12) \
        | (MUX_ACLK_400_MCUISP_SEL_SCLKMPLL_USER_T << 8) \
        | (MUX_ACLK_266_GPS_SELL_SCLKMPLL_USER_T << 4))


/* CLK_DIV_TOP */
#define ACLK_400_MCUISP_RATIO   0x1
#define ACLK_266_GPS_RATIO      0x2
#define ONENAND_RATIO		0x0
#define ACLK_133_RATIO		0x5
#define ACLK_160_RATIO		0x4
#define ACLK_100_RATIO		0x7
#define ACLK_200_RATIO		0x3
#define CLK_DIV_TOP_VAL		((ACLK_400_MCUISP_RATIO << 24)  \
        | (ACLK_266_GPS_RATIO << 20) \
        | (ONENAND_RATIO << 16)	\
        | (ACLK_133_RATIO << 12)\
        | (ACLK_160_RATIO << 8)	\
        | (ACLK_100_RATIO << 4)	\
        | (ACLK_200_RATIO << 0))

/* CLK_SRC_LEFTBUS */
#define MUX_MPLL_USER_SEL_L_FINPLL      0x0
#define MUX_MPLL_USER_SEL_L_FOUTMPLL    0x1
#define MUX_GDL_SEL_SCLKMPLL	0x0
#define MUX_GDL_SEL_SCLKAPLL	0x1
#define CLK_SRC_LEFTBUS_VAL	(MUX_MPLL_USER_SEL_L_FOUTMPLL << 4)

/* CLK_DIV_LEFTBUS */
#define GPL_RATIO		0x1
#define GDL_RATIO		0x3
#define CLK_DIV_LEFTBUS_VAL	((GPL_RATIO << 4) | (GDL_RATIO))

/* CLK_SRC_RIGHTBUS */
#define MUX_MPLL_USER_SEL_R_FINPLL      0x0
#define MUX_MPLL_USER_SEL_R_FOUTMPLL    0x1
#define MUX_GDR_SEL_SCLKMPLL	0x0
#define MUX_GDR_SEL_SCLKAPLL	0x1
#define CLK_SRC_RIGHTBUS_VAL	(MUX_MPLL_USER_SEL_R_FOUTMPLL  << 4)

/* CLK_DIV_RIGHTBUS */
#define GPR_RATIO		0x1
#define GDR_RATIO		0x3
#define CLK_DIV_RIGHTBUS_VAL	((GPR_RATIO << 4) | (GDR_RATIO))

/* CLK_SRS_FSYS: 6 = SCLKMPLL */
#define SATA_SEL_SCLKMPLL	0
#define SATA_SEL_SCLKAPLL	1

#define MMC_SEL_XXTI		0
#define MMC_SEL_XUSBXTI		1
#define MMC_SEL_SCLK_HDMI24M	2
#define MMC_SEL_SCLK_USBPHY0	3
#define MMC_SEL_SCLK_USBPHY1	4
#define MMC_SEL_SCLK_HDMIPHY	5
#define MMC_SEL_SCLKMPLL	6
#define MMC_SEL_SCLKEPLL	7
#define MMC_SEL_SCLKVPLL	8

#define MMCC0_SEL		MMC_SEL_SCLKMPLL
#define MMCC1_SEL		MMC_SEL_SCLKMPLL
#define MMCC2_SEL		MMC_SEL_SCLKMPLL
#define MMCC3_SEL		MMC_SEL_SCLKMPLL
#define MMCC4_SEL		MMC_SEL_SCLKMPLL
#define CLK_SRC_FSYS_VAL	((SATA_SEL_SCLKMPLL << 24) \
        | (MMCC4_SEL << 16) \
        | (MMCC3_SEL << 12) \
        | (MMCC2_SEL << 8) \
        | (MMCC1_SEL << 4) \
        | (MMCC0_SEL << 0))

/* SCLK_MMC[0-4] = MOUTMMC[0-4]/(MMC[0-4]_RATIO + 1)/(MMC[0-4]_PRE_RATIO +1) */
/* CLK_DIV_FSYS1 */
#define MMC0_RATIO		    0x7
#define MMC0_PRE_RATIO		0x1
#define MMC1_RATIO		    0x7
#define MMC1_PRE_RATIO		0x1
#define CLK_DIV_FSYS1_VAL	((MMC1_PRE_RATIO << 24) \
        | (MMC1_RATIO << 16) \
        | (MMC0_PRE_RATIO << 8) \
        | (MMC0_RATIO << 0))

/* CLK_DIV_FSYS2 */
#define MMC2_RATIO		    0x7
#define MMC2_PRE_RATIO		0x1
#define MMC3_RATIO		    0x7
#define MMC3_PRE_RATIO		0x1
#define CLK_DIV_FSYS2_VAL	((MMC3_PRE_RATIO << 24) \
        | (MMC3_RATIO << 16) \
        | (MMC2_PRE_RATIO << 8) \
        | (MMC2_RATIO << 0))

/* CLK_DIV_FSYS3 */
#define MMC4_RATIO		    0x7
#define MMC4_PRE_RATIO		0x0
#define CLK_DIV_FSYS3_VAL	((MMC4_PRE_RATIO << 8) \
        | (MMC4_RATIO << 0))

/* CLK_SRC_PERIL0 */
#define UART_SEL_XXTI		0
#define UART_SEL_XUSBXTI	1
#define UART_SEL_SCLK_HDMI24M	2
#define UART_SEL_SCLK_USBPHY0	3
#define UART_SEL_SCLK_USBPHY1	4
#define UART_SEL_SCLK_HDMIPHY	5
#define UART_SEL_SCLKMPLL	6
#define UART_SEL_SCLKEPLL	7
#define UART_SEL_SCLKVPLL	8

#define UART0_SEL		UART_SEL_SCLKMPLL
#define UART1_SEL		UART_SEL_SCLKMPLL
#define UART2_SEL		UART_SEL_SCLKMPLL
#define UART3_SEL		UART_SEL_SCLKMPLL
#define UART4_SEL		UART_SEL_SCLKMPLL
#define CLK_SRC_PERIL0_VAL	((UART4_SEL << 16) \
        | (UART3_SEL << 12) \
        | (UART2_SEL << 8) \
        | (UART1_SEL << 4) \
        | (UART0_SEL << 0))

/* SCLK_UART[0-4] = MOUTUART[0-4]/(UART[0-4]_RATIO + 1) */
/* CLK_DIV_PERIL0 */
#define UART0_RATIO		7
#define UART1_RATIO		7
#define UART2_RATIO		7
#define UART3_RATIO		7
#define UART4_RATIO		7
#define CLK_DIV_PERIL0_VAL	((UART4_RATIO << 16) \
        | (UART3_RATIO << 12) \
        | (UART2_RATIO << 8) \
        | (UART1_RATIO << 4) \
        | (UART0_RATIO << 0))

/* Clock Source CAM/FIMC */
/* CLK_SRC_CAM */
#define CAM0_SEL_XUSBXTI	1
#define CAM1_SEL_XUSBXTI	1
#define CSIS0_SEL_XUSBXTI	1
#define CSIS1_SEL_XUSBXTI	1

#define FIMC_SEL_SCLKMPLL	6
#define FIMC0_LCLK_SEL		FIMC_SEL_SCLKMPLL
#define FIMC1_LCLK_SEL		FIMC_SEL_SCLKMPLL
#define FIMC2_LCLK_SEL		FIMC_SEL_SCLKMPLL
#define FIMC3_LCLK_SEL		FIMC_SEL_SCLKMPLL

#define CLK_SRC_CAM_VAL		((CSIS1_SEL_XUSBXTI << 28) \
        | (CSIS0_SEL_XUSBXTI << 24) \
        | (CAM1_SEL_XUSBXTI << 20) \
        | (CAM0_SEL_XUSBXTI << 16) \
        | (FIMC3_LCLK_SEL << 12) \
        | (FIMC2_LCLK_SEL << 8) \
        | (FIMC1_LCLK_SEL << 4) \
        | (FIMC0_LCLK_SEL << 0))

/* SCLK CAM */
/* CLK_DIV_CAM */
#define FIMC0_LCLK_RATIO	4
#define FIMC1_LCLK_RATIO	4
#define FIMC2_LCLK_RATIO	4
#define FIMC3_LCLK_RATIO	4
#define CLK_DIV_CAM_VAL		((FIMC3_LCLK_RATIO << 12) \
        | (FIMC2_LCLK_RATIO << 8) \
        | (FIMC1_LCLK_RATIO << 4) \
        | (FIMC0_LCLK_RATIO << 0))

/* SCLK MFC */
/* CLK_SRC_MFC */
#define MFC_SEL_MPLL		0
#define MOUTMFC_0		    0
#define MFC_SEL			    MOUTMFC_0
#define MFC_0_SEL		    MFC_SEL_MPLL
#define CLK_SRC_MFC_VAL		((MFC_SEL << 8) | (MFC_0_SEL))


/* CLK_DIV_MFC */
#define MFC_RATIO		    3
#define CLK_DIV_MFC_VAL		(MFC_RATIO)

/* SCLK G3D */
/* CLK_SRC_G3D */
#define G3D_SEL_MPLL		0
#define MOUTG3D_0		    0
#define G3D_SEL			    MOUTG3D_0
#define G3D_0_SEL		    G3D_SEL_MPLL
#define CLK_SRC_G3D_VAL		((G3D_SEL << 8) | (G3D_0_SEL))

/* CLK_DIV_G3D */
#define G3D_RATIO		    1
#define CLK_DIV_G3D_VAL		(G3D_RATIO)

/* SCLK LCD0 */
/* CLK_SRC_LCD0 */
#define FIMD_SEL_SCLKMPLL	    6
#define MDNIE0_SEL_XUSBXTI	    1
#define MDNIE_PWM0_SEL_XUSBXTI	1
#define MIPI0_SEL_XUSBXTI	    1
#define CLK_SRC_LCD0_VAL	((MIPI0_SEL_XUSBXTI << 12) \
        | (MDNIE_PWM0_SEL_XUSBXTI << 8) \
        | (MDNIE0_SEL_XUSBXTI << 4) \
        | (FIMD_SEL_SCLKMPLL << 0))

/* CLK_DIV_LCD0 */
#define FIMD0_RATIO		4
#define CLK_DIV_LCD0_VAL	(FIMD0_RATIO)

/* Required period to generate a stable clock output */
/* PLL_LOCK_TIME */
#define APLL_LOCKTIME		0x960
#define MPLL_LOCKTIME		0x190
#define EPLL_LOCKTIME		0xBB8
#define VPLL_LOCKTIME		0x190

/* PLL Values */
#define DISABLE			0
#define ENABLE			1
#define SET_PLL(mdiv, pdiv, sdiv)	((ENABLE << 31)\
        | (mdiv << 16) \
        | (pdiv << 8) \
        | (sdiv << 0))

/* APLL_CON0 */
#define APLL_MDIV		0x7D
#define APLL_PDIV		0x3
#define APLL_SDIV		0x0
#define APLL_CON0_VAL		SET_PLL(APLL_MDIV, APLL_PDIV, APLL_SDIV)

/* APLL_CON1 */
#define APLL_AFC_ENB		0x1
#define APLL_AFC		    0xC
#define APLL_CON1_VAL		((APLL_AFC_ENB << 31) | (APLL_AFC << 0))

/* MPLL_CON0 */
#define MPLL_MDIV		0x64
#define MPLL_PDIV		0x3
#define MPLL_SDIV		0x0
#define MPLL_CON0_VAL		SET_PLL(MPLL_MDIV, MPLL_PDIV, MPLL_SDIV)

/* MPLL_CON1 */
#define MPLL_AFC_ENB		0x0
#define MPLL_AFC		    0x1C
#define MPLL_CON1_VAL		((MPLL_AFC_ENB << 31) | (MPLL_AFC << 0))

/* EPLL_CON0 */
#define EPLL_MDIV		0x64
#define EPLL_PDIV		0x3
#define EPLL_SDIV		0x1
#define EPLL_CON0_VAL		SET_PLL(EPLL_MDIV, EPLL_PDIV, EPLL_SDIV)

/* EPLL_CON1 */
#define EPLL_K			    0x0
#define EPLL_CON1_VAL		(EPLL_K >> 0)

/* VPLL_CON0 */
#define VPLL_MDIV		    0x64
#define VPLL_PDIV		    0x3
#define VPLL_SDIV		    0x3
#define VPLL_CON0_VAL		SET_PLL(VPLL_MDIV, VPLL_PDIV, VPLL_SDIV)

/* VPLL_CON1 */
#define VPLL_SSCG_EN		    DISABLE
#define VPLL_SEL_PF_DN_SPREAD	0x0
#define VPLL_MRR		        0x11
#define VPLL_MFR		        0x0
#define VPLL_K			        0x0
#define VPLL_CON1_VAL		((VPLL_SSCG_EN << 31)\
        | (VPLL_SEL_PF_DN_SPREAD << 29) \
        | (VPLL_MRR << 24) \
        | (VPLL_MFR << 16) \
        | (VPLL_K << 0))


#endif
