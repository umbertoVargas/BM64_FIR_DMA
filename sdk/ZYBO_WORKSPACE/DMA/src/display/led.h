 #ifndef LED_H
 #define LED_H
#include "xparameters.h"
#include "led.h"
#include "xil_io.h"
#include "led_display.h"
/* 	Define the base memory addresses of the stopwatch_controller IP core */
#define LED_BASE XPAR_LED_DISPLAY_0_S00_AXI_BASEADDR
#define ADDR_DATA LED_DISPLAY_S00_AXI_SLV_REG0_OFFSET
#define WE_OE LED_DISPLAY_S00_AXI_SLV_REG1_OFFSET
#define O_DEMUX LED_DISPLAY_S00_AXI_SLV_REG2_OFFSET
#define O_DATA LED_DISPLAY_S00_AXI_SLV_REG3_OFFSET


void runLed();




#endif
