/*
 * Regesters.h
 *
 * Created: 12/9/2022 9:02:05 PM
 *  Author: omars
 */ 


#ifndef REGESTERS_H_
#define REGESTERS_H_

#include "Types.h"

//                     Registers

/*
Define any register By getting it's address
*/

/*
Port A has 3 Registers 
*/

#define PORTA *((volatile uint8_t *)0x3B)   // 8 bit register
#define DDRA *((volatile uint8_t *)0x3A)    // 8 bit register
#define PINA *((volatile uint8_t *)0x39)    // 8 bit register

/*
Port B has  3 Registers
*/

#define PORTB *((volatile uint8_t *)0x38)  // 8 bit register
#define DDRB *((volatile uint8_t *)0x37)  // 8 bit register
#define PINB *((volatile uint8_t *)0x36)  // 8 bit register

/*
Port C has  3 Registers
*/

#define PORTC *((volatile uint8_t *)0x35)  // 8 bit register
#define DDRC *((volatile uint8_t *)0x34)  // 8 bit register
#define PINC *((volatile uint8_t *)0x33)  // 8 bit register

/*
Port D has  3 Registers
*/

#define PORTD *((volatile uint8_t *)0x32)  // 8 bit register
#define DDRD *((volatile uint8_t *)0x31)  // 8 bit register
#define PIND *((volatile uint8_t *)0x30)  // 8 bit register

/*
Timer 0 Registers
*/

#define TCCR0  *((volatile uint8_t*)0x53) // 8 bit register
#define TCNT0  *((volatile uint8_t*)0x52) // 8 bit register
#define TIFR   *((volatile uint8_t*)0x58) // 8 bit register


/*
Timer 2 Registers
*/

#define TCNT2  *((volatile uint8_t*)0x44) // 8 bit register
#define TCCR2  *((volatile uint8_t*)0x45) // 8 bit register

/*
Interrupt Registers
*/

#define MCUCR	*((volatile uint8_t*)0x55) // 8 bit register
#define GICR	*((volatile uint8_t*)0x5B) // 8 bit register
#define TIMSK	*((volatile uint8_t*)0x59) // 8 bit register

#endif /* REGESTERS_H_ */