#include<interrupt.h>
#include<stm32f4xx.h>
#include<stm32f4xx_gpio.h>
#include<stm32f4xx_exti.h>
#include<stm32f4xx_syscfg.h>
#include<misc.h>
#include<setjmp.h>



//Vars

static jmp_buf env_start;
static jmp_buf env_ret;

// MACROS

#define I_DATA  ( (uint8_t)  ( (GPIO_ReadInputData(GPIOA) & 0x0F) | ( GPIO_ReadInputData(GPIOD) << 0x04 ) ) )

#define HOLD_START	if( !setjmp(env_start) ) return
#define RETURN longjmp(env_ret,1)
#define HOLD	if( !setjmp(env_start) ) RETURN
#define RESUME   if( !setjmp(env_ret) ) longjmp(env_start,1)

#define CHECK(var) \
   if(data == var ) HOLD;\
	else { \
		HOLD; \
		goto start;\
	}

#define CHECK_FOR_VALID \
	if(data == 0 || data == 0xFF ) { \
		RETURN; \
		goto start;\
	} else RETURN 

//IMP
void do_magic(void);

void init_EXINT(void){
	
	
	EXTI_InitTypeDef EXTI_InitStructure;
	GPIO_InitTypeDef input_struct ;

	input_struct.GPIO_Pin = GPIO_Pin_15;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	input_struct.GPIO_Mode  = GPIO_Mode_IN;
	input_struct.GPIO_Speed  = GPIO_OType_PP;
	input_struct.GPIO_OType = GPIO_Speed_100MHz;
	input_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &input_struct); 


	

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource15);

	EXTI_InitStructure.EXTI_Line = EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	do_magic(); // Does nothing, just set function env start
}



static uint8_t data;

void do_magic(void){

	static uint32_t hc = 0;
	static uint32_t line = 0;
	HOLD_START;

start :
// -------------------- Field 1 - First Vertical Blanking --------------------

	for(line=0;line<19;line++){
		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(182);


		for(hc=0;hc<67;hc++) { //BLANKING
		/*	CHECK(128)
			CHECK(16)	*/
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
		}

		//SAV
		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(171);

		// ACTIVE VIDEO

		for(hc=0;hc<360;hc++){
	/*
			set_blue(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			set_gamma1(Global_Video_Buffer,repeat,data);		
			CHECK_FOR_VALID;
			set_red(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			set_gamma2(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			*/
			CHECK_FOR_VALID;	
	
		}
	
	}

	// -------------------- FIELD1 --------------------
	
	for(line=0;line<240;line++) {

		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(157);

		for(hc=0;hc<67;hc++) { //BLANKING
			/*	CHECK(128)
				CHECK(16)	*/
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
			}

		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(128);

		//VIDEO
		for(hc=0;hc<360;hc++){

				set_blue(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
				set_gamma1(Global_Video_Buffer,hc,data);		
				CHECK_FOR_VALID;
				set_red(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
				set_gamma2(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
	
			}


		Global_Video_Buffer = Global_Video_Buffer->next; // FALTA CHECAR ERRORES
	
	
	}
	
// -------------------- Field 1 - Second Vertical Blanking --------------------

	for(line=0;line<3;line++){
		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(182);


		for(hc=0;hc<67;hc++) { //BLANKING
		/*	CHECK(128)
			CHECK(16)	*/
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
		}

		//SAV
		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(171);

		// ACTIVE VIDEO

		for(hc=0;hc<360;hc++){
	/*
			set_blue(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			set_gamma1(Global_Video_Buffer,repeat,data);		
			CHECK_FOR_VALID;
			set_red(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			set_gamma2(Global_Video_Buffer,repeat,data);
			CHECK_FOR_VALID;
			*/
			CHECK_FOR_VALID;	
	
		}
	
	}	

// -------------------- Field 2 - First Vertical Blanking --------------------

	for(line=0;line<20;line++){
		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(241);


		for(hc=0;hc<67;hc++) { //BLANKING
		/*	CHECK(128)
			CHECK(16)	*/
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
		}

		//SAV
		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(236);

		// ACTIVE VIDEO

		for(hc=0;hc<360;hc++){
			CHECK_FOR_VALID;	
	
		}
	
	}

	// -------------------- FIELD2 --------------------
	
	for(line=0;line<240;line++) {

		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(218);

		for(hc=0;hc<67;hc++) { //BLANKING
			/*	CHECK(128)
				CHECK(16)	*/
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
				CHECK_FOR_VALID;
			}
		//SAV CODE

		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(199);

		//VIDEO
		for(hc=0;hc<360;hc++){

				set_blue(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
				set_gamma1(Global_Video_Buffer,hc,data);		
				CHECK_FOR_VALID;
				set_red(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
				set_gamma2(Global_Video_Buffer,hc,data);
				CHECK_FOR_VALID;
	
			}


		Global_Video_Buffer = Global_Video_Buffer->next; // FALTA CHECAR ERRORES
	
	
	}

// -------------------- Field 2 - Second Vertical Blanking --------------------

	for(line=0;line<3;line++){
		//EAV CODE
		CHECK(255);
		CHECK(0);
		CHECK(0);
		CHECK(241);


		for(hc=0;hc<67;hc++) { //BLANKING
		/*	CHECK(128)
			CHECK(16)	*/
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
			CHECK_FOR_VALID;
		}

		//SAV
		CHECK(255);	
		CHECK(0);
		CHECK(0);
		CHECK(236);

		// ACTIVE VIDEO

		for(hc=0;hc<360;hc++){
			CHECK_FOR_VALID;	
	
		}
	
	}

	goto  start;

}

void EXTI15_10_IRQHandler(void){

	data = I_DATA;

	RESUME; // Resume  do_magic();

	EXTI_ClearITPendingBit(EXTI_Line15);

	return;

}



