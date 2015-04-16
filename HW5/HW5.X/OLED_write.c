#include "OLED_write.h"
#include "i2c_display.h"
#include "ASCII_Table.h"

void OLED_ASCII(const char array[][5],char letter,int row,int col){
    int i,j,rowset;
    rowset=row;
    for(i=0;i<5;i++){
        for(j=0;j<8;j++){
            display_pixel_set(row,col,array[letter-0x20][i]>>j&0b1);
            row++;
        }
        row=rowset;
        col++;
    }
}

void write_OLED_message(char *array,int row,int col){
    int i=0,j=0,k=0,colspace=1,rowspace=1;
    while(array[i]){
        if (row+(rowspace+8)*j<55){
            if(((5+colspace)*k+col)<120){
                OLED_ASCII(ASCII,array[i],row+(rowspace+8)*j,(5+colspace)*k+col);
                i++;
                k++;
            }
            else{
                j++;
                k=0;
            }
        }
        else{
            break;
        }
    }
}

//void accel_pixels(int accelpixels,char axis){
//    int i;
//    if (axis == 'x'){
//        if (accelpixels > 0){
//            for (i=0;i<=accelpixels;i++){
//                display_pixel_set(32,63+i,1);
//            }
//        }
//        else if (accelpixels < 0){
//            for (i=0;i<=-accelpixels;i++){
//                display_pixel_set(32,63+i,1);
//            }
//        }
//        else{
//            break;
//        }
//    }
//    if (axis == 'y'){
//        if (accelpixels > 0){
//            for (i=0;i<=accelpixels;i++){
//                display_pixel_set(32,63+i,1);
//            }
//        }
//        else if (accelpixels < 0){
//            for (i=0;i<=-accelpixels;i++){
//                display_pixel_set(32,63+i,1);
//            }
//        }
//        else{
//            break;
//        }
//    }
//}