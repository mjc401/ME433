/*******************************************************
 Windows HID simplification

 Alan Ott
 Signal 11 Software

 8/22/2009

 Copyright 2009
 
 This contents of this file may be used by anyone
 for any reason without any conditions and may be
 used as a starting point for your own applications
 which use HIDAPI.
********************************************************/

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include "hidapi.h"

// Headers needed for sleeping.
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

#define MAX_STR 255

#define PIC_READ 1
#define PIC_REPLY 2
#define PIC_NONE 0

int main(int argc, char* argv[])
{
	int res;
	unsigned char buf[65];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i,j = 0;
	unsigned char message[25];
	int length,row;
	short xa[500],ya[500],za[500];;
	float accel_x[500],accel_y[500],accel_z[500];
	
	// Initialize the hidapi library
	res = hid_init();
	
	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x4d8, 0x3f, NULL);
	
	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	wprintf(L"Manufacturer String: %s\n", wstr);
	
	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	wprintf(L"Product String: %s\n", wstr);
	
	// Read the Serial Number String
	res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	wprintf(L"Serial Number String: (%d) %s\n", wstr[0], wstr);
	
	// Read Indexed String 1
	res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
	wprintf(L"Indexed String 1: %s\n", wstr);
	
	// Toggle LED (cmd 0x80). The first byte is the report number (0x0).
//	buf[0] = 0x0;
//	buf[1] = 0x80;
//	res = hid_write(handle, buf, 65);
//	
//	// Request state (cmd 0x81). The first byte is the report number (0x0).
//	buf[0] = 0x0;
//	buf[1] = 0x81;
//	res = hid_write(handle, buf, 65);
//	
//	// Read requested state
//	res = hid_read(handle, buf, 65);
//	
//	// Print out the returned buffer.
//	for (i = 0; i < 4; i++)
//		printf("buf[%d]: %d\n", i, buf[i]);
	
	
	// Get string and row number from computer
	printf("String: ");
	length = scanf("%25[^\n]s",message);
	printf("Row: ");
	scanf("%d",&row);
	buf[0] = 0x0; 
	buf[1] = PIC_READ; //Set buf[1] to read
	buf[2] = row; //send row
	
	for(i=0;i < 25;i++){
		buf[3+i] = message[i];
	}
	
	res = hid_write(handle, buf, 65);
	
	// Get accelerometer values sampled at 100Hz for 5s
	
	while(j<500){
		buf[0] = 0x0;
		buf[1] = PIC_REPLY;
		res = hid_write(handle,buf,65);
		res = hid_read(handle,buf,65);
		if(buf[0] == 1){
			// Reconstruct accelerometers bytes
			xa[j] = buf[1] << 8 | buf[2];
			ya[j] = buf[3] << 8 | buf[4];
			za[j] = buf[5] << 8 | buf[6];
			// Convert to gs
			accel_x[j] = xa[j]*6.1/100000;
			accel_y[j] = ya[j]*6.1/100000;
			accel_z[j] = za[j]*6.1/100000;
			//printf("%d %f %f %f\n",j,accel_x[j],accel_y[j],accel_z[j]);
			j++;
		}
	}
		
	// Save all accelerometer values (in gs) 
	FILE *ofp;
	ofp = fopen("/Users/mattcollins/Documents/ME433/HW8/accels.txt","w");
	fprintf(ofp,"X_Accel Y_Accel Z_Accel\n");
	for(i = 0; i < 500; i++){
		fprintf(ofp,"%f %f %f\r\n",accel_x[i],accel_y[i],accel_z[i]);
	}
	fclose(ofp);
	
	
	// Finalize the hidapi library
	res = hid_exit();
	
	return 0;
}