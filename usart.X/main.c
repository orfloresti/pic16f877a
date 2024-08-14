/*
 * File:   main.c
 * Author: orfloresti
 *
 * Created on August 14, 2024, 12:22 AM
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "libs/uart/uart.h"
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
