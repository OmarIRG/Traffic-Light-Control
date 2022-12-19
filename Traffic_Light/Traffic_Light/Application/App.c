/*
 * App.c
 *
 * Created: 12/12/2022 2:02:29 PM
 *  Author: omars
 */ 
#include "App.h"
uint8_t state = 0 ;               
uint8_t button = 0;
uint32_t counting2 = 0;
float counting = 0;
uint32_t check_push_yellow = 0 ;


void app_start()
{
	uint32_t five_seconds = 5;
	
	// initiate all pins used in this program
	
	Led_init(port_A , 0);  // set direction of pin 0 in portA output (car_green)
	Led_init(port_A , 1);  // set direction of pin 1 in portA output (car_yellow)
	Led_init(port_A , 2);  // set direction of pin 2 in portA output (car_red)
	Led_init(port_B , 0);  // set direction of pin 0 in portB output (pedestrain_green)
	Led_init(port_B , 1);  // set direction of pin 1 in portB output (pedestrain_yellow)
	Led_init(port_B , 2);  // set direction of pin 2 in portB output (pedestrain_red)
	
// -------------------------------------------------------------------------------------
	Button_Init(port_D , 2); // set direction of pin2 in portD (push button) to be input
// -------------------------------------------------------------------------------------	
    Timer0_Mode(Normal);     // set mode of the timer to normal mode
// -------------------------------------------------------------------------------------
    Timer2_Mode(Normal);
// -------------------------------------------------------------------------------------
    Interrupt0_Init();                    // Initiate Interrupt 0
	Timer2_InT();                        // overflow interrupts in timer 2
// -------------------------------------------------------------------------------------

	while(1){
		
		switch (state)
		{
		
		//------------------------------------------------------------
		
		case 0 :                                   // first case when cars is green and pedestrian is red
		while( counting < five_seconds ){          // increment 10 times of .5 to reach 5 seconds
			if (state == 1)                        // check if there is interrupt or not 
			{ 
				counting = 0;                      // if there is interrupt reset counting and break
				break;
			}
			else if (state == 0)                   // if there is no interrupt it will go back to normal function 
			{
		Led_on(port_A , 0);
		Led_on(port_B , 2);
        Timer0_Delay_half_second();                // delay .5 second
		counting = counting + .5;
			}
		}
		counting = 0;
		Led_off(port_A , 0);
		Led_off(port_B , 2);
		
		state = 1 ;
		break;

		// ------------------------------------------------------------

	    case 1 :                                     // first case when cars is yellow and pedestrian is yellow
		while( counting < five_seconds ){            // increment 10 times of .5 to reach 5 seconds
			if (check_push_yellow == 1)              // if interrupt while yellow leds are on then reset counting
			{
				counting = 0;
				Timer0_Stop();
				check_push_yellow = 0; 
				goto breaking1;
			}
			else                                     // no interrupt then go back to normal function
			{
		Led_toggle(port_A , 1);
		Led_toggle(port_B , 1);
		Timer0_Delay_half_second();                 // delay .5 second
		counting = counting + .5;
			}
		}
		counting = 0;
		Led_off(port_A , 1);
		Led_off(port_B , 1);
		
		state = 2;
		breaking1:
		break;
		
		//-------------------------------------------------------------
		
	    case 2 :                                     // first case when cars is red and pedestrian is green
		Led_on(port_A , 2);
		Led_on(port_B , 0);
		Timer0_Delay_5s();   // delay 5 seconds
		Led_off(port_A , 2);
		Led_off(port_B , 0);
		
		state = 3;
		break;
		
		//-------------------------------------------------------------
		
		case 3:                                             // first case when cars is yellow and pedestrian is yellow
		while( counting < five_seconds ){                   // increment 10 times of .5 to reach 5 seconds
			if (check_push_yellow == 1){                     // if interrupt while yellow leds are on then reset counting			{
				counting = 0;
				Timer0_Stop();
				check_push_yellow = 0;
				goto breaking2;
			}
			else
			{
			Led_toggle(port_A , 1);
			Led_toggle(port_B , 1);
			Timer0_Delay_half_second();             // delay .5 second
			counting = counting + .5;
			}
		}
		counting = 0;
		Led_off(port_A , 1);
		Led_off(port_B , 1);
		
		state = 0 ;
		breaking2:
		break;
		
		default:
		break;
		}
  

		
	}
	
	
}



ISR(INT_0){               // interrupt when pressing the push button
	
	button ++;
	
	switch(button){
	
	case 1:                                // set timer 0 to compare number of overflows with 30 (.5 second)
    Timer2_cl_source( clk_64 );            // set prescaller to 64
	TCNT2 = 47;                            // initiate timer 0 with 47
	break;
	
	case 2:                          
	if (counting2 > 30 ){                // if still pressing the button after .5 second nothing will happen
		// do nothing
	} 
	
	else{                                // go to state 1 (yellow state)
    
	if (state == 0){

		state = 1;
		counting = 0;
	}
	else if(state == 1 ){              // if state = 1 (yellow state)  then reset timer to start delay with 0 sec until it goes to 5 sec
		check_push_yellow = 1;
	}
	else if(state == 3 ){              // if state = 3 (yellow state)  then reset timer to start delay with 0 sec until it goes to 5 sec
		check_push_yellow = 1;
	}
	else{
		// do nothing
	}
	
    Timer2_Stop();   //
	counting2 = 0; // reset all
	button = 0 ;     //
	break;
	}
	}
}

ISR(TIMER2_OVF)
{
	counting2++; // increment overflow
}