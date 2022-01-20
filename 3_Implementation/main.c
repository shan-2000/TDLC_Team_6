/*	Main.c: Application for drowsy driver detection	*/
/*	Written By	: Team 11		*/
#ifndef __AVR_ATmega32__
    #define __AVR_ATmega32__
#endif


#include "main.h"
#include "includes.h"

const char *MSG[] = { "Fire Detected",
					  "Alcohol Consumed by the driver",
					};

static void init(void) {
	Flags.Blink = FALSE;
	Flags.Meas = FALSE;
	buzinit();
	beep(2,100);
	ledinit();
	EyeBlinkInit();
	lcdinit();
	uartinit();
	tmr1init();
	tmr0init();
	motorinit();
	FireSensInit();
	//GSMinit();
	AlcoSensInit();
	rlyinit();
	//rlyon();
	disptitl();
	sei();
	sleep();
}
void ChkBlink(void) {
	if (Flags.Blink) {
		Flags.Blink = FALSE;
		lcdclrr(1);
		lcdws("Please Wake Up..");
		beep(5,100);
		dlyms(DISP_DLY);
		lcdclrr(1);
	}
}
void BlockSys(void) {
	lcdclrr(1);
	lcdws("****BLOCKED*****");
	ledon();
	cli();
	sleep();
	for(;;);
}
void ChkAlcohol(void){
	if (alcodet()) {
		lcdclrr(1);
		lcdws("Alcohol Detected");
		//rlyoff();
		beep(2,100);
		// GSMsndmsg(OPhNum, MSG[1]);
		 BlockSys();
	}
}
void ChkFire(void) {
	if (firedet()) {
		lcdclrr(1);
		lcdws(" Fire Detected");
		//rlyoff();
		beep(2,100);
		Mot1On();
		dlyms(2000);
		Mot1Off();
		// GSMsndmsg(OPhNum, MSG[0]);
		 BlockSys();
	}
}

void EyeBlinkInit(void) {
	EYEBLINK_SENS_DDR &= ~_BV(EYEBLINK_SENS_PIN);
	EYEBLINK_SENS_PORT |= _BV(EYEBLINK_SENS_PIN);
}
static void disptitl(void) {
	lcdclr();
	lcdws(" SMART VEHICLE");
}
static void tmr1init(void) {
	TCNT1H   = 225;					/* overflows at every 250msec */
	TCNT1L   = 123;
	TIMSK   |= _BV(TOIE1);			/* ENABLE OVERFLOW INTERRUPT */
	TCCR1A   = 0x00;
	TCCR1B  |= _BV(CS12);			 /* PRESCALAR BY 256 */
}
/* overflows at every 250msec */
ISR(TIMER1_OVF_vect) {
	static int8u i, j, k;
	TCNT1H   = 225;					/* overflows at every 250msec */
	TCNT1L   = 123;
	if (!Flags.Meas && ++j >= 4) {
		Flags.Meas = TRUE;
		j = 0;
	}
	if (++i >= 20)	i = 0;
	switch(i) {
		case 0: case 2: ledon(); break;
		case 1: case 3: ledoff(); break;
	}
	if (++k >= 8) 
		TCNT0 = k = 0;
	
	if (TCNT0 >= N_BLINKS) {
		Flags.Blink = TRUE;
		TCNT0 = k = 0;
	}
}
void tmr0init(void){
	TCNT0 = 0;
	TCCR0 |= _BV(CS02) | _BV(CS01);	/* EXTERNAL CLOCK */
}
int main(void) {
	init();
	while (TRUE) {
		if (Flags.Meas) {
			Flags.Meas = FALSE;
			ChkBlink();		
			ChkAlcohol();
			ChkFire();
		}
		sleep();
	}
	return 0;
}
