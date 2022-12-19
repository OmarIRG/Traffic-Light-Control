/*
 * Interrupt.c
 *
 * Created: 12/18/2022 12:00:43 AM
 *  Author: omars
 */ 

#include "Interrupt.h"
#include "../../Utilities/Regesters.h"

void Interrupt0_Init(void){
	sei();                                   //  Enable global interrupts
	MCUCR |= (1 << 0); MCUCR |= (0 << 1);            //  logical change
	GICR |= (1 << 6);                        //  Enable External Interrupt (INT0)
}

void Timer2_InT(void){
	TIMSK |= (1 << 6);                   // overflow interrupts in timer 2
}



