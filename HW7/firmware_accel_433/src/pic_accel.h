/* 
 * File:   pic_accel.h
 * Author: mattcollins
 *
 * Created on April 17, 2015, 6:30 PM
 */

#ifndef PIC_ACCEL_H
#define	PIC_ACCEL_H

// accel to pixels
int accel_to_pixels(short accel);

// accel direction (for pixels)
char accel_pixel_direction(int numpixels);

// accelerometer test (Who Am I)
void accelerometer_test(void);

// creates bars with length proportional to X & Y acceleration due to gravity
void accelerometer_pixel_bars(void);

// creates pixel bars to show accelerations
void accel_pixels(int accelpixels,char axis);

#endif	/* PIC_ACCEL_H */

