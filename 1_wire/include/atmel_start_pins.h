/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set OWI_DS1820 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void OWI_DS1820_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(PORTD0, pull_mode);
}

/**
 * \brief Set OWI_DS1820 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void OWI_DS1820_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(PORTD0, dir);
}

/**
 * \brief Set OWI_DS1820 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void OWI_DS1820_set_level(const bool level)
{
	PORTD_set_pin_level(PORTD0, level);
}

/**
 * \brief Toggle output level on OWI_DS1820
 *
 * Toggle the pin level
 */
static inline void OWI_DS1820_toggle_level()
{
	PORTD_toggle_pin_level(PORTD0);
}

/**
 * \brief Get level on OWI_DS1820
 *
 * Reads the level on a pin
 */
static inline bool OWI_DS1820_get_level()
{
	return PORTD_get_pin_level(PORTD0);
}

#endif // ATMEL_START_PINS_H_INCLUDED
