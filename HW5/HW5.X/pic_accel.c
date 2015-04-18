#include "accel.h"
#include "pic_accel.h"
#include "i2c_display.h"
#include <xc.h>

/*Converts accelerations to a proportional length for a OLED screen.  Returns a
 positive or negative value depending on acceleration direction.*/

int accel_to_pixels(short accel){
    int accelpixels;
    if (accel >= 0){
        accelpixels = accel/1024;
    }
    else{
        accelpixels = accel/1024;
    }
    return accelpixels;
}

/*Determines the acceleration direction.  Used to display direction on OLED screen*/

char accel_pixel_direction(int numpixels){
    if (numpixels > 0){
        return '+';
    }
    else if (numpixels < 0){
        return '-';
    }
    else{
        return '0';
    }
}

/*Reads from WHO_AM_I register on accelerometer to test that connections are working.
 The displayed value on the screen should be 73.*/

void accelerometer_test(void){
    unsigned char who,message[5];
    acc_read_register(WHO_AM_I,&who,1);
    sprintf(message,"%d",who);
    write_OLED_message(message,0,0);
    display_draw();
}

/*Determines number of pixels needed to display acceleration in a given direction
 and along what axis.*/

void accel_pixels(int accelpixels,char axis){
    int i,j;
    if (axis == 'x'){
        if (accelpixels > 0){
            for (i=0;i<=accelpixels;i++){
                for (j=0;j<6;j++){
                    display_pixel_set(29+j,64+i,1);
                }
            }
        }
        else if (accelpixels < 0){
            for (i=0;i<=-accelpixels;i++){
                for (j=0;j<6;j++){
                    display_pixel_set(29+j,63-i,1);
                }
            }
        }
    }
    if (axis == 'y'){
        if (accelpixels > 0){
            for (i=0;i<=accelpixels;i++){
                for (j=0;j<6;j++){
                    display_pixel_set(32+i,61+j,1);
                }
            }
        }
        else if (accelpixels < 0){
            for (i=0;i<=-accelpixels;i++){
                for (j=0;j<6;j++){
                    display_pixel_set(31-i,61+j,1);
                }
            }
        }
    }
}

/*One function that will do all calculations to display the pixel bars on the screen*/

void accelerometer_pixel_bars(void){
    short accels[3];
    int xpix,ypix;
    char x_acc_dir,y_acc_dir;
    unsigned char x_dir[20],y_dir[20];
    acc_read_register(OUT_X_L_A,(unsigned char *) accels, 6);
    xpix = accel_to_pixels(accels[0]);
    ypix = accel_to_pixels(accels[1]);
    x_acc_dir = accel_pixel_direction(xpix);
    y_acc_dir = accel_pixel_direction(ypix);
    sprintf(x_dir,"X-Acc = %c",x_acc_dir);
    sprintf(y_dir,"Y-Acc = %c",y_acc_dir);
    display_clear();
    write_OLED_message(x_dir,0,0);
    write_OLED_message(y_dir,10,0);
    accel_pixels(xpix,'x');
    accel_pixels(ypix,'y');
    display_draw();
}
