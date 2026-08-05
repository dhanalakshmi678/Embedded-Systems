#include <reg51.h>

unsigned int num1 = 3000;
unsigned int num2 = 20;
unsigned long result;

void main()
{
    result = (unsigned long)num1 * num2;

    while(1);
}