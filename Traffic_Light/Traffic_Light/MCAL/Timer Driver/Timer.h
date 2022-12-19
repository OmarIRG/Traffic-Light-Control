/*
 * Timer.h
 *
 * Created: 12/10/2022 10:00:38 PM
 *  Author: omars
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/Regesters.h"
#include "../../Utilities/Types.h"

// modes macros

#define Normal 0
#define CTC  1
#define Phase_Shift  2
#define Fast_PWM 3

//prescaller macros

#define No_clock_source 0
#define clk 1
#define clk_8 2
#define clk_64 3
#define clk_256 4
#define clk_1024  5
#define falling_edge 6
#define rising_edge 7


#define Frequancy 1000000  // frequency of atmega 32

/*
                                                                     Functions to make it easier to use  
*/


//                                              all functions output are void 

void Timer0_Mode( uint8_t Mode ); // select the mode of timer 0 (in this program we use normal mode)  // input is mode 

void Timer0_cl_source( uint8_t Clk_Source ); // initiate the start of timer0   // input is prescaller type

void Timer0_Stop(void); // Stop Timer // void input



/* set delay of time by taking

inputs:
1: Clk Source (prescaller)
2:Number Of Overflows needed to reach the delay
3:Initial Value to increase inefficiency by reducing the error from reminder of N_OF_Overflows If its float -> 13.34 (aking .34 in calculation) 
output is void

*/
void Timer0_Delay(uint8_t Clk_Source , uint32_t Number_Of_OverFlows , uint8_t Initial_Value);  

void Timer0_Delay_5s(void); // delay 5 sec

/*

by taking 1024 prescaller
then T(tick) = 1024/F = 1024 us
then T(max delay) = 2^8 * T(tick) = 262.144 ms
then N of overflows needed to delay 5 sec is -> T(delay) / T(max delay) = 19 .073 = 20
then initial value of timer is 237 
*/

void Timer0_Delay_half_second(void);

/*

by taking 1024 prescaller
then T(tick) = 1024/F = 1024 us
then T(max delay) = 2^8 * T(tick) = 262.144 ms
then N of overflows needed to delay 5 sec is -> T(delay) / T(max delay) = 1.9073 = 2
then initial value of timer is 23.71 = 24

*/

void Timer2_Mode( uint8_t Mode ); // select the mode of timer 0 (in this program we use normal mode)   // input is mode 

void Timer2_cl_source( uint8_t Clk_Source ); // initiate the start of timer0  //  input is prescaller type

void Timer2_Stop(void); // Stop Timer

void Timer2_Delay(uint8_t Clk_Source , uint32_t Number_Of_OverFlows , uint8_t Initial_Value);   // make delay by knowing (number of overflows and initial value and prescaller)

void Timer2_Delay_half_second(void); // delay .5 sec

/*

by taking 64 prescaller
then T(tick) = 64/F = 64 us
then T(max delay) = 2^8 * T(tick) = 16.384 ms
then N of overflows needed to delay 5 sec is -> T(delay) / T(max delay) = 1.9073 = 2
then initial value of timer is 23.71 = 24

*/


#endif /* TIMER_H_ */

































