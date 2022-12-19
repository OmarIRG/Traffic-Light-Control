/*
 * Led.h
 *
 * Created: 12/9/2022 10:34:47 PM
 *  Author: omars
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/Timer Driver/Timer.h"
#include "../../MCAL/Interrupt Driver/Interrupt.h"
#include "../../Utilities/Regesters.h"
#include "../../Utilities/Types.h"
#include "../../MCAL/DIO Driver/DIO.h"

/*
                                                                     Functions to make it easier to use  
*/

// all functions are void outputs

// Set the direction of led >> input or output
void Led_init(uint8_t led_Port , uint8_t Led_Pin); // takes led_port and Led_Pin


//  Initiate the led to make it on (lighted)
void Led_on(uint8_t led_Port , uint8_t Led_Pin); // takes led_port and Led_Pin


//  Initiate the led to make it off
void Led_off(uint8_t led_Port , uint8_t Led_Pin); // takes led_port and Led_Pin


//  Initiate the led to make it toggle (lighted and off)
void Led_toggle(uint8_t led_Port , uint8_t Led_Pin); // takes led_port and Led_Pin



#endif /* LED_H_ */