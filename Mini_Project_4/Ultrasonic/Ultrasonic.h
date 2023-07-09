 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: Ultrasonic.h
 *
 * Description: Header file for the Ultrasonic driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/


#ifndef Ultrasonic_H_
#define Ultrasonic_H_

#include "std_types.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);



#endif