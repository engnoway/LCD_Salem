/*
 * main.c
 *
 *  Created on: Aug 5, 2016
 *      Author: mohamed
 */


#include "Types.h"
#include "util.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "delay.h"



void start (void) __attribute__((constructor));
	int main(void)

	{

		/*DIO_voidInit();
		LCD_init();
		Lcd8_Set_Cursor(1, 15);
		Lcd8_Write_Char('M');

		while (1) {

		}*/
		Lcd8_Set_Cursor(2, 15);
				Lcd8_Write_Char('M');
	}

	void start()
	{
		DIO_voidInit();
				LCD_init();
		Lcd8_Write_String("Hello Mido");

	}
