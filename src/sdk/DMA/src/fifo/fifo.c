

#include "fifo.h"




float samples_In[MAX_DATA_BUFFER_SIZE];

static int count=0;

XStatus fnInitFifo(XLlFifo *psFifo, u16 DeviceId){

	int Status;
	Status = XST_SUCCESS;
	XLlFifo_Config *Config;

	/* Initialize the Device Configuration Interface driver */
	Config = XLlFfio_LookupConfig(DeviceId);
	if (!Config) {
		xil_printf("No config found for %d\r\n", DeviceId);
		return XST_FAILURE;
	}

	/*
	 * This is where the virtual address would be used, this example
	 * uses physical address.
	 */
	Status = XLlFifo_CfgInitialize(psFifo, Config,Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("Initialization failed\n\r");
		return Status;
	}

	/* Check for the Reset value */

	Status = XLlFifo_Status(psFifo);
	XLlFifo_IntClear(psFifo,0xFFFFFFFF);
	Status = XLlFifo_Status(psFifo);
	if(Status != 0x0) {
		xil_printf("\n ERROR : Reset value of ISR0 : 0x%x\t"
			    "Expected : 0x0\n\r",
			    XLlFifo_Status(psFifo));
		return XST_FAILURE;
	}


	 return XST_SUCCESS;



}

/*****************************************************************************/
/**
*
* This is the interrupt handler for the fifo it checks for the type of interrupt
* and proceeds according to it.
*
* @param	InstancePtr is a reference to the Fifo device instance.
*
* @return	None.
*
* @note		None.
*
******************************************************************************/

void FifoHandler(XLlFifo *InstancePtr)
{
	u32 Pending;


		Pending = XLlFifo_IntPending(InstancePtr);
		while (Pending)
		{
			if (Pending & XLLF_INT_ERROR_MASK){
				FifoErrorHandler(InstancePtr, Pending);
				XLlFifo_IntClear(InstancePtr, XLLF_INT_ERROR_MASK);

			}
			else if (Pending & XLLF_INT_TC_MASK) {

					FifoSendHandler(InstancePtr);
					XLlFifo_IntClear(InstancePtr,Pending);

				}
			else if (Pending &   (XLLF_INT_RC_MASK | XLLF_INT_RFPF_MASK) )
			{
				FifoStreamHandler(InstancePtr);
				XLlFifo_IntClear(InstancePtr, (XLLF_INT_RC_MASK | XLLF_INT_RFPF_MASK) );


			}

			else
			{
				XLlFifo_IntClear(InstancePtr,Pending);
			}

			Pending = XLlFifo_IntPending(InstancePtr);
		}
}






/*****************************************************************************/
/**
*
* This is the Receive handler and Tx handler callback function.
*
* Description: stream  NR_AUDIO_SAMPLES from receive FIFO to DMA
*
* @param	InstancePtr is a reference to the Fifo device instance.
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
 void FifoStreamHandler(XLlFifo *InstancePtr)
{


	 	int i;
	 	u32 RxWord;
	 	static u32 ReceiveLength;
	 	int j;
	 	int txVancanccy;


	 	count=0;

	 	// checking the occupancy
	 	while(XLlFifo_iRxOccupancy(InstancePtr)>2)
	 	{

	 		//Read RLR to find the number of bytes
		    ReceiveLength = (XLlFifo_iRxGetLen(InstancePtr))/WORD_SIZE;



			for (i=0; i < ReceiveLength; i++)
				 {


						RxWord = XLlFifo_RxGetWord(InstancePtr);
						*(samples_In+i) = RxWord;
						words_number+=4;

						count+=1;
				 }



			//check TDFV for the FIFO occupancy before writing to the TX FIFO
			txVancanccy=Xil_In32((InstancePtr->BaseAddress) + XLLF_TDFV_OFFSET);

			/* to set transmit destination address */
			Xil_Out32(((InstancePtr->BaseAddress) + XLLF_TDR_OFFSET), 0x00000002);




			if(txVancanccy)
				{
					for (j=0; j < ReceiveLength ; j++)
						{
								/* to write data in the transmit data FIFO data write port, eight words */
								Xil_Out32(((InstancePtr->BaseAddress) + XLLF_TDFD_OFFSET), *(samples_In+j));

						}
				}

			if(words_number > (NR_AUDIO_SAMPLES*5))
					{
						/* Start Transmission by writing transmission length into the TLR */
						XLlFifo_iTxSetLen(InstancePtr,words_number);
							fifo_done=1;
							/* Disable the interrupt for the FIFO*/
							XLlFifo_IntDisable(InstancePtr,XLLF_INT_ALL_MASK);
							return;
					}




		 }




}


/*****************************************************************************/
/**
*
* This is the Error handler callback function and this function increments the
* the error counter so that the main thread knows the number of errors.
*
* @param	InstancePtr is a pointer to Instance of AXI FIFO device.
*
* @param	Pending is a bitmask of the pending interrupts.
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
  void FifoErrorHandler(XLlFifo *InstancePtr, u32 Pending)
 {
 	if (Pending & XLLF_INT_RPURE_MASK) {
 		XLlFifo_RxReset(InstancePtr);
 	} else if (Pending & XLLF_INT_RPORE_MASK) {
 		XLlFifo_RxReset(InstancePtr);
 	} else if(Pending & XLLF_INT_RPUE_MASK) {
 		XLlFifo_RxReset(InstancePtr);
 	} else if (Pending & XLLF_INT_TPOE_MASK) {
 		XLlFifo_TxReset(InstancePtr);
 	} else if (Pending & XLLF_INT_TSE_MASK) {
 		XLlFifo_TxReset(InstancePtr);
 	}

 }


  /*****************************************************************************/
  /*
  *
  * This is the transfer Complete Interrupt handler function.
  *
  * This clears the transmit complete interrupt and set the done flag.
  *
  * @param	InstancePtr is a pointer to Instance of AXI FIFO device.
  *
  * @return	None
  *
  * @note		None
  *
  ******************************************************************************/
   void FifoSendHandler(XLlFifo *InstancePtr)
  {
	   XLlFifo_IntClear(InstancePtr, XLLF_INT_TC_MASK);

  }