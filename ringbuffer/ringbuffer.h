#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define BUFFER_OK 1
#define ERROR -1

//unsigned char receive_buffer[BUFFER_SIZE];

struct buffer_type{
	unsigned char *head;	
	unsigned char *tail;
	unsigned char *beginning;
	unsigned char *end;
};

/*creating condition for errors*/
typedef enum error_type{
	OK,	 	/*no errors*/
	BUFFER_OVER_FLOW,
	EMPTY_BUFFER,
	POINTER_ERROR,
	BUFFER_FULL
}error_type;

/*initializes the buffer, placing pointers to beginning of buffer*/
void init_buffer(struct buffer_type *b, unsigned char *buffer, int buffer_size);

/*refresh buffer*/
void empty_buffer(struct buffer_type *b);

/*check buffer status*/
int get_buffer_state(struct buffer_type *b, error_type *err);

/*adding a character to buffer*/
int  add_char_to_buffer(struct buffer_type *b,  unsigned char c, error_type *err);

/*getting one character from buffer*/
char get_char_from_buffer(struct buffer_type *b, error_type *err);

/*list character from buffer*/
int print_buffer(struct buffer_type b, error_type *err);

/*additional function*/
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err);

/*get number of characters to be read from buffer by parameter*/
int  get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err);
