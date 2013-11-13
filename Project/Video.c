#include"Video.h"





void erase_frame_buffer(struct FrameBuffer* head){
	
			struct FrameBuffer *fr;
			
			while(head!=0){
				
				if(head->frame== 0) free(head->frame);
				
				fr = head->next;
				free(head);
				head = fr;
				
			}
			
			return;
	
}

void Blank_Buffer(struct FrameBuffer* head){

	struct pixel *pixar = head->frame->pixels;
	size_t i;

	for(i = 0;i< SIZE_LINE;i++){

		pixar[i].Y1 = 0;
		pixar[i].Y2 = 0;
		pixar[i].Cb = 0;
		pixar[i].Cr = 0;

	}

}

struct FrameBuffer * init_video(size_t buffer_size){
		
		struct FrameBuffer * buff;
		struct FrameBuffer * head;
		size_t i ;
		
		if(buffer_size == 0) return 0;
		
		head = (struct FrameBuffer *) malloc( sizeof(struct FrameBuffer) );
		if(head==0) return 0;
		head->frame = (struct VideoFrame *) malloc( sizeof(struct VideoFrame) );
		
		if(head->frame==0){
			erase_frame_buffer(head);
			return 0;
		}
		Blank_Buffer(head);
		head->next = 0;
		
		buff = head;
		
		for(i= 1; i < buffer_size ; i++){
			
				 buff->next = (struct FrameBuffer *) malloc( sizeof(struct FrameBuffer) );
				 buff = buff->next;
				 
				 if(buff->next == 0){ 
							
							erase_frame_buffer(head);
							return 0;
				 }
				 
				 buff->frame = (struct VideoFrame *) malloc( sizeof(struct VideoFrame) );
				 
				 if(buff->frame == 0){ 
							
							erase_frame_buffer(head);
							return 0;
				 }
				 
			   Blank_Buffer(buff);
			   buff->next = 0;
				  
		}
	
		buff->next = head;
		return head;
	
}


