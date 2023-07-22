/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

/******************************** 			TIMERS			********************************/

/* : Auto-reload preload enable - options:
 * 			1: TIMx_ENABLE					TIMx_ARR register is buffered
 * 			2: TIMx_DISABLE					TIMx_ARR register is not buffered
 * 	in Normal mode: may or not to be enabled to update the shadow registers with new values
 * 	in PWM: must be enabled
 * */
#define TIM2_ARPE			TIMx_ENABLE
#define TIM3_ARPE
#define TIM4_ARPE

/* : Center-aligned mode selection - options:
 * 			1: TIMx_CMS_EDGE_ALIGNED					Edge-aligned mode (counts up or down)
 * 			2: TIMx_CMS_CENTER_ALIGNED_MODE1			 The counter counts up and down alternatively. Output compare
					interrupt flags of channels configured in output are set only when the counter is counting down.
 * 			3: TIMx_CMS_CENTER_ALIGNED_MODE2			The counter counts up and down alternatively. Output compare
					interrupt flags of channels configured in output are set only when the counter is counting up.
 * 			4: TIMx_CMS_CENTER_ALIGNED_MODE3			The counter counts up and down alternatively. Output compare
				interrupt flags of channels configured in output are set only when the counter is counting up or down.
 * */
#define TIM2_CMS				TIMx_CMS_EDGE_ALIGNED
#define TIM3_CMS				TIMx_CMS_EDGE_ALIGNED
#define TIM4_CMS				TIMx_CMS_EDGE_ALIGNED

/* Direction	options:		if it's TIMx_CMS_EDGE_ALIGNED
 * 			1: TIMx_DIR_UP					    Counter used as upcounter
 * 			2: TIMx_DIR_DOWN					Counter used as downcounter
 * */
#if TIM2_CMS == TIMx_CMS_EDGE_ALIGNED
#define TIM2_DIR					TIMx_DIR_UP
#endif

#if TIM3_CMS == TIMx_CMS_EDGE_ALIGNED
#define TIM3_DIR					TIMx_DIR_DOWN
#endif

#if TIM4_CMS == TIMx_CMS_EDGE_ALIGNED
#define TIM4_DIR					TIMx_DIR_DOWN
#endif

/* One-pulse mode	options:
 * 			1: TIMx_OPM_CONTINUE			    Counter is not stopped at update event
 * 			2: TIMx_OPM_STOP					Counter stops counting at the next update event (clearing the bit CEN)
 *
 * */
#define TIM2_OPM				TIMx_OPM_CONTINUE
#define TIM3_OPM
#define TIM4_OPM

/* Update request source	options:
 * 			1: TIMx_URS_0	    Any of the following events generate an update interrupt or DMA request if enabled.
 * 				– Counter overflow/underflow
				– Setting the UG bit
				– Update generation through the slave mode controller
 * 			2: TIMx_URS_1		Only counter overflow/underflow generates an update interrupt or DMA request if enable
 * */
#define TIM2_URS				TIMx_URS_0
#define TIM3_URS
#define TIM4_URS

/* Update disable	options:
 * 			1: TIMx_UDIS_UEV_EN			    UEV enabled. The Update (UEV) event is generated
 * 						– Counter overflow/underflow
						– Setting the UG bit
						– Update generation through the slave mode controller
 * 			2: TIMx_UDIS_UEV_DIS			UEV disabled. The Update event is not generated
 *
 * */
#define TIM2_UDIS				TIMx_UDIS_UEV_EN
#define TIM3_UDIS
#define TIM4_UDIS

//Prescaler - choose any value between 0 & 65535
#define TIM2_PRESCALER				8UL
#define TIM3_PRESCALER
#define TIM4_PRESCALER

/********************************		TIMx capture/compare mode			**********************************/
#define TIM2_CHANNEL1
/* : options:
 * 			1: TIMx_DISABLE
 * 			2: TIMx_ENABLE
 * */
#define TIM2_OC1CE					TIMx_DISABLE	// Output compare 1 clear enable
#define TIM2_OC1PE					TIMx_DISABLE	//Output compare 1 preload enable
#define TIM2_OC1FE					TIMx_DISABLE	//Output compare 1 fast enable
#define TIM2_OC2CE					TIMx_DISABLE	// Output compare 2 clear enable
#define TIM2_OC2PE					TIMx_DISABLE	//Output compare 2 preload enable
#define TIM2_OC2FE					TIMx_DISABLE	//Output compare 2 fast enable
#define TIM2_OC3CE					TIMx_DISABLE	// Output compare 3 clear enable
#define TIM2_OC3PE					TIMx_DISABLE	//Output compare 3 preload enable
#define TIM2_OC3FE					TIMx_DISABLE	//Output compare 3 fast enable
#define TIM2_OC4CE					TIMx_DISABLE	// Output compare 4 clear enable
#define TIM2_OC4PE					TIMx_ENABLE 	//Output compare 4 preload enable
#define TIM2_OC4FE					TIMx_DISABLE	//Output compare 4 fast enable

/* : Output compare x mode - options:
 * 			1: TIMx_OCxM_FROZEN	   		 Frozen - The comparison between the output compare register TIMx_CCRx and
 * 			the counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing base)
 * 			2: TIMx_OCxM_SET_ACTIVE	   	  	 Set channel x to active level on match. OCxREF signal is forced high
 * 			when the counter TIMx_CNT matches the capture/compare register x (TIMx_CCRx).
 * 			3: TIMx_OCxM_SET_INACTIVE  	  	 Set channel x to inactive level on match. OCxREF signal is forced low
 * 			when the counter TIMx_CNT matches the capture/compare register x (TIMx_CCRx).
 * 			4: TIMx_OCxM_TOGGLE  	  	 OCxREF toggles when TIMx_CNT=TIMx_CCRx
 * 			5: TIMx_OCxM_FORCE_INACTIVE 	  	 - OCxREF is forced low
 * 			6: TIMx_OCxM_FORCE_ACTIVE 	  	 - OCxREF is forced high
 * 			7: TIMx_OCxM_PWM_MODE1 	  	 - In upcounting, channel x is active as long as TIMx_CNT<TIMx_CCRx
								else inactive. In downcounting, channel x is inactive (OCxREF=‘0) as long as
								TIMx_CNT>TIMx_CCRx else active (OCxREF=1)
			8: TIMx_OCxM_PWM_MODE2 	  	 - In upcounting, channel x is inactive as long as TIMx_CNT<TIMx_CCRx
								else active. In downcounting, channel x is active as long as TIMx_CNT>TIMx_CCRx
								else inactive
 * */
#define TIM2_OC1M						TIMx_OCxM_FROZEN
#define TIM2_OC2M						TIMx_OCxM_FROZEN
#define TIM2_OC3M						TIMx_OCxM_FROZEN
#define TIM2_OC4M						TIMx_OCxM_PWM_MODE1

/* : Capture/Compare x selection - options:
 * 			1: TIMx_CCxS_OUTPUT			   		CCx channel is configured as output
 * 			2: TIMx_CCxS_INPUT1		    	  	 CCx channel is configured as input, ICx is mapped on TIx
 * 			3: TIMx_CCxS_INPUT2					CC2 channel is configured as input, IC2 is mapped on TIx
 * 			4: TIMx_CCxS_INPUT3
 * */
#define TIM2_CC1S						TIMx_CCxS_OUTPUT
#define TIM2_CC2S						TIMx_CCxS_OUTPUT
#define TIM2_CC3S						TIMx_CCxS_OUTPUT
#define TIM2_CC4S						TIMx_CCxS_OUTPUT

/* : Capture/Compare x output polarity - options:
 * 			1: TIMx_CCxP_HIGH			   		OCx active high configured as output
 * 			2: TIMx_CCxP_LOW		    	  	 OCx active low configured as output
 * */
#define TIM2_CC1P						TIMx_CCxP_HIGH
#define TIM2_CC2P						TIMx_CCxP_HIGH
#define TIM2_CC3P						TIMx_CCxP_HIGH
#define TIM2_CC4P						TIMx_CCxP_HIGH

/* : Capture/Compare x output enable - options:
 * 			1: TIMx_CCxE_OFF	  		OCx is not active. channel configured as output
 * 			2: TIMx_CCxE_ON		    OCx signal is output on the corresponding output pin. channel configured as output
 * */
#define TIM2_CC1E						TIMx_CCxE_OFF
#define TIM2_CC2E						TIMx_CCxE_OFF
#define TIM2_CC3E						TIMx_CCxE_OFF
#define TIM2_CC4E						TIMx_CCxE_ON

#endif
