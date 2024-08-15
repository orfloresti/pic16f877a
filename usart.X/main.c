/*
 * File:   main.c
 * Author: orfloresti
 *
 * Created on August 14, 2024, 12:22 AM
 */

#include <xc.h>
#include "../lib/fuses.h"
#include "../lib/uart/uart.h"
#define _XTAL_FREQ 20000000

void main(void) {

    TRISAbits.TRISA4 = 0;
    PORTAbits.RA4 = 0;
    
    char flag_rx;
    
    UART_init();
    unsigned char* text = "Hello world \n\r";
    UART_printf(text);
    UART_printf("***************\n\r");
    UART_printf("0 - Led Off \n\r");
    UART_printf("1 - Led On \n\r");
    UART_printf("***************\n\r");
    
    while (1) {
        flag_rx = UART_read();
        if(flag_rx == '1') {
            UART_printf("LED On \n\r");
            PORTAbits.RA4 = 1;
        }
        
        if(flag_rx == '0') {
            UART_printf("LED Off \n\r");
            PORTAbits.RA4 = 0;
        }
    }

    return;
}
