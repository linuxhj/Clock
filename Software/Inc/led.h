#ifndef __LED_H
#define __LED_H


typedef enum
{
	LED0 = 1,
	LED1,
	LED2,
}eLED;
typedef enum
{
	LED_OFF = 0,
	LED_ON,
}eLED_MODE;
	
	
#define PORT_LED0			GPIOE
#define PIN_LED0			GPIO_PIN_3

#define PORT_LED1			GPIOE
#define PIN_LED1			GPIO_PIN_4

#define PORT_LED2			GPIOG
#define PIN_LED2			GPIO_PIN_9




void LEDInit(void);
void LED_Ctrl(eLED led_name, eLED_MODE mode);
void LED_Toggle(eLED led_name);
#endif
