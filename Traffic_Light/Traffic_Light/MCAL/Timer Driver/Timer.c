/*
 * Timer.c
 *
 * Created: 12/10/2022 10:00:26 PM
 *  Author: omars
 */ 
#include "Timer.h"

void Timer0_Mode( uint8_t Mode ){        // set the mode Timer0 (Normal or CTC or Phase Shift or Fast PWM) 
	
	switch(Mode){
		
		case Normal :
		TCCR0 |= (0<<3) | (0<<6);
		break;
		
		case CTC :
		TCCR0 |= (1<<3) | (0<<6);
		break;
		
		case Phase_Shift :
		TCCR0 |= (0<<3) | (1<<6);
		break;
		
		case Fast_PWM :
		TCCR0 |= (1<<3) | (1<<6);
		break;
		
	}
	
	
}

void Timer0_cl_source( uint8_t Clk_Source ){    // choose if no prescaller or with prescaller and which type or choose rising edge or falling edge 
	
	switch(Clk_Source){
		
		case  No_clock_source :
		        TCCR0 |= (0 << 0) | (0 << 1) | (0 << 2);
		break;
		
		case clk :
				TCCR0 |= (1 << 0) | (0 << 1) | (0 << 2);
		break;
		
		case clk_8 :
				TCCR0 |= (0 << 0) | (1 << 1) | (0 << 2);
		break;
		
		case clk_64 :
				TCCR0 |= (1 << 0) | (1 << 1) | (0 << 2);
		break;
		
		case clk_256 :
				TCCR0 |= (0 << 0) | (0 << 1) | (1 << 2);
		break;
		
		case clk_1024 :
				TCCR0 |= (1 << 0) | (0 << 1) | (1 << 2);
		break;
		
		case falling_edge :
				TCCR0 |= (0 << 0) | (1 << 1) | (1 << 2);
		break;
		
		case rising_edge :
				TCCR0 |= (1 << 0) | (1 << 1) | (1 << 2);
		break;
		
	}
	
	
}

void Timer0_Stop(void){       // stop timer 
	TCCR0 = 0;
}

/*

to make delay we need 3 informations:

1:prescaller type
2:Number of overflows
3:initial value of the timer

*/
void Timer0_Delay(uint8_t Clk_Source , uint32_t Number_Of_OverFlows , uint8_t Initial_Value){  
	
	Timer0_cl_source(Clk_Source );
	TCNT0 = Initial_Value;
	uint32_t Over_Flow   = 0;
	
	
	while (Over_Flow < Number_Of_OverFlows)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0);
		// Clear the overflow flag
		TIFR |= (1 << 0);
		Over_Flow++;
	}
	
	
	Over_Flow = 0;
	Timer0_Stop();
}

void Timer0_Delay_5s(void){     // delay 5 seconds
	
	Timer0_Delay( clk_1024 , 20 , 237 );
	
}

void Timer0_Delay_half_second(void){
	
	Timer0_Delay( clk_1024 , 2 , 24 );
	
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------//
//                                                           Timer 2
// -------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Timer2_Mode( uint8_t Mode ){        // set the mode Timer0 (Normal or CTC or Phase Shift or Fast PWM)
	
	switch(Mode){
		
		case Normal :
		TCCR2  |= (0<<3) | (0<<6);
		break;
		
		case CTC :
		TCCR2  |= (1<<3) | (0<<6);
		break;
		
		case Phase_Shift :
		TCCR2  |= (0<<3) | (1<<6);
		break;
		
		case Fast_PWM :
		TCCR2  |= (1<<3) | (1<<6);
		break;
		
	}
	
	
}

void Timer2_cl_source( uint8_t Clk_Source ){    // choose if no prescaller or with prescaller and which type or choose rising edge or falling edge
	
	switch(Clk_Source){
		
		case  No_clock_source :
		TCCR2 |= (0 << 0) | (0 << 1) | (0 << 2);
		break;
		
		case clk :
		TCCR2 |= (1 << 0) | (0 << 1) | (0 << 2);
		break;
		
		case clk_8 :
		TCCR2 |= (0 << 0) | (1 << 1) | (0 << 2);
		break;
		
		case clk_64 :
		TCCR2 |= (1 << 0) | (1 << 1) | (0 << 2);
		break;
		
		case clk_256 :
		TCCR2 |= (0 << 0) | (0 << 1) | (1 << 2);
		break;
		
		case clk_1024 :
		TCCR2 |= (1 << 0) | (0 << 1) | (1 << 2);
		break;
		
		case falling_edge :
		TCCR2 |= (0 << 0) | (1 << 1) | (1 << 2);
		break;
		
		case rising_edge :
		TCCR2 |= (1 << 0) | (1 << 1) | (1 << 2);
		break;
		
	}
}

void Timer2_Stop(void){       // stop timer2
	TCCR2 = 0;
}

void Timer2_Delay(uint8_t Clk_Source , uint32_t Number_Of_OverFlows , uint8_t Initial_Value){
	
	Timer2_cl_source(Clk_Source );
	TCNT2 = Initial_Value;
	uint32_t Over_Flow   = 0;
	
	
	while (Over_Flow < Number_Of_OverFlows)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0);
		// Clear the overflow flag
		TIFR |= (1 << 0);
		Over_Flow++;
	}
	
	
	Over_Flow = 0;

}

void Timer2_Delay_half_second(void){  // delay of .5 second
	
	Timer2_Delay( clk_64 , 30 , 47);
	
}