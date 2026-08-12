#include <reg51.h>

void main()
{
    unsigned long hex, decimal;
    unsigned int d1, d2, d3;

    hex = 0x123456;

    decimal = hex;

    d1 = decimal / 10000;
    decimal = decimal % 10000;

    d2 = decimal / 100;
    d3 = decimal % 100;

    P0 = d1;
    P1 = d2;
    P2 = d3;

    while(1);
}