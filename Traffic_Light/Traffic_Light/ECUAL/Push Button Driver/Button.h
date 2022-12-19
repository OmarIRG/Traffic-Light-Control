/*
 * Button.h
 *
 * Created: 12/9/2022 11:12:56 PM
 *  Author: omars
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/Timer Driver/Timer.h"
#include "../../MCAL/Interrupt Driver/Interrupt.h"
#include "../../Utilities/Regesters.h"
#include "../../Utilities/Types.h"
#include "../../MCAL/DIO Driver/DIO.h"

/*
                                                                     Functions to make it easier to use  
*/

// all functions are void outputs

void Button_Init(uint8_t Button_Port , uint8_t Button_Pin); // Set the direction of button >> input or output // takes button port and pin

void Button_Read(uint8_t Button_Port , uint8_t Button_Pin , uint8_t *value); // read button state // takes button port and pin and read value

#endif /* BUTTON_H_ */