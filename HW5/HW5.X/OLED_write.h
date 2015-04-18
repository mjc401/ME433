/* 
 * File:   OLED_write.h
 * Author: mattcollins
 *
 * Created on April 13, 2015, 5:06 PM
 */

#ifndef OLED_WRITE_H
#define	OLED_WRITE_H

void OLED_ASCII(const char array[][5],char letter,int row,int col);
void write_OLED_message(char *array,int row,int col);

#endif	/* OLED_WRITE_H */

