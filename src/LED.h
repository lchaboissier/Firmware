#ifndef RGBLED_H
#define RGBLED_H

#include "Switchable.h"

class LED : public Switchable
{
	public:
		LED(const int pin, const int channel);
};

#endif //__LED_H
