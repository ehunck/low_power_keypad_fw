#include "mbed.h"
#include "keypad.h"
#include "password.h"


DigitalOut test_led(PC_13, 0);
KeyPad keypad;
Password password(keypad);

void TransitionStandby()
{
    test_led = 1;
    keypad.SetWakeUpMonitor();
    HAL_PWR_EnterSTOPMode( PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
    SetSysClock();
}

void PulseLED(int ms)
{
    test_led = 0;
    ThisThread::sleep_for(ms);
    test_led = 1;
    ThisThread::sleep_for(ms);
}

int main()
{
    PulseLED(1000); 
    while(1)
    {
        TransitionStandby();
        password.BlockForPassword("1234");
        if(password.IsTimedOut())
        {
            PulseLED(1000);
        }
        else if(password.IsPasswordCorrect())
        {
            for( int i = 0; i<5; i++)
            {
                PulseLED(100);
            }
        }
        else
        {
            for( int i = 0; i<2; i++)
            {
                PulseLED(100);
            }
        }
    }
}