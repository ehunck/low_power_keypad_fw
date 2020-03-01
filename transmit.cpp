#include "transmit.h"

Modem::Modem():
rf_power(RF_POWER),
rf_transmit(RF_DATA)
{

}

Modem::~Modem()
{

}

void Modem::Send( const uint8_t * message, const uint32_t length )
{
    EnablePower();
    ThisThread::sleep_for( 1 );
    for( uint32_t i = 0; i < length; i ++ )
    {
        SendByte( message[i] );
    }
    ThisThread::sleep_for( 1 );
    DisablePower();
}

void Modem::EnablePower()
{
    // Turn power on
    rf_power = 1;
}

void Modem::DisablePower()
{
    // Turn power off
    rf_power = 0;
}

void Modem::SendByte( const uint8_t byte )
{
    for( int i = 0; i < 8; i ++ )
    {
        if( (byte >> i) & 0x01 )
        {
            LongPulse();
        }
        else
        {
            ShortPulse();
        }
    }
}

void Modem::LongPulse()
{
    rf_transmit = 1;
    wait_us(90);
    rf_transmit = 0;
    wait_us(10);
}

void Modem::ShortPulse()
{
    rf_transmit = 1;
    wait_us(10);
    rf_transmit = 0;
    wait_us(90);
}