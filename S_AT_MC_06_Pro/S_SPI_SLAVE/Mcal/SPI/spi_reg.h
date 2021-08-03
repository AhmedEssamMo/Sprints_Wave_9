/*
 * SPI_register.h
 *
 *  Created on: July 17, 2021
 *      Author: Ahmed
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR     *( ( volatile uint8_t* ) 0x2D )
#define SPSR     *( ( volatile uint8_t* ) 0x2E )
#define SPDR     *( ( volatile uint8_t* ) 0x2F )


#endif /* SPI_REGISTER_H_ */
