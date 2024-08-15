/*
 * File:   main.c
 * Author: orfloresti
 *
 * Created on August 15, 2024, 5:58 PM
 */

#include <xc.h>
#include "../lib/fuses.h"
#include "../lib/uart/uart.h"
#define _XTAL_FREQ 20000000

void __interrupt() interrupts(void) {

    if (INTCONbits.INTF == 1) {
        UART_printf("External interrupt RB0 \n\r");
        INTCONbits.INTF = 0;
    } else if (PIR1bits.RCIF == 1) {
        char data = RCREG;
        UART_write(data);
        UART_printf("External interrupt USART RX \n\r");
        PIR1bits.RCIF = 0;
    }
}

void main(void) {

    UART_init();

    // More information in page 115 of data-sheet
    INTCONbits.GIE = 1; // Enable interrupts    
    INTCONbits.INTE = 1; // Enable external interrupt

    INTCONbits.PEIE = 1; // Enable internal interrupts
    PIE1bits.RCIE = 1; // Enable interrupt by serial recept

    OPTION_REGbits.INTEDG = 1; // Enable by low state

    while (1) {
        UART_printf("Message\n\r");
        __delay_ms(1000);
    }
}
