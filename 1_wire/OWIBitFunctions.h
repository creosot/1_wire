
#ifndef _OWI_BIT_FUNCTIONS_H_
#define _OWI_BIT_FUNCTIONS_H_

#include "OWIdefs.h"
#include "OWIPolled.h"
#include "atmel_start.h"

#ifdef OWI_SOFTWARE_DRIVER
void OWI_Init(unsigned char pins);
void OWI_WriteBit1(unsigned char pins);
void OWI_WriteBit0(unsigned char pins);
unsigned char OWI_ReadBit(unsigned char pins);
unsigned char OWI_DetectPresence(unsigned char pins);
#endif

#ifdef OWI_UART_DRIVER
unsigned char OWI_TouchBit(unsigned char outValue);

void OWI_Init();
#define OWI_Init(arg) OWI_Init()

void OWI_WriteBit1();
#define OWI_WriteBit1(arg) OWI_WriteBit1()

void OWI_WriteBit0();
#define OWI_WriteBit0(arg) OWI_WriteBit0()

unsigned char OWI_ReadBit();
#define OWI_ReadBit(arg) OWI_ReadBit()

unsigned char OWI_DetectPresence();
#define OWI_DetectPresence(arg) OWI_DetectPresence()
#endif // OWI_UART_DRIVER

/****************************************************************************
 Macros
****************************************************************************/
/*! \brief Pull 1-Wire bus low.
 *
 *  This macro sets the direction of the 1-Wire pin(s) to output and
 *  pull the line(s) low.
 *
 *  \param bitMask  A bitmask of the buses to pull low.
 *  If more than one devices are present add corresponding Switch case.
 */

#define OWI_PULL_BUS_LOW(bitMask)                                                                                      \
	switch (bitMask) {                                                                                                 \
	case OWI_PIN_0:                                                                                                    \
		OWI_DS1820_set_dir(PORT_DIR_OUT);                                                                              \
		OWI_DS1820_set_level(0);                                                                                       \
		break;                                                                                                         \
	}

/*! \def    OWI_RELEASE_BUS(bitMask)
 *
 *  \brief  Release the bus.
 *
 *  This macro releases the bus and enables the internal pull-up if
 *  it is used.
 *
 *  \param  bitMask A bitmask of the buses to release.
 *If more than one devices are present add corresponding Switch case.
 */
#ifdef OWI_USE_INTERNAL_PULLUP

#define OWI_RELEASE_BUS(bitMask)                                                                                       \
	switch (bitMask) {                                                                                                 \
	case OWI_PIN_0:                                                                                                    \
		OWI_DS1820_set_dir(PORT_DIR_IN);                                                                               \
		OWI_DS1820_set_pull_mode(PORT_PULL_UP);                                                                        \
		break;                                                                                                         \
	}

#else
// Set 1-Wire pin(s) to input mode. No internal pull-up enabled.

#define OWI_RELEASE_BUS(bitMask)                                                                                       \
	switch (bitMask) {                                                                                                 \
	case OWI_PIN_0:                                                                                                    \
		OWI_DS1820_set_dir(PORT_DIR_IN);                                                                               \
		OWI_DS1820_set_pull_mode(PORT_PULL_OFF);                                                                       \
		break;                                                                                                         \
	}

#endif

#endif
