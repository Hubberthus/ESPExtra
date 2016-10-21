#ifndef MCP23S17_H
#define MCP23S17_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcp23s17_regs.h"

// This defines are not representing the real Divider of the ESP8266
// the Defines match to an AVR Arduino on 16MHz for better compatibility
#define SPI_CLOCK_DIV2 		0x00101001 //8 MHz
#define SPI_CLOCK_DIV4 		0x00241001 //4 MHz
#define SPI_CLOCK_DIV8 		0x004c1001 //2 MHz
#define SPI_CLOCK_DIV16 	0x009c1001 //1 MHz
#define SPI_CLOCK_DIV32 	0x013c1001 //500 KHz
#define SPI_CLOCK_DIV64 	0x027c1001 //250 KHz
#define SPI_CLOCK_DIV128 	0x04fc1001 //125 KHz

extern uint8_t _mcp23s17_cs_pin;

void _mcp23s17_init(uint8_t chipSelectPin);
void _mcp23s17_setReg(uint8_t ctrl_reg, uint8_t chip, uint8_t value);
uint8_t _mcp23s17_getReg(uint8_t ctrl_reg, uint8_t chip);

#define _mcp23s17_setA(chip, value) _mcp23s17_setReg(MCP23S17_OLATA, chip, value)
#define _mcp23s17_setB(chip, value) _mcp23s17_setReg(MCP23S17_OLATB, chip, value)

#define _mcp23s17_getA(chip) _mcp23s17_getReg(MCP23S17_GPIOA, chip)
#define _mcp23s17_getB(chip) _mcp23s17_getReg(MCP23S17_GPIOB, chip)


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MCP23S17_H */

