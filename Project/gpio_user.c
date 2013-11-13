#include<gpio_user.h>
#include<stm32f4xx.h>
#include<stm32f4xx_gpio.h>



void init_LED(void){

	
	GPIO_InitTypeDef init_led ;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	init_led.GPIO_Pin = 	GPIO_Pin_15 | 
				GPIO_Pin_14 | 
				GPIO_Pin_13 | 
				GPIO_Pin_12;

	init_led.GPIO_Mode  = GPIO_Mode_OUT;
	init_led.GPIO_Speed  = GPIO_OType_PP;
	init_led.GPIO_OType = GPIO_Speed_50MHz;
	init_led.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &init_led); 
	
}


void init_GPIO(void){

	GPIO_InitTypeDef input_struct ;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	input_struct.GPIO_Pin = GPIO_Pin_3 | 
				GPIO_Pin_2 | 
				GPIO_Pin_1 | 
				GPIO_Pin_0;

	input_struct.GPIO_Mode  = GPIO_Mode_IN;
	input_struct.GPIO_Speed  = GPIO_OType_PP;
	input_struct.GPIO_OType = GPIO_Speed_100MHz;
	input_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &input_struct); 
	GPIO_Init(GPIOA, &input_struct); 


}



void set_led(int led){


	switch(led){


		case 0 :

			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			break;

		case 1 : 
		
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			break;

		case 2 : 

			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			break;

		case 3 :
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			break;
	}

	return;

}


void clear_led(int led){


	switch(led){


		case 0 :

			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
			break;

		case 1 : 
		
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
			break;

		case 2 : 

			GPIO_ResetBits(GPIOD, GPIO_Pin_13);
			break;

		case 3 :
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);
			break;
	}

	return;

}


