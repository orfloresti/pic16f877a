#ifndef _UART_H
#define	_UART_H
void UART_init();
char UART_read();
void UART_write(char data);
void UART_printf(unsigned char* text);
#endif

