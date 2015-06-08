
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "system/common/sys_module.h"   // SYS function prototypes
#include "system_config.h"
#include "system_definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize ( NULL );

    //Initialize Phase (Direction) for motors
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB7 = 0;
    LATBbits.LATB14 = 1;
    LATBbits.LATB7 = 0;

    //Initialize Output Compare PWM for motor speed

    //Timer 2 Setup
    T2CONbits.ON = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.T32 = 0;
    TMR2 = 0;
    PR2 = 1999;
    T2CONbits.ON = 1;

    //OC1 Setup (B15)
    ANSELBbits.ANSB15 = 0;
    RPB15Rbits.RPB15R = 0b0101;
    OC1CONbits.ON = 0;
    OC1CONbits.OC32 = 0;
    OC1CONbits.OCTSEL = 0;
    OC1CONbits.OCM = 0b110;
    OC1RS = 0;
    OC1CONbits.ON = 1;

    //OC2 Setup (B5)
    RPB5Rbits.RPB5R = 0b0101;
    OC2CONbits.ON = 0;
    OC2CONbits.OC32 = 0;
    OC2CONbits.OCTSEL = 0;
    OC2CONbits.OCM = 0b110;
    OC2RS = 0;
    OC2CONbits.ON = 1;

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

