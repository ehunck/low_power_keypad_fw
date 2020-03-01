#include "password.h"

Password::Password(KeyPad& keypad) :
    _keypad(keypad),
    _timed_out( false ),
    _correct( false ),
    _prev_key(KeyPress_None)
{

}

Password::~Password()
{

}

void Password::BlockForPassword(std::string password)
{
    _timed_out = true;
    _correct = false;
    std::string password_attempt;

    bool entry_complete = false;
    _timer.start();
    _timer.reset();
    while( _timer.read_ms() < 90000 && !entry_complete )
    {
        KeyPress new_key = GetKeyReleased();
        wait_ms(10);
        if( new_key != KeyPress_None )
        {
            switch( new_key )
            {
                case KeyPress_0:
                    password_attempt.push_back('0');
                    break;
                case KeyPress_1:
                    password_attempt.push_back('1');
                    break;
                case KeyPress_2:
                    password_attempt.push_back('2');
                    break;
                case KeyPress_3:
                    password_attempt.push_back('3');
                    break;
                case KeyPress_4:
                    password_attempt.push_back('4');
                    break;
                case KeyPress_5:
                    password_attempt.push_back('5');
                    break;
                case KeyPress_6:
                    password_attempt.push_back('6');
                    break;
                case KeyPress_7:
                    password_attempt.push_back('7');
                    break;
                case KeyPress_8:
                    password_attempt.push_back('8');
                    break;
                case KeyPress_9:
                    password_attempt.push_back('9');
                    break;
                case KeyPress_POUND:
                    entry_complete = true;
                    _timed_out = false;
                    if(password_attempt == password)
                    {
                        _correct = true;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    _timer.stop();
}

bool Password::IsTimedOut()
{
    return _timed_out;
}

bool Password::IsPasswordCorrect()
{
    return _correct;
}

KeyPress Password::GetKeyReleased()
{
    bool key_change = false;
    KeyPress current_key = _keypad.GetKey();
    if( current_key != _prev_key )
    {
        key_change = true;
    }

    KeyPress return_key = KeyPress_None;
    if( key_change && current_key == KeyPress_None )
    {
        return_key = _prev_key;
    }
    _prev_key = current_key;

    return return_key;
}