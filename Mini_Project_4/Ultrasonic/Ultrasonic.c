 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: Ultrasonic.c
 *
 * Description: Source file for the Ultrasonic driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/

#include "gpio.h"
#include "icu.h"
#include "Ultrasonic.h"
#include "common_macros.h" 
#include "avr/io.h"
#include "avr/delay.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
void Ultrasonic_init(void)
{
	Icu_ConfigType Icu_Config = {F_CPU_8,RISING};
	SREG |= (1<<7);
	Icu_init(&Icu_Config);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
	uint16 u16_Distance;
	uint16 u16_PulseWidth;
	Ultrasonic_Trigger();
	u16_PulseWidth = Icu_getInputCaptureValue();
	Icu_clearTimerValue();
	u16_Distance=(uint16)((float)((uint32)u16_PulseWidth*34000)/2000000);
	return u16_Distance;
}
void Ultrasonic_edgeProcessing(void)
{
	Icu_setEdgeDetectionType(FALLING);
}
