/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

void system_init()
{
	mcu_init();

	// PORT on PD0

	// Set pin direction to input
	OWI_DS1820_set_dir(PORT_DIR_IN);

	OWI_DS1820_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_UP);

	sysctrl_init();
}
