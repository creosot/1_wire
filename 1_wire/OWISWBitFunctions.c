#include "OWIPolled.h"

#ifdef OWI_SOFTWARE_DRIVER

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <util/atomic.h>
#include "OWIBitFunctions.h"

/*! \brief Initialization of the one wire bus(es). (Software only driver)
 *
 *  This function initializes the 1-Wire bus(es) by releasing it and
 *  waiting until any presence sinals are finished.
 *
 *  \param  pins    A bitmask of the buses to initialize.
 */
void OWI_Init(unsigned char pins)
{
	OWI_RELEASE_BUS(pins);

	// The first rising edge can be interpreted by a slave as the end of a
	// Reset pulse. Delay for the required reset recovery time (H) to be
	// sure that the real reset is interpreted correctly.
	_delay_loop_2((OWI_DELAY_H_STD_MODE) / 4);
}

/*! \brief  Write a '1' bit to the bus(es). (Software only driver)
 *
 *  Generates the waveform for transmission of a '1' bit on the 1-Wire
 *  bus.
 *
 *  \param  pins    A bitmask of the buses to write to.
 */
void OWI_WriteBit1(unsigned char pins)
{

	// restore interrupts
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		// Drive bus low and delay.
		OWI_PULL_BUS_LOW(pins);
		_delay_loop_2((OWI_DELAY_A_STD_MODE) / 4);

		// Release bus and delay.
		OWI_RELEASE_BUS(pins);
		_delay_loop_2((OWI_DELAY_B_STD_MODE) / 4);
	}
}

/*! \brief  Write a '0' to the bus(es). (Software only driver)
 *
 *  Generates the waveform for transmission of a '0' bit on the 1-Wire(R)
 *  bus.
 *
 *  \param  pins    A bitmask of the buses to write to.
 */
void OWI_WriteBit0(unsigned char pins)
{

	// restore interrupts
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		// Drive bus low and delay.
		OWI_PULL_BUS_LOW(pins);
		_delay_loop_2((OWI_DELAY_C_STD_MODE) / 4);

		// Release bus and delay.
		OWI_RELEASE_BUS(pins);
		_delay_loop_2((OWI_DELAY_D_STD_MODE) / 4);
	}
}

/*! \brief  Read a bit from the bus(es). (Software only driver)
 *
 *  Generates the waveform for reception of a bit on the 1-Wire(R) bus(es).
 *
 *  \param  pins    A bitmask of the bus(es) to read from.
 *
 *  \return A bitmask of the buses where a '1' was read.
 */
unsigned char OWI_ReadBit(unsigned char pins)
{

	unsigned char bitsRead;

	// restore interrupts
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		// Drive bus low and delay.
		OWI_PULL_BUS_LOW(pins);
		_delay_loop_2((OWI_DELAY_A_STD_MODE) / 4);

		// Release bus and delay.
		OWI_RELEASE_BUS(pins);
		_delay_loop_2((OWI_DELAY_E_STD_MODE) / 4);

		// Sample bus and delay.
		bitsRead = OWI_PIN & pins;
		_delay_loop_2((OWI_DELAY_F_STD_MODE) / 4);
	}

	return bitsRead;
}

/*! \brief  Send a Reset signal and listen for Presence signal. (software
 *  only driver)
 *
 *  Generates the waveform for transmission of a Reset pulse on the
 *  1-Wire(R) bus and listens for presence signals.
 *
 *  \param  pins    A bitmask of the buses to send the Reset signal on.
 *
 *  \return A bitmask of the buses where a presence signal was detected.
 */
unsigned char OWI_DetectPresence(unsigned char pins)
{

	unsigned char presenceDetected;

	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		// Drive bus low and delay.
		OWI_PULL_BUS_LOW(pins);
		_delay_loop_2((OWI_DELAY_H_STD_MODE) / 4);

		// Release bus and delay.
		OWI_RELEASE_BUS(pins);
		_delay_loop_2((OWI_DELAY_I_STD_MODE) / 4);

		// Sample bus to detect presence signal and delay.
		presenceDetected = ((~OWI_PIN) & pins);
		_delay_loop_2((OWI_DELAY_J_STD_MODE) / 4);
	}

	return presenceDetected;
}

#endif
