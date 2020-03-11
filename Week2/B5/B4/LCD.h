/*
 * LCD.h
 *
 * Created: 11-3-2020 21:21:25
 *  Author: mjays
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_E 	3

void lcd_init();
void lcd_display_text(char *str);
void lcd_set_cursor(int position);
void lcd_e(void);
void lcd_write_char(unsigned char dat);

#endif /* LCD_H_ */