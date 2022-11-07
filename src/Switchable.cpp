#include "Switchable.h"
#include <Arduino.h>

Switchable::Switchable(const int pin, const int channel) : m_pin(pin), m_channel(channel)
{
    // Set pin as output
    pinMode(m_pin, OUTPUT);
    ledcSetup(m_channel, 4000, 8);
    ledcAttachPin(m_pin, m_channel);
    // Start state if off
	off();
}

//turn on:
void Switchable::on()
{
	digitalWrite(m_pin, 1); //high
	m_state = true;
}

//turn off:
void Switchable::off()
{
	//digitalWrite(m_pin, 0); //low
    // set duty cycle to 0, the idle state will be low, to stop outputting a signal.
    ledcWrite(m_channel,0);
	m_state = false;
}

void Switchable::toggle()
{
	digitalWrite(m_pin, !m_state); //low
	m_state = !m_state;
}

// dim pin
void Switchable::dim(int dimVal)
{
    //analogWrite(m_pin, dimVal);
    ledcWrite(m_channel, dimVal);
}
		
bool Switchable::getState()
{
    return m_state;
}

void Switchable::setState(bool state)
{
    digitalWrite(m_pin, state);
    m_state = state;
}
