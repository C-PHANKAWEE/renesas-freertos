#include <stdio.h>              // For sprintf
#include "platform.h"           // Located in the FIT BSP module
#include "r_sci_rx_if.h"        // The SCI module API interface file.
#include "r_byteq_if.h"         // The BYTEQ module API interface file.
#include "r_sci_rx_config.h"    // User configurable options for the SCI module
#include "r_sci_rx_pinset.h"
#include "r_smc_entry.h"

/*****************************************************************************
Private global variables and functions
******************************************************************************/
void my_sci_callback(void *pArgs);

/* Handle storage. Needs to persist as long as SCI calls are going to be made.*/
static sci_hdl_t   g_my_sci_handle;

/*****************************************************************************
* Function Name: main()
* Description  : Main loop for demo.
* Arguments    : none
* Return Value : none
******************************************************************************/
void main(void)
{
    sci_cfg_t   my_sci_config;
    sci_err_t   my_sci_err;
    uint32_t    my_version;
    uint8_t     my_char;
    uint8_t version_str[12] = {0};

    /* Set up the configuration data structure for asynchronous (UART) operation. */
    my_sci_config.async.baud_rate    = 115200;
    my_sci_config.async.clk_src      = SCI_CLK_INT;
    my_sci_config.async.data_size    = SCI_DATA_8BIT;
    my_sci_config.async.parity_en    = SCI_PARITY_OFF;
    my_sci_config.async.parity_type  = SCI_EVEN_PARITY;
    my_sci_config.async.stop_bits    = SCI_STOPBITS_1;
    my_sci_config.async.int_priority = 3;    // 1=lowest, 15=highest

    /* OPEN ASYNC CHANNEL
     *  Provide address of the config structure,
     *  the callback function to be assigned,
     *  and the location for the handle to be stored.*/
    my_sci_err = R_SCI_Open(SCI_CH1, SCI_MODE_ASYNC, &my_sci_config, my_sci_callback, &g_my_sci_handle);

    /* If there were an error this would demonstrate error detection of API calls. */
    if (SCI_SUCCESS != my_sci_err)
    {
        R_BSP_NOP(); // Your error handling code would go here.
    }

    /* Initialize the I/O port pins for communication on this SCI channel.
     * This is specific to the MCU and ports chosen. For the RSKRX65N we will use the
     * SCI channel connected to the USB serial port emulation. */
    R_SCI_PinSet_SCI1();

    /* Get module software version using the API function provided. */
    my_version = R_SCI_GetVersion();

    /* Demonstrate parsing and formatting of version number. */
    sprintf((char *)version_str, "SCIv%1.0hu.%2.2hu\r\n", ((my_version >> 16)&0xf), (my_version & 0xff));

    /* Print out to virtual debug console*/
	printf("Initializes the SCI successfully\n%s",version_str);

    /* Wait to get a character from the terminal so we know that it is ready. */
    do
    {
        my_sci_err = R_SCI_Receive(g_my_sci_handle, &my_char, 1);
    } while (SCI_ERR_INSUFFICIENT_DATA == my_sci_err);

    /* Now send the version string out through the serial port to the terminal. */
    R_SCI_Send(g_my_sci_handle, version_str, 10);

    /* Repeat forever. */
    while(1)
    {
        /* Read next character from the serial port receive queue.
         * Repeat read if needed until data is available in the queue. */
        do
        {
            my_sci_err = R_SCI_Receive(g_my_sci_handle, &my_char, 1);
        } while (SCI_ERR_INSUFFICIENT_DATA == my_sci_err);

        /* Print out to virtual debug console */
		printf("%c\n",(char)(my_char));
		R_SCI_Send(g_my_sci_handle, "\nMessage Received : ", 20);
        /* Echo 1 character of the received data back to the sender. */
        R_SCI_Send(g_my_sci_handle, &my_char, 1);
    }

} /* End of function main. */

/*****************************************************************************
* Function Name: my_sci_callback
* Description  : This is a template for an SCI Async Mode callback function.
* Arguments    : pArgs -
*                    pointer to sci_cb_args_t structure cast to a void. Structure
*                    contains event and associated data.
* Return Value : none
******************************************************************************/
void my_sci_callback(void *pArgs)
{
sci_cb_args_t   *args;

    args = (sci_cb_args_t *)pArgs;

    if (args->event == SCI_EVT_RX_CHAR)
    {
        /* From RXI interrupt; received character data is in args->byte */
    	PIN_WRITE(LED0) = ~PIN_READ(LED0);       // Toggle LED to demonstrate callback execution.
        R_BSP_NOP();
    }
    else if (args->event == SCI_EVT_RXBUF_OVFL)
    {
        /* From RXI interrupt; rx queue is full; 'lost' data is in args->byte
           You will need to increase buffer size or reduce baud rate */
    	R_BSP_NOP();
    }
    else if (args->event == SCI_EVT_OVFL_ERR)
    {
        /* From receiver overflow error interrupt; error data is in args->byte
           Error condition is cleared in calling interrupt routine */
    	R_BSP_NOP();
    }
    else if (args->event == SCI_EVT_FRAMING_ERR)
    {
        /* From receiver framing error interrupt; error data is in args->byte
           Error condition is cleared in calling interrupt routine */
    	R_BSP_NOP();
    }
    else if (args->event == SCI_EVT_PARITY_ERR)
    {
        /* From receiver parity error interrupt; error data is in args->byte
           Error condition is cleared in calling interrupt routine */
    	R_BSP_NOP();
    }
}
