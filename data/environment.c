/*

 ENVIRONMENT.C

 Tile Source File.

 Info:
  Form                 : All tiles as one unit.
  Format               : Gameboy 4 color.
  Compression          : None.
  Counter              : None.
  Tile size            : 8 x 8
  Tiles                : 0 to 9

  Palette colors       : None.
  SGB Palette          : None.
  CGB Palette          : None.

  Convert to metatiles : No.

 This file was generated by GBTD v2.2

*/

/* Start of tile array. */
#include "environment.h"

unsigned char TileEnvironment[] =
{
	//NORMAL BOTTOM 1
	0xFF,0x10,0x18,0xF7,0x18,0xF7,0xFF,0xFF,
	0xFF,0x01,0x81,0x7F,0x81,0x7F,0xFF,0xFF,
	//TOPLEFT LEFT 2
	0xFF,0xFF,0x98,0xF7,0x98,0xF7,0xFF,0xFF,
	0xFF,0x81,0x81,0xFF,0x81,0xFF,0xFF,0xFF,
	//BOTTOM LEFT 3
	0xFF,0x90,0x98,0xF7,0x98,0xF7,0xFF,0xFF,
	0xFF,0x81,0x81,0xFF,0x81,0xFF,0xFF,0xFF,
	//TOPRIGHT RIGHT 4
	0xFF,0xFF,0x19,0xF7,0x19,0xF7,0xFF,0xFF,
	0xFF,0x01,0x81,0x7F,0x81,0x7F,0xFF,0xFF,
	//BOTTOM RIGHT 5
	0xFF,0x11,0x19,0xF7,0x19,0xF7,0xFF,0xFF,
	0xFF,0x01,0x81,0x7F,0x81,0x7F,0xFF,0xFF,
	//TOP 6
	0xFF,0xFF,0x18,0xF7,0x18,0xF7,0xFF,0xFF,
	0xFF,0x01,0x81,0x7F,0x81,0x7F,0xFF,0xFF,
	//BARREL 7
	0x3F,0x3F,0x60,0x5F,0x7F,0x7F,0x68,0x5F,
	0xD0,0xBF,0xD0,0xBF,0xD0,0xBF,0xD0,0xBF,
	//8
	0xD0,0xBF,0xD0,0xBF,0xD0,0xBF,0xD0,0xBF,
	0x68,0x5F,0x7F,0x7F,0x60,0x5F,0x3F,0x3F,
	//9
	0xFC,0xFC,0x06,0xFA,0xFE,0xFE,0x8E,0xFA,
	0x87,0xFD,0x87,0xFD,0x87,0xFD,0x87,0xFD,
	//10
	0x87,0xFD,0x87,0xFD,0x87,0xFD,0x87,0xFD,
	0x8E,0xFA,0xFE,0xFE,0x06,0xFA,0xFC,0xFC
};

unsigned char TileWhite[] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
UBYTE TileEnvironmentLength = 10U;

/* End of ENVIRONMENT.C */
