#ifndef _SPICONFIG_H_
#define _SPICONFIG_H_

#define SLAVE_EXIST          1
#define SLAVE_NON_EXIST      0

#define ON                   1
#define OFF                  0

#define SLAVE                0
#define MASTER               1

#define MODE_MSRT_SLAVE SLAVE

#define SLAVE_1    SLAVE_EXIST
#define SLAVE_2    SLAVE_NON_EXIST
#define SLAVE_3    SLAVE_NON_EXIST
#define SLAVE_4    SLAVE_NON_EXIST
#define SLAVE_5    SLAVE_NON_EXIST
#define SLAVE_6    SLAVE_NON_EXIST
#define SLAVE_7    SLAVE_NON_EXIST
#define SLAVE_8    SLAVE_NON_EXIST







/*THIS MACRO CONTROLS THE CPOL FUNCTIONALITY
-RISING_FALLING
-FALLLING_RISING
 * */
#define CPOL_FUNCTIONALITY RISING_FALLING

/*THIS MACRO CONTROLS THE CLOCK PHASE BIT
-SAMPLE_SETUP
-SETUP_SAMPLE
 */
#define CLK_PHASE_BIT SAMPLE_SETUP

/*THIS MACRO CONTROLS DOUBLE SPEED
-ON
-OFF
 * */
#define DOUBLE_SPEED OFF

/*THIS MACRO CONTROLS PRESCALER
*IF DOUBLE_SPEED IS OFF
-FREQ_4
-FREQ_16
-FREQ_64
-FREQ_128
*IF DOUBLE_SPEED IS ON
-FREQ_2
-FREQ_8
-FREQ_32
-FREQ_64
*/
#define PRESCALER FREQ_16

/*THIS MACRO CONTROLS DATA ORDER
-LSB_FIRST
-MSB_FIRST
 * */
#define DATA_ORDER MSB_FIRST


/*SPI_CH0_PINS
*/
#define SPI_CH0_SS_PORT    PORTB
#define SPI_CH0_SS_PIN     PIN4
#define SPI_CH0_MOSI_PORT  PORTB
#define SPI_CH0_MOSI_PIN   PIN5
#define SPI_CH0_MISO_PORT  PORTB
#define SPI_CH0_MISO_PIN   PIN6
#define SPI_CH0_SCK_PORT   PORTB
#define SPI_CH0_SCK_PIN    PIN7

#if MODE_MSRT_SLAVE
#define SLAVE_1_PORT       PORTA
#define SLAVE_1_PIN        PIN0
#define SLAVE_2_PORT       PORTA
#define SLAVE_2_PIN        PIN1
#define SLAVE_3_PORT       PORTA
#define SLAVE_3_PIN        PIN2
#define SLAVE_4_PORT       PORTA
#define SLAVE_4_PIN        PIN3
#define SLAVE_5_PORT       PORTA
#define SLAVE_5_PIN        PIN4
#define SLAVE_6_PORT       PORTA
#define SLAVE_6_PIN        PIN5
#define SLAVE_7_PORT       PORTA
#define SLAVE_7_PIN        PIN6
#define SLAVE_8_PORT       PORTA
#define SLAVE_8_PIN        PIN7
#endif





#endif /*_SPICONFIG_H_*/
