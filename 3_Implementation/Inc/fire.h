#ifndef FIRE_SENSOR_H
#define FIRE_SENSOR_H

#include "includes.h"

#define	FIRE_SENS_PIN			PD2

#define firedet()			(FIRE_SENS_PIN & _BV(FIRE_SENS_PIN))

void	FireSensInit(void);

#endif