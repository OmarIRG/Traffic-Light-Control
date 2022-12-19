/*
 * DIO.h
 *
 * Created: 12/9/2022 8:59:31 PM
 *  Author: omars
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Regesters.h"
#include "../../Utilities/Types.h"

/*
declaration of ports
*/

#define port_A 'A'
#define port_B 'B'
#define port_C 'C'
#define port_D 'D'

/*
macros of:
input , output , low ,  high  macros
*/

#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1

/*
                                                                     Functions to make it easier to use  
*/

// all functions are void outputs

// Set the direction of pins >> input or output
void Dio_init(uint8_t  Port_Letter , uint8_t  Pin_Number , uint8_t  Direction ); // takes port number and pin number and direction


//  read any pin state
void Dio_read(uint8_t  Port_Letter , uint8_t  Pin_Number , uint8_t  *value ); // takes port number and pin number and read value


//  Initiate any pin to use it as high voltage or ground(low voltage)
void Dio_Write(uint8_t  Port_Letter , uint8_t  Pin_Number , uint8_t  value ); // takes port number and pin number and write value


// toggle any pin (low and high)
void Dio_Toggle(uint8_t  Port_Letter , uint8_t  Pin_Number  );  // takes port number and pin number


#endif /* DIO_H_ */