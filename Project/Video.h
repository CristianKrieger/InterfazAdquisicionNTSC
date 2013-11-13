#include<stdint.h>
#include<setjmp.h>
#include<stdlib.h>

// Types and decl

#define VIDEO_BUFFER_LINES 240
#define SIZE_LINE 360




struct pixel {
	
	int8_t Y1;
	int8_t Y2;	
	int8_t Cb;
	int8_t Cr;
	
};

#define set_gamma1(buffer,index,val) buffer->frame->pixels[index].Y1=val 
#define set_gamma2(buffer,index,val) buffer->frame->pixels[index].Y2=val 
#define set_blue(buffer,index,val) buffer->frame->pixels[index].Cb=val 
#define set_red(buffer,index,val) buffer->frame->pixels[index].Cr=val
																
																
#define get_pixel(buffer,x)  &(buffer->frame.pixels[x])




struct VideoFrame{
	
				struct pixel pixels[SIZE_LINE];
				
};

struct FrameBuffer{
		
			struct VideoFrame *frame;
			struct FrameBuffer* next ;
			
};

//-----------------------------------------


// Global Vars

//------------------------------------


//Functions 



struct FrameBuffer * init_video(size_t buffer_size);




//--------------------------------------


