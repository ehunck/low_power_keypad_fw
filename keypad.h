#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include "mbed.h"
#include "pins.h"

typedef enum
{
    KeyPress_None,
    KeyPress_1,
    KeyPress_2,
    KeyPress_3,
    KeyPress_4,
    KeyPress_5,
    KeyPress_6,
    KeyPress_7,
    KeyPress_8,
    KeyPress_9,
    KeyPress_STAR,
    KeyPress_0,
    KeyPress_POUND,
}KeyPress;

class KeyPad
{
public:
    KeyPad();
    ~KeyPad();

    KeyPress GetKey();
    void SetWakeUpMonitor();

private:
    void SetDefaultConfig();
    void DoNothing();

    DigitalIn col0;
    DigitalIn col1;
    DigitalIn col2;
    DigitalOut row0;
    DigitalOut row1;
    DigitalOut row2;
    DigitalOut row3;

    InterruptIn * wakeup;

};


#endif // _KEYPAD_H_