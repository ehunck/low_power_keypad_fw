#include "keypad.h"

KeyPad::KeyPad() :
    col0(KEYPAD_5),
    col1(KEYPAD_6),
    col2(KEYPAD_7),
    row0(KEYPAD_1),
    row1(KEYPAD_2),
    row2(KEYPAD_3),
    row3(KEYPAD_4),
    wakeup(NULL)
{
    SetDefaultConfig();
}

KeyPad::~KeyPad()
{

}

KeyPress KeyPad::GetKey()
{
    SetDefaultConfig();

// Check row 0
    row0 = 1;
    row1 = 0;
    row2 = 0;
    row3 = 0;

    if( col0 )
    {
        SetDefaultConfig();
        return KeyPress_1;
    }
    else if( col1 )
    {
        SetDefaultConfig();
        return KeyPress_2;
    }
    else if( col2 )
    {
        SetDefaultConfig();
        return KeyPress_3;
    }

// Check row 1
    row0 = 0;
    row1 = 1;
    row2 = 0;
    row3 = 0;

    if( col0 )
    {
        SetDefaultConfig();
        return KeyPress_4;
    }
    else if( col1 )
    {
        SetDefaultConfig();
        return KeyPress_5;
    }
    else if( col2 )
    {
        SetDefaultConfig();
        return KeyPress_6;
    }

// Check row 2
    row0 = 0;
    row1 = 0;
    row2 = 1;
    row3 = 0;

    if( col0 )
    {
        SetDefaultConfig();
        return KeyPress_7;
    }
    else if( col1 )
    {
        SetDefaultConfig();
        return KeyPress_8;
    }
    else if( col2 )
    {
        SetDefaultConfig();
        return KeyPress_9;
    }

// Check row 3
    row0 = 0;
    row1 = 0;
    row2 = 0;
    row3 = 1;

    if( col0 )
    {
        SetDefaultConfig();
        return KeyPress_STAR;
    }
    else if( col1 )
    {
        SetDefaultConfig();
        return KeyPress_0;
    }
    else if( col2 )
    {
        SetDefaultConfig();
        return KeyPress_POUND;
    }
    SetDefaultConfig();
    return KeyPress_None;
}

void KeyPad::SetWakeUpMonitor()
{
    row0 = 0;
    row1 = 0;
    row2 = 0;
    row3 = 1;

    wakeup = new InterruptIn(KEYPAD_5, PullDown);
    wakeup->rise(callback(this, &KeyPad::DoNothing));
}

void KeyPad::SetDefaultConfig()
{
    if( wakeup )
    {
        delete wakeup;
        wakeup = NULL;
    }

    row0 = 0;
    row1 = 0;
    row2 = 0;
    row3 = 0;

    col0.mode(PullDown);
    col1.mode(PullDown);
    col2.mode(PullDown);
}

void KeyPad::DoNothing()
{

}