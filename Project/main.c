#include"main.h"

volatile uint32_t Ticks = 0; 
struct FrameBuffer * Global_Video_Buffer;

#define BUFFER_SIZE 5


void SysTick_Handler(void) {
	
	switch(Ticks%1000){
		case 500:
			set_led(1);
			break;
		case 999:
			clear_led(1);
			break;
	}	
	Ticks++; 
		
}

	
void Delay(uint32_t t){
	
	uint32_t c ;
	c = Ticks;

	while( (Ticks - c) < t ) ;

}


int main(){

	init_LED();
	init_GPIO();
	
	SysTick_Config(SystemCoreClock / 1000);

	Global_Video_Buffer =  init_video(BUFFER_SIZE);
	if(Global_Video_Buffer) set_led( 0 );

	init_EXINT();
	
	setjmp(env_main);
	while(1);

	return 0;

}
