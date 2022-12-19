/*
 * led.c
 *
 * Created: 12/9/2022 10:35:01 PM
 *  Author: omars
 */ 



#include "led.h"


// Set the direction of led >> input or output

void Led_init(uint8_t led_Port , uint8_t Led_Pin){
	
	Dio_init(led_Port , Led_Pin , OUT); // Set direction of pin referred from led
	
}

//  Initiate the led to make it on (lighted)

void Led_on(uint8_t led_Port , uint8_t Led_Pin){
	
	Dio_Write(led_Port , Led_Pin , 1); // Set high in pin referred from led
	
}

//  Initiate the led to make it off

void Led_off(uint8_t led_Port , uint8_t Led_Pin){
	
	Dio_Write(led_Port , Led_Pin , 0); // Set low in pin referred from led
	
}

//  Initiate the led to make it toggle (lighted and off)

void Led_toggle(uint8_t led_Port , uint8_t Led_Pin){
	
	Dio_Toggle(led_Port, Led_Pin); // toggle pin referred from led
	
}

