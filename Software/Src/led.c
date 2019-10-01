#include "stm32f4xx_hal.h"
#include "led.h"


void LEDInit(void)
{
  GPIO_InitTypeDef   GPIO_InitStructure;

  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = PIN_LED0;
  HAL_GPIO_Init(PORT_LED0, &GPIO_InitStructure);

  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = PIN_LED1;
  HAL_GPIO_Init(PORT_LED1, &GPIO_InitStructure);

	
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = PIN_LED2;
  HAL_GPIO_Init(PORT_LED2, &GPIO_InitStructure);	
	
	HAL_GPIO_WritePin(PORT_LED0, PIN_LED0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PORT_LED1, PIN_LED1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PORT_LED2, PIN_LED2, GPIO_PIN_SET);
}

void LED_Ctrl(eLED led_name, eLED_MODE mode)
{
	if(mode != 0)
	{
		switch (led_name)
		{
			case LED0:
				HAL_GPIO_WritePin(PORT_LED0, PIN_LED0, GPIO_PIN_RESET);
				break;
			case LED1:
				HAL_GPIO_WritePin(PORT_LED1, PIN_LED1, GPIO_PIN_RESET);
				break;
			case LED2:
				HAL_GPIO_WritePin(PORT_LED2, PIN_LED2, GPIO_PIN_RESET);
				break;
			default:
				break;
		}
	}
	else
	{
		switch (led_name)
		{
			case LED0:
				HAL_GPIO_WritePin(PORT_LED0, PIN_LED0, GPIO_PIN_SET);
				break;
			case LED1:
				HAL_GPIO_WritePin(PORT_LED1, PIN_LED1, GPIO_PIN_SET);
				break;
			case LED2:
				HAL_GPIO_WritePin(PORT_LED2, PIN_LED2, GPIO_PIN_SET);
				break;
			default:
				break;	
		}			
	}
}
