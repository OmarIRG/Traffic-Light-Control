/*
 * Interrupt.h
 *
 * Created: 12/18/2022 12:01:29 AM
 *  Author: omars
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// External interrupt INT0
#define INT_0       __vector_1

// timer 2 interrupt
#define TIMER2_OVF		__vector_5

// Set Global Interrupts
#define  sei() __asm__ __volatile__ ("sei" ::: "memory")


// Clear Global Interrupts
#define cli() __asm__ __volatile__ ("cli" ::: "memory")


// ISR function
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

void Interrupt0_Init(void);
void Timer2_InT(void);

#endif /* INTERRUPT_H_ */