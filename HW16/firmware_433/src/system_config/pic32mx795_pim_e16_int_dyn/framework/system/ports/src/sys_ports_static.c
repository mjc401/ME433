
#include "system_config.h"
#include "peripheral/ports/plib_ports.h"
#include "peripheral/int/plib_int.h"


void SYS_PORTS_Initialize(void)
{
    /* AN and CN Pins Initialization */
//    PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, SYS_PORT_AD1PCFG, PORTS_PIN_MODE_DIGITAL);
//    PLIB_PORTS_CnPinsPullUpEnable(PORTS_ID_0, SYS_PORT_CNPUE);
//    PLIB_PORTS_CnPinsEnable(PORTS_ID_0, SYS_PORT_CNEN);
//    PLIB_PORTS_ChangeNoticeEnable(PORTS_ID_0);
    
    ANSELBbits.ANSB13 = 0;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB7 = 0;
    ANSELBbits.ANSB15 = 0;
    
//    /* PORT A Initialization */
//    PLIB_PORTS_DirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_B,  SYS_PORT_B_TRIS ^ 0xFFFF);
//    PLIB_PORTS_Toggle( PORTS_ID_0, PORT_CHANNEL_B,  SYS_PORT_B_LAT);
//    PLIB_PORTS_OpenDrainEnable(PORTS_ID_0, PORT_CHANNEL_B, SYS_PORT_B_ODC);
    
}


/*******************************************************************************
 End of File
*/
