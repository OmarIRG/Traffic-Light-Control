/*
 * Button.c
 *
 * Created: 12/9/2022 11:12:39 PM
 *  Author: omars
 */ 


#include "Button.h"

// Set the direction of button >> input or output
void Button_Init(uint8_t Button_Port , uint8_t Button_Pin){
	
	Dio_init (Button_Port , Button_Pin , IN); // Set direction of pin referred from Button
	
}


// read button state
void Button_Read(uint8_t Button_Port , uint8_t Button_Pin , uint8_t *value){
	
	Dio_read (Button_Port , Button_Pin , value);   // read state of the pin referred from Button
	
}
