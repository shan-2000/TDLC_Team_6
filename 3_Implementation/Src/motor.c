#include "motor.h"

void motorinit(void) {
	MOT_DDR	|= _BV(MOT1_AN) | _BV(MOT1_CA) | _BV(MOT2_AN) | _BV(MOT2_CA);
	MOT_PORT	&= ~(_BV(MOT1_AN) | _BV(MOT1_CA) | _BV(MOT2_AN) | _BV(MOT2_CA));
}
void  Mot1Clk(void) {
	MOT_PORT |= _BV(MOT1_AN);
	MOT_PORT &= ~_BV(MOT1_CA);
}
void Mot1Aclk(void) {
	MOT_PORT |= _BV(MOT1_CA);
	MOT_PORT &= ~_BV(MOT1_AN);
}
void  Mot2Clk(void) {
	MOT_PORT |= _BV(MOT2_AN);
	MOT_PORT &= ~_BV(MOT2_CA);
}
void Mot2Aclk(void) {
	MOT_PORT |= _BV(MOT2_CA);
	MOT_PORT &= ~_BV(MOT2_AN);
}
void MotStop(void) {
	MOT_PORT &= ~(_BV(MOT1_AN) | _BV(MOT1_CA));
}
void Forward(void) {
	Mot1Clk();
	Mot2Aclk();
}
void Backward(void) {
	Mot1Aclk();
	Mot2Clk();
}
void Right(void) {
	Mot1Clk();
	Mot2Clk();
}
void Left(void) {
	Mot1Aclk();
	Mot2Aclk();
}
void Stop(void) {
	MOT_PORT &= ~(_BV(MOT1_AN) | _BV(MOT1_CA));
	MOT_PORT &= ~(_BV(MOT2_AN) | _BV(MOT2_CA));
}