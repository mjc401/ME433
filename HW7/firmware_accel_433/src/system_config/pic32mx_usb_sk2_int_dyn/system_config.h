/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.
    
    Created with MPLAB Harmony Version 1.03
*******************************************************************************/

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

/* This is a temporary workaround for an issue with the peripheral library "Exists"
   functions that causes superfluous warnings.  It "nulls" out the definition of
   The PLIB function attribute that causes the warning.  Once that issue has been
   resolved, this definition should be removed. */
#define _PLIB_UNSUPPORTED


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

#include "bsp_config.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "1.03"
#define SYS_VERSION               10300

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        40000000
#define SYS_CLK_BUS_PERIPHERAL_1            40000000
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       48000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul

/*** Interrupt System Service Configuration ***/

#define SYS_INT                     true


/*** Ports System Service Configuration ***/

#define SYS_PORT_AD1PCFG        0x0
#define SYS_PORT_CNPUE          0x0
#define SYS_PORT_CNEN           0x0




#define SYS_PORT_B_TRIS         0x7f7f
#define SYS_PORT_B_LAT          0x0
#define SYS_PORT_B_ODC          0x0








/*** Console System Service Configuration DISABLED ***/

#define SYS_CONSOLE_MESSAGE(message)
#define SYS_CONSOLE_PRINT(fmt, ...)


/*** Command Processor System Service Configuration DISABLED ***/

#define SYS_CMD_MESSAGE(message)
#define SYS_CMD_PRINT(fmt, ...)
#define SYS_CMD_READY_TO_READ()




// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************

/*** USB Driver Configuration ***/

/* Enables Device Support */
#define DRV_USB_DEVICE_SUPPORT      true

/* Enables Device Support */
#define DRV_USB_HOST_SUPPORT        false


/* Maximum USB driver instances */
#define DRV_USB_INSTANCES_NUMBER    1

/* Interrupt mode enabled */
#define DRV_USB_INTERRUPT_MODE      true

/* Number of Endpoints used */
#define DRV_USB_ENDPOINTS_NUMBER    2

/*** USB Device Stack Configuration ***/

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      8

#define USB_DEVICE_SOF_EVENT_ENABLE




/* Maximum instances of HID function driver */
#define USB_DEVICE_HID_INSTANCES_NUMBER     1










/* HID Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_HID_QUEUE_DEPTH_COMBINED 2

/* Tick time in 1msec units */
#define APP_USB_SWITCH_DEBOUNCE_COUNT (160)

/* Macro defines the conversion factor to be
 * multiplied to convert to millisecs*/
#define APP_USB_CONVERT_TO_MILLISECOND (1)

/* Macro defines USB internal DMA Buffer criteria*/
#define APP_MAKE_BUFFER_DMA_READY

/* Macros defines board specific led */
#define APP_USB_LED_1   BSP_LED_1

/* Macros defines board specific led */
#define APP_USB_LED_2    BSP_LED_2

/* Macros defines board specific led */
#define APP_USB_LED_3    BSP_LED_3

/* Macros defines board specific switch */
#define APP_USB_SWITCH_1    BSP_SWITCH_1

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/

