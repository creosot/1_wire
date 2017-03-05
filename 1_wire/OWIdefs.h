
#ifndef _OWI_DEFS_H_
#define _OWI_DEFS_H_

#include <avr/io.h>

/****************************************************************************
 ROM commands
****************************************************************************/
#define OWI_ROM_READ 0x33   //!< READ ROM command code.
#define OWI_ROM_SKIP 0xcc   //!< SKIP ROM command code.
#define OWI_ROM_MATCH 0x55  //!< MATCH ROM command code.
#define OWI_ROM_SEARCH 0xf0 //!< SEARCH ROM command code.

/****************************************************************************
 Return codes
****************************************************************************/
#define OWI_ROM_SEARCH_FINISHED 0x00 //!< Search finished return code.
#define OWI_ROM_SEARCH_FAILED 0xff   //!< Search failed return code.

/****************************************************************************
 UART patterns
****************************************************************************/
#define OWI_UART_WRITE1 0xff   //!< UART Write 1 bit pattern.
#define OWI_UART_WRITE0 0x00   //!< UART Write 0 bit pattern.
#define OWI_UART_READ_BIT 0xff //!< UART Read bit pattern.
#define OWI_UART_RESET 0xf0    //!< UART Reset bit pattern.

#endif
