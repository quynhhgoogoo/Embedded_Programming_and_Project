#include <gtest/gtest.h>
#include "ringbuffer.h"
#include <string.h>

/*test case for initializing buffer*/
TEST(Init_Buffer,Normal)
{
		unsigned char received_buffer[BUFFER_SIZE];
    	struct buffer_type rb;

    	init_buffer(&rb,received_buffer,BUFFER_SIZE);

    	EXPECT_EQ(rb.head,received_buffer);
    	EXPECT_EQ(rb.tail,received_buffer);
    	EXPECT_EQ(rb.beginning,received_buffer);
		EXPECT_EQ(rb.end,received_buffer+BUFFER_SIZE-1);
}

TEST(Init_Buffer, Full_Buffer)
{
		unsigned char received_buffer[BUFFER_SIZE];
		struct buffer_type rb;
		rb.head == rb.end;
    	init_buffer(&rb,received_buffer,BUFFER_SIZE);
    	EXPECT_EQ(rb.head,received_buffer);
    	EXPECT_EQ(rb.tail,received_buffer);
    	EXPECT_EQ(rb.beginning,received_buffer);
		EXPECT_EQ(rb.end,received_buffer+BUFFER_SIZE-1);
}

TEST(Init_Buffer, Duplicated_String)
{
		unsigned char received_buffer1[BUFFER_SIZE];
		unsigned char received_buffer2[BUFFER_SIZE];
		struct buffer_type rb;
    	init_buffer(&rb,received_buffer1,BUFFER_SIZE);
		init_buffer(&rb,received_buffer2,BUFFER_SIZE);
    	EXPECT_EQ(rb.head, received_buffer2);
    	EXPECT_EQ(rb.tail, received_buffer2);
    	EXPECT_EQ(rb.beginning, received_buffer2);
		EXPECT_EQ(rb.end,received_buffer2+BUFFER_SIZE-1);
}

/*test case for empty buffer function*/
TEST(Empty_Buffer,Normal)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
	init_buffer(&rb,received_buffer,BUFFER_SIZE);
	empty_buffer(&rb);
    EXPECT_EQ(rb.head,received_buffer);
    EXPECT_EQ(rb.tail,received_buffer);
    EXPECT_EQ(rb.beginning,received_buffer);
    EXPECT_EQ(rb.end,received_buffer+BUFFER_SIZE-1);
}

TEST(Empty_Buffer,Buffer_Full)
{
	unsigned char received_buffer[BUFFER_SIZE];
	int i,j;
	struct buffer_type rb1;
	struct buffer_type rb2;
	init_buffer(&rb1,received_buffer,BUFFER_SIZE);
	rb2.tail = rb1.tail;
	rb2.head = rb1.head;
	rb2.end = rb1.end;
	rb2.beginning = rb1.beginning;
	empty_buffer(&rb1);
    EXPECT_EQ(rb1.head,rb2.head);
    EXPECT_EQ(rb1.tail,rb2.tail);
    EXPECT_EQ(rb1.beginning,rb2.beginning);
    EXPECT_EQ(rb1.end,rb2.end);
}

/*Get Buffer State Function*/
TEST(Get_Buffer_State,Normal)
{
    unsigned char received_buffer[BUFFER_SIZE];
    struct buffer_type rb;
	error_type err;
	rb.head = received_buffer+2;
	rb.tail = received_buffer;
	rb.beginning = received_buffer;
	rb.end = received_buffer + BUFFER_SIZE -1;
	int len = get_buffer_state(&rb,&err);
	EXPECT_EQ(2,len);
	EXPECT_EQ(err,OK);
}

TEST(Get_Buffer_State,Empty_Buffer)
{
        unsigned char received_buffer[BUFFER_SIZE];
        struct buffer_type rb;
        error_type err;
        rb.head = received_buffer;
        rb.tail = received_buffer;
        rb.beginning = received_buffer;
        rb.end = received_buffer+BUFFER_SIZE-1;
        int len = get_buffer_state(&rb,&err);
        EXPECT_EQ(0,len);
        EXPECT_EQ(err,EMPTY_BUFFER);
}

TEST(Get_Buffer_State,Buffer_Full)
{
    unsigned char received_buffer[BUFFER_SIZE];
    struct buffer_type rb;
    error_type err;
	rb.head = received_buffer + BUFFER_SIZE - 2;
	rb.tail = received_buffer + BUFFER_SIZE - 1;
	rb.beginning = received_buffer;
	rb.end = received_buffer+BUFFER_SIZE-1;
    int len = get_buffer_state(&rb,&err);
    EXPECT_EQ(BUFFER_SIZE-1,len);
    EXPECT_EQ(err, BUFFER_FULL);
}

TEST(Get_Buffer_State,Pointer_error)
{
    unsigned char received_buffer[BUFFER_SIZE];
    struct buffer_type rb;
    error_type err;
    rb.head = received_buffer + BUFFER_SIZE + 1;
    rb.tail = received_buffer;
	rb.beginning = received_buffer;
    rb.end = received_buffer+BUFFER_SIZE-1;
    int len = get_buffer_state(&rb,&err);
    EXPECT_EQ(-1,len);
    EXPECT_EQ(err, POINTER_ERROR);
}

/*Adding char to buffer function*/
TEST(Add_Char_To_Buffer,Normal)
{
		unsigned char letter = 'q';
        unsigned char received_buffer[BUFFER_SIZE];
        struct buffer_type rb;
        error_type err;
		rb.head = received_buffer + BUFFER_SIZE-2;
        rb.tail = received_buffer;
        rb.beginning = received_buffer;
        rb.end = received_buffer+BUFFER_SIZE-1;
		received_buffer[0] = 'a';
		int len = add_char_to_buffer(&rb,letter,&err);
		EXPECT_EQ(BUFFER_SIZE-1,len);
		EXPECT_EQ('q',received_buffer[BUFFER_SIZE-2]);
		EXPECT_EQ(OK,err);
}

TEST(Add_Char_To_Buffer,Buffer_Full)
{
        unsigned char letter = 'q';
        unsigned char received_buffer[BUFFER_SIZE];
        struct buffer_type rb;
        error_type err;
        rb.head = received_buffer + BUFFER_SIZE - 2;
        rb.tail = received_buffer + BUFFER_SIZE - 1;
        rb.beginning = received_buffer;
        rb.end = received_buffer+BUFFER_SIZE-1;
		received_buffer[BUFFER_SIZE - 2] = 0;
        int len = add_char_to_buffer(&rb,letter,&err);
        EXPECT_EQ(-1,len);
        EXPECT_EQ('\0',received_buffer[BUFFER_SIZE - 2]);
		EXPECT_EQ(BUFFER_FULL,err);
}

TEST(Add_Char_To_Buffer,Pointer_error)
{
    unsigned char letter = 'q';
    unsigned char received_buffer[BUFFER_SIZE];
    struct buffer_type rb;
    error_type err;
    rb.head = received_buffer + BUFFER_SIZE + 1;
    rb.tail = received_buffer;
    rb.beginning = received_buffer;
    rb.end = received_buffer+BUFFER_SIZE-1;
    received_buffer[0] = 'a';
    int len = add_char_to_buffer(&rb,letter,&err);
    EXPECT_EQ(-1,len);
    EXPECT_EQ('a',received_buffer[0]);
    EXPECT_EQ(POINTER_ERROR,err);
}

/*Getting char from buffer function*/
TEST(Get_Char_From_Buffer, Normal)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
	error_type err;
	unsigned char state;
	rb.head = received_buffer+1022;
	rb.tail = received_buffer;
	rb.beginning = received_buffer;
	rb.end = received_buffer+BUFFER_SIZE-1;
    received_buffer[0] = 'a';
	state = get_char_from_buffer(&rb, &err);
	EXPECT_EQ('a',state);
	EXPECT_EQ(OK,err);
}

TEST(Get_Char_From_Buffer, Empty_Buffer)
{
        unsigned char received_buffer[BUFFER_SIZE];
        struct buffer_type rb;
        error_type err;
        unsigned char state;
        rb.head = received_buffer;
        rb.tail = received_buffer;
        rb.beginning = received_buffer;
        rb.end = received_buffer+BUFFER_SIZE-1;
        received_buffer[0] = 'a';
        state = get_char_from_buffer(&rb, &err);
        EXPECT_EQ((unsigned char)-1,state);
        EXPECT_EQ(EMPTY_BUFFER,err);
}

TEST(Get_Char_From_Buffer, Pointer_error)
{
        unsigned char received_buffer[BUFFER_SIZE];
        struct buffer_type rb;
        error_type err;
        unsigned char state;
        rb.head = received_buffer + BUFFER_SIZE + 1;
        rb.tail = received_buffer;
        rb.beginning = received_buffer;
        rb.end = received_buffer+BUFFER_SIZE-1;
        received_buffer[0] = 'a';
		state = get_char_from_buffer(&rb, &err);
        EXPECT_EQ((unsigned char)-1,state);
        EXPECT_EQ(POINTER_ERROR,err);
}

TEST(Get_Char_From_Buffer, Buffer_Full)
{
    unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
	error_type err;
	unsigned char state;
	rb.tail = rb.head = received_buffer + 1000;
	rb.beginning = received_buffer;
	rb.end = received_buffer+BUFFER_SIZE-1;
    received_buffer[0] = 'a';
	state = get_char_from_buffer(&rb, &err);
	EXPECT_EQ((unsigned char)-1,state);
	EXPECT_EQ(EMPTY_BUFFER,err);
}

/*Print Buffer Test Case*/
TEST(PrintBuffer, Normal)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
    error_type err = OK;
	int amount = 0;
	rb.head = received_buffer + BUFFER_SIZE-2;
	rb.tail = received_buffer;
	rb.end = received_buffer + BUFFER_SIZE -1;
	rb.beginning = received_buffer;
    received_buffer[0] = 'a';
	amount = print_buffer(rb, &err);
	EXPECT_EQ(BUFFER_SIZE-2, amount);
}

TEST(PrintBuffer, EmptyBuffer)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
    error_type err = OK;
	int amount = 0;
	rb.head = received_buffer;
	rb.tail = received_buffer;
	rb.end = received_buffer + BUFFER_SIZE -1;
	rb.beginning = received_buffer;
	amount = print_buffer(rb, &err);
	EXPECT_EQ(0, amount);
	EXPECT_EQ(EMPTY_BUFFER, err);
}

TEST(PrintBuffer, ErrorInput)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
    error_type err = POINTER_ERROR;
	int amount = 0;
	rb.head = received_buffer;
	rb.tail = received_buffer+50;
	rb.end = received_buffer + BUFFER_SIZE -1;
	rb.beginning = received_buffer;
	received_buffer[0] = 'a';
	amount = print_buffer(rb, &err);
	EXPECT_EQ(-1, amount);
	EXPECT_EQ(POINTER_ERROR, err);
}

TEST(PrintBuffer, Buffer_Full)
{
	unsigned char received_buffer[BUFFER_SIZE];
	struct buffer_type rb;
    error_type err = OK;
	int amount = 0;
	rb.head = received_buffer + BUFFER_SIZE-2;
	rb.tail = received_buffer;
	rb.end = received_buffer + BUFFER_SIZE -1;
	rb.beginning = received_buffer;
    received_buffer[0] = 'a';
	amount = print_buffer(rb, &err);
	EXPECT_EQ(rb.tail, rb.beginning);
	EXPECT_EQ(BUFFER_SIZE-2, amount);
}