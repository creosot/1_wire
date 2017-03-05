
#ifndef _OWI_ROM_FUNCTIONS_H_
#define _OWI_ROM_FUNCTIONS_H_

void OWI_SendByte(unsigned char data, unsigned char pins);
unsigned char OWI_ReceiveByte(unsigned char pin);
void OWI_SkipRom(unsigned char pins);
void OWI_ReadRom(unsigned char *romValue, unsigned char pins);
void OWI_MatchRom(unsigned char *romValue, unsigned char pins);
unsigned char OWI_SearchRom(unsigned char *bitPattern, unsigned char lastDeviation, unsigned char pins);

#endif
