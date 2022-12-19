/*
 * DIO.c
 *
 * Created: 12/5/2022 5:39:32 PM
 *  Author: omars
 */ 

#include "DIO.h"


//  Initiate any pin to use it as input or output
 
void Dio_init(uint8_t  Port_Letter , uint8_t  Pin_Number , uint8_t  Direction ){
	
	switch(Port_Letter)
	{
		case port_A:
		if(Direction == IN){
			DDRA |= (0<<Pin_Number);
			break;
		}
		else if (Direction == OUT)
		{
			DDRA |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		
		case port_B:
		if(Direction == IN){
			DDRB |= (0<<Pin_Number);
			break;
		}
		else if (Direction == OUT)
		{
			DDRB |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		case port_C:
		if(Direction == IN){
			DDRC |= (0<<Pin_Number);
			break;
		}
		else if (Direction == OUT)
		{
			DDRC |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		case port_D:
		if(Direction == IN){
			DDRD |= (0<<Pin_Number);
			break;
		}
		else if (Direction == OUT)
		{
			DDRD |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		
	}
	
	
	
	//  Initiate any pin to use it as high voltage or ground(low voltage)

}
void Dio_Write(uint8_t  Port_Letter , uint8_t  Pin_Number , uint8_t  value ){
	
	
	switch(Port_Letter)
	{
		case 'A' :
		if(value == LOW){
			PORTA &= ~(1<<Pin_Number);
			break;
		}
		else if (value == HIGH)
		{
			PORTA |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		
		case port_B:
		if(value == LOW){
			PORTB &= ~(1<<Pin_Number);
			break;
		}
		else if (value == HIGH)
		{
			PORTB |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		case port_C:
		if(value == LOW){
			PORTC &= ~(1<<Pin_Number);
			break;
		}
		else if (value == HIGH)
		{
			PORTC |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		case port_D:
		if(value == LOW){
			PORTD &= ~(1<<Pin_Number);
			break;
		}
		else if (value == HIGH)
		{
			PORTD |= (1<<Pin_Number);
			break;
		}
		else{
			break;
		}
		
		
	}
}
	//  read any pin state

	void Dio_read(uint8_t  Port_Letter , uint8_t  Pin_Number ,uint8_t *value ){
		
		
		switch(Port_Letter){
			
			case port_A:
			*value = (PINA & (1<<Pin_Number))>> Pin_Number;
			break;
			
			case port_C:
			*value = (PINC & (1<<Pin_Number))>> Pin_Number;
			break;
			
			case port_D:
			*value = (PIND & (1<<Pin_Number))>> Pin_Number;
			break;
			
			case port_B:
			*value = (PINB & (1<<Pin_Number))>> Pin_Number;
			break;
			
		}
		
		
		
		
		
	}
	
	// toggle any pin (low and high)
void Dio_Toggle(uint8_t  Port_Letter , uint8_t  Pin_Number)
{
	
	switch (Port_Letter)
	{
		case port_A:
		PORTA ^= (1<<Pin_Number);
		break;
		
		case port_B:
		PORTB ^=(1<<Pin_Number);
		break;
		
		case port_C:
		PORTC ^=(1<<Pin_Number);
		break;
		
		case port_D:
		PORTD ^=(1<<Pin_Number);
		break;
	}
	

}
	
	
	
	

