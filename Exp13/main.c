#include <reg51.h>

unsigned int arr[5] = {1000, 2000, 3000, 4000, 5000};
unsigned long sum;

void main()
{
    unsigned char i;

    sum = 0;

    for(i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    while(1);
}