/*
 * File:   main.c
 * Author: orlan
 *
 * Created on 11 de octubre de 2022, 18:18
 */
#include <xc.h>
#include "configs.h"

#define _XTAL_FREQ 20000000

void main(void) {
    TRISB0 = 0x0;
    TRISA4 = 0x1;

    PORTBbits.RB0 = 0;
    PORTAbits.RA4 = 0;

    while (1) {
        if (PORTAbits.RA4 == 0) {
            __delay_ms(50);
            if (PORTAbits.RA4 == 0) {
                PORTBbits.RB0 = 1;
                __delay_ms(5);
                PORTBbits.RB0 = 0;
                __delay_ms(5000);
            }
        }
        
    }
}
