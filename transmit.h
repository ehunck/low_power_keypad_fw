#ifndef __transmit_h__
#define __transmit_h__

#include "mbed.h"
#include "pins.h"

class Modem
{
public:
    Modem();
    virtual ~Modem();
    void Send( const uint8_t * message, const uint32_t length );

private:
    void EnablePower();
    void DisablePower();
    void SendByte( const uint8_t byte );
    void LongPulse();
    void ShortPulse();

    DigitalOut rf_power;
    DigitalOut rf_transmit;

};

#endif // __transmit_h__
