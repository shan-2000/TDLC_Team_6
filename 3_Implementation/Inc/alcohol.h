#ifndef ALCOHOL_H
#define ALCOHOL_H

#include "includes.h"
#define	ALSENS_PIN		 PD3

#define alcodet()			((ALSENS_PIN & _BV(ALSENS_PIN)) == 0)


void	AlcoSensInit	(void);

#endif