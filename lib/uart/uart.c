#include <xc.h>
#include "uart.h"

void UART_init() {
    TRISCbits.TRISC6 = 0; // TX output
    TRISCbits.TRISC7 = 1; // RX input
    TXSTAbits.SYNC = 0; // UART
    TXSTAbits.TX9 = 0; // 8 bits
    TXSTAbits.BRGH = 1; // High speed
    SPBRG = 129; // Value from table in data-sheet (p. 114)
    RCSTAbits.SPEN = 1; // UART on
    TXSTAbits.TXEN = 1; // Enable TX on
    RCSTAbits.CREN = 1; // Enable RX on
}

char UART_read() {
    if (PIR1bits.RCIF == 1) {
        return RCREG;
    } else {
        return 0;
    }
}

void UART_write(char data) {
    TXREG = data;
    while (TXSTAbits.TRMT == 0);
}

void UART_printf(unsigned char* text) {
    while (*text != 0x00) {
        UART_write(*text);
        text++;
    }
}