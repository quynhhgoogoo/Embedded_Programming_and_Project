#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringbuffer.h"

/*initializes the buffer, placing pointers to beginning of buffer*/
void init_buffer(struct buffer_type *b, unsigned char *buffer, int buffer_size){
	b->head = buffer;
	b->tail = buffer;
	b->beginning = buffer;
	b->end = buffer + BUFFER_SIZE - 1;
	//int buffer_size = MAX_BUFFER;
	for(int i=0; i<BUFFER_SIZE; i++){
		*(buffer+i)=0;
	}
}

/*refresh buffer*/
void empty_buffer(struct buffer_type *b){
	b->tail=b->head;
}

/*check buffer status*/
int get_buffer_state(struct buffer_type *b, error_type *err){
	int len = 0;
	if(b->head == b->tail-1||(b->head == b->end && b->tail == b->beginning)){
	 	*err = BUFFER_FULL;
		len = BUFFER_SIZE -1;
	}else if(b->tail == b->head){
		*err = EMPTY_BUFFER;
		len = 0;
	}else if(b->head > b->end || b->tail > b->end|| b->tail < b->beginning || b->head > b->beginning){
		*err = POINTER_ERROR;
		len = -1;
	}else if (b->tail < b->end){
		while(b->tail != b->head){
			if(b->tail == b->end){
				b->tail == b->beginning;
			}else{
				b->tail++;
			}
			len++;
			*err = OK;
		}
	}else{
		len = -1;
	}
	return len;	
}

/*adding character to buffer
*function will return 
 *     amount of character in buffer
 *     -1 in error conditon, err for more info*/

int add_char_to_buffer(struct buffer_type *b, unsigned char c, error_type *err){
	*err = OK;
	int num = get_buffer_state(b, err);
	/*check buffer state*/
	if(*err==POINTER_ERROR || *err == BUFFER_OVER_FLOW || *err == BUFFER_FULL){
		return -1;
	}else{
		*(b->head)=c;
		if(b->head != b->end){
			b->head++;
		}
		else{
			b->head = b->beginning;
		}
		num++;
		return num; 
	}
}

/*getting one character from buffer
 * function will return 
 *     character read from buffer
 *     -1 - in error condition,  err more info of error*/
char get_char_from_buffer(struct buffer_type *b, error_type *err){
	*err = OK;
	unsigned char c = 0;
	if(*err==POINTER_ERROR || *err == BUFFER_OVER_FLOW || *err == BUFFER_FULL){
		return -1;
	}else{
		c = *(b->tail);
	}
	return c;
}

/*Additional function*/
/*add character to function*/
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err){

}
/*list characters from buffer*/
int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err){

}
