/*
 * File:   main.c
 * Author: Orlando Flores Teomitzi 
 *
 * Created on July 25, 2020, 5:11 PM
 */

// PIC16F877A Configuration Bit Settings

// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#include <xc.h>
#define _XTAL_FREQ 20000000

#define IO_CONFIG TRISA
#define IO_STATUS PORTA

void main(void) {
    
    IO_CONFIG = 0x00;
    
    while(1) {
        IO_STATUS = 0xff;
        __delay_ms(1000);
        IO_STATUS = 0x00;
        __delay_ms(1000);
    }
    
}
