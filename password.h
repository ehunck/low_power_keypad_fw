#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#include "mbed.h"
#include <string>
#include "keypad.h"

class Password
{
public:
    Password(KeyPad& keypad);
    ~Password();

    void BlockForPassword(std::string password);
    bool IsTimedOut();
    bool IsPasswordCorrect();

private:
    KeyPress GetKeyReleased();
    KeyPress _prev_key;

    KeyPad& _keypad;

    bool _timed_out;
    bool _correct;

#if DEVICE_LPTICKER
    LowPowerTimer _timer;
#else
    Timer _timer;
#endif

};

#endif // _PASSWORD_H_