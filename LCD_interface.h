/*
 * LCD_interface.h
 *
 *  Created on: Aug 5, 2016
 *      Author: mohamed
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define Disabled   0
#define Enabled    1


extern void Write_Command(u8 local_u8Command );
extern void Write_Data(u8 local_u8Data );
extern void LCD_init(void);
extern void Lcd8_Write_Char(char a);
extern void LCDBuildChar(u8 loc, u8 *p);
extern void Lcd8_Clear(void);
extern void Lcd8_Write_String(char *a);
extern void Lcd8_Set_Cursor(char a, char b);


#endif /* LCD_INTERFACE_H_ */
