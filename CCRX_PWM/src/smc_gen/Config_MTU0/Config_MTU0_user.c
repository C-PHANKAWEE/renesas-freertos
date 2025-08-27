/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU0_user.c
* Component Version: 1.12.0
* Device(s)        : R5F565NEDxFP
* Description      : This file implements device driver for Config_MTU0.
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
#include "Config_MTU0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
#define PRV_TICKS_PER_CYCLE    (_EA5F_TGRB0_VALUE + 1)
#define PRV_TICKS_DUTY_20_STEP ((PRV_TICKS_PER_CYCLE * 20) / 100)
#define PRV_TICKS_DUTY_20      (PRV_TICKS_PER_CYCLE - (PRV_TICKS_DUTY_20_STEP * 1) - 1)
#define PRV_TICKS_DUTY_80    (PRV_TICKS_PER_CYCLE - (PRV_TICKS_DUTY_20_STEP * 4) - 1)
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU0_Create_UserInit
* Description  : This function adds user code after initializing the MTU0 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU0_tgib0_interrupt
* Description  : This function is TGIB0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA210
#pragma interrupt r_Config_MTU0_tgib0_interrupt(vect=VECT(PERIA,INTA210),fint)
#else
#pragma interrupt r_Config_MTU0_tgib0_interrupt(vect=VECT(PERIA,INTA210))
#endif
static void r_Config_MTU0_tgib0_interrupt(void)
{
    /* Start user code for r_Config_MTU0_tgib0_interrupt. Do not edit comment generated here */
	if (MTU0.TGRC <= PRV_TICKS_DUTY_80)
	    {
	        /* Reset the duty cycle to 20% */
	        MTU0.TGRC = PRV_TICKS_DUTY_20;
	    }
	    else
	    {
	        /* Increase the duty cycle by 20 % */
	        MTU0.TGRC -= PRV_TICKS_DUTY_20_STEP;
	    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
