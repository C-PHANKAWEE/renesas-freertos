/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name    : r_irq_rx_pinset.c
* Version      : 1.0.2
* Device(s)    : R5F565NEDxFP
* Tool-Chain   : RXC toolchain
* Description  : Setting of port and mpc registers
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_irq_rx_pinset.h"
#include "platform.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/***********************************************************************************************************************
* Function Name: R_ICU_PinSet
* Description  : This function initializes pins for r_irq_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

void R_ICU_PinSet()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);
    /* Set IRQ4 pin */
    PORTB.PMR.BYTE &= ~(1U<<1);
    PORTB.PDR.BYTE &= ~(1U<<1);
    MPC.PB1PFS.BYTE = 0x40U;
    /* Set IRQ5 pin */
    PORT1.PMR.BYTE &= ~(1U<<5);
    PORT1.PDR.BYTE &= ~(1U<<5);
    MPC.P15PFS.BYTE = 0x40U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

