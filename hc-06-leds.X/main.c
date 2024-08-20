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
    char data_rx;
    
    TRISB = 0b11111110; // RB0,1,2 as output
    UART_init();
    __delay_ms(1000);
    
    while (1) {

        data_rx = UART_read();
        
        switch(data_rx){
            case '1': {
                PORTBbits.RB0 = 1;
                break;
            }
            case '2': {
                PORTBbits.RB0 = 0;
                break;
            }
        }
    }

    return;
}
