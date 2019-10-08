#include "stm32f4xx_hal.h"
#include "led.h"
#include "lcd.h"
#include "ucos_ii.h"
#include "display.h"
#include "font.h"

static void SystemClock_Config(void);
static void Error_Handler(void);
static  void  AppTaskStart (void *p_arg);

#define  APP_CFG_TASK_START_STK_SIZE            256u
#define  APP_CFG_TASK_START_PRIO                3u
static  OS_STK       AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];

int main(void)
{
	HAL_Init();
	LEDInit();
	LED_Ctrl(LED0, LED_ON);
	SystemClock_Config();
	LCD_Init();
	LCD_Clear(BLACK);
//	for(uint16_t i = 0; i < 320; i++)
//	for(uint16_t j = 0; j < 240; j++)
	
//	LCD_Color_DrawPoint(j, i, RED);
//	LCD_Color_DrawPoint(50, 20, BLACK);
	DisplayFont(10, 10, &GUI_FontArial24.pProp->paCharInfo[50]);
	OSInit();
	OSTaskCreateExt( AppTaskStart,                              /* Create the start task                                */
									 0,
									&AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE - 1],
									 APP_CFG_TASK_START_PRIO,
									 APP_CFG_TASK_START_PRIO,
									&AppTaskStartStk[0],
									 APP_CFG_TASK_START_STK_SIZE,
									 0,
									(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));	
	
	OSStart();	
	return 0;
}

static  void  AppTaskStart (void *p_arg)
{
	while(1)
	{
		LED_Toggle(LED0);
		OSTimeDly(100);
	}
}



/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  while(1)
  {
  }
}
