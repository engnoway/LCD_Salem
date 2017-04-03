/*
 * LCD_prog.c
 *
 *  Created on: Aug 5, 2016
 *      Author: mohamed
 */


#include "Types.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "util.h"
#include "delay_config.h"
#include "delay.h"

////////////////////////////////////////////////////////////
void Lcd8_Write_Char(char a)
{
	DIO_u8WritePinVal(RS,1);          // => RS = 1
	DIO_u8WritePortVal(DIO_u8PORT3,a);             //Data transfer
	DIO_u8WritePinVal(EN,1);             // => E = 1
	Delay_ms(1);
	DIO_u8WritePinVal(EN,0);             // => E = 04
	Delay_ms(1);
}
///////////////////////////////////////////////////////////
	void LCDBuildChar(u8 loc, u8 *p) {
		u8 i;

		if (loc < 8)                                 //If valid address
				{
			Write_Command(0x40 + (loc * 8));               //Write to CGRAM
			for (i = 0; i < 8; i++)
				Write_Data(p[i]);             //Write the character pattern to CGRAM
		}
		Write_Command(0x80);                        //shift back to DDRAM location 0
	}
/////////////////////////////////////
	void Lcd8_Clear(void)
	{
		DIO_u8WritePinVal(RS,0);             // => RS = 0
		DIO_u8WritePortVal(DIO_u8PORT3,1);              //Data transfer
		DIO_u8WritePinVal(EN,1);            // => E = 1
		Delay_ms(1);
		DIO_u8WritePinVal(EN,0);             // => E = 0
		Delay_ms(1);
	}
///////////////////////////
	void Lcd8_Write_String(char *a)
	{
		int i;
		for(i=0;a[i]!='\0';i++)
		Lcd8_Write_Char(a[i]);
	}
//////////////////////////////////
	void Lcd8_Set_Cursor(char a, char b)
	{
		if(a == 1)
		{
			DIO_u8WritePinVal(RS,0);             // => RS = 0
					DIO_u8WritePortVal(DIO_u8PORT3,(0x80 + b));              //Data transfer
					DIO_u8WritePinVal(EN,1);            // => E = 1
					Delay_ms(1);
					DIO_u8WritePinVal(EN,0);             // => E = 0
					Delay_ms(1);
		}

		else if(a == 2)
		{
			DIO_u8WritePinVal(RS,0);             // => RS = 0
			DIO_u8WritePortVal(DIO_u8PORT3,(0xC0 + b));              //Data transfer
		    DIO_u8WritePinVal(EN,1);            // => E = 1
			Delay_ms(1);
			DIO_u8WritePinVal(EN,0);             // => E = 0
			Delay_ms(1);
		}

	}
	////////////////////////////////
void Write_Command(u8 copy_u8Command )
{

	u8 local_u8Data=copy_u8Command;

	DIO_u8WritePortVal(DIO_u8PORT3,local_u8Data);
	DIO_u8WritePinVal(RS,0);
	DIO_u8WritePinVal(RW,0);
	DIO_u8WritePinVal(EN,1);
	//delay_voidDelay(0.5);
	DIO_u8WritePinVal(EN,0);
//	delay_voidDelay(1);//1usec
}


///////////////
void Write_Data(u8 copy_u8Data )
{	u8 local_u8Data2=copy_u8Data;
DIO_u8WritePortVal(DIO_u8PORT3,local_u8Data2);


	DIO_u8WritePinVal(RS,1);
	DIO_u8WritePinVal(RW,0);
	DIO_u8WritePinVal(EN,1);
	//delay_voidDelay(0.5);
	DIO_u8WritePinVal(EN,0);
//	delay_voidDelay(1);//1usec
}
//////////////////////////////////////////////////////////

void LCD_init(void)
{
	Delay_ms(20);
	Write_Command(0b00110000);
	Delay_ms(5);
	Write_Command(0b00110000);
	//Write_Command(0b00000100);
	Delay_ms(0.5);
	Write_Command(0b00110000);
	//delay_voidDelay(1);

	Write_Command(0b00111000);//function set
	Write_Command(0b00000110);//entry mode
	Write_Command(0b00001111);//display mode


}
