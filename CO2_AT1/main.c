#include <REGX51.H>

sbit ABS_LED = P1^0;
sbit BRAKE_LED = P1^1;

unsigned char wheelSpeed = 80;
bit brakePressed = 0;

/* Timer0 Interrupt */
void timer0_ISR(void) interrupt 1
{
    if(wheelSpeed > 0)
        wheelSpeed--;

    TH0 = 0xFC;
    TL0 = 0x18;
}

/* External Interrupt 0 */
void brake_ISR(void) interrupt 0
{
    brakePressed = 1;
}

void timer0_init()
{
    TMOD = 0x01;

    TH0 = 0xFC;
    TL0 = 0x18;

    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void interrupt_init()
{
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

void main()
{
    timer0_init();
    interrupt_init();

    while(1)
    {
        if(brakePressed)
        {
            BRAKE_LED = 1;

            if(wheelSpeed < 30)
            {
                ABS_LED = 1;
            }
            else
            {
                ABS_LED = 0;
            }

            brakePressed = 0;
        }
        else
        {
            BRAKE_LED = 0;
        }
    }
}