#include <reg51.h>

void UART_Init(void)
{
    TMOD = 0x20;      // Timer 1, Mode 2
    TH1 = 0xFD;       // 9600 baud rate
    SCON = 0x50;      // Serial mode 1, 8-bit data
    TR1 = 1;          // Start Timer 1
}

void UART_Send(char ch)
{
    SBUF = ch;        // Put character into serial buffer
    while(TI == 0);   // Wait until transmission is complete
    TI = 0;           // Clear transmit flag
}

void UART_SendString(char *str)
{
    while(*str)
    {
        UART_Send(*str);
        str++;
    }
}

void main(void)
{
    UART_Init();

    UART_SendString("Hello World");

    while(1);
}