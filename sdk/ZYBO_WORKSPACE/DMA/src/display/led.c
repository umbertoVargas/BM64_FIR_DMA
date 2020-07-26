#include "led.h"


void runLed(){


	u32 add_data_reg = 0;
	u32 we_oe_reg = 0;
	u32 o_demux_reg = 0;
	u32 o_data = 0;
	u32 rows=0b1;

    /* oe and we disable*/
    LED_DISPLAY_mWriteReg(LED_BASE, WE_OE, we_oe_reg);

    /*we enable*/
    we_oe_reg = 0b01;
    LED_DISPLAY_mWriteReg(LED_BASE, WE_OE, we_oe_reg);
    for(int i=0; i<64; i++)
    	{

    	/* Actions go here */
    	LED_DISPLAY_mWriteReg(LED_BASE, ADDR_DATA, add_data_reg);
    	      add_data_reg = ((0x0000)<<6) | i;
    	}
    /*we disable and oe enable*/
    we_oe_reg = 0b10;
    LED_DISPLAY_mWriteReg(LED_BASE, WE_OE, we_oe_reg);
}