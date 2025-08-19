/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_ICU_user.c
* Component Version: 2.3.0
* Device(s)        : R5F565NEDxFP
* Description      : This file implements device driver for Config_ICU.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_ICU.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern volatile uint32_t blinkDelay;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ICU_Create_UserInit
* Description  : This function adds user code after initializing the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq4_interrupt
* Description  : This function is IRQ4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ4
#pragma interrupt r_Config_ICU_irq4_interrupt(vect=VECT(ICU,IRQ4),fint)
#else
#pragma interrupt r_Config_ICU_irq4_interrupt(vect=VECT(ICU,IRQ4))
#endif
static void r_Config_ICU_irq4_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq4_interrupt. Do not edit comment generated here */
    switch (blinkDelay) {
    case 500:
        blinkDelay = 50; // Change blink delay to 50 milliseconds (on + off is 10Hz)
        break;
    case 50:
        blinkDelay = 500; // Change blink delay to 500 milliseconds (on + off is 1Hz)
        break;
    default:
        blinkDelay = 500; // Change blink delay back to 500 milliseconds (on + off is 1Hz)
        break;
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

