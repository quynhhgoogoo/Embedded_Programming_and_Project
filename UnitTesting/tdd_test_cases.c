#include <gtest/gtest.h>
#include <string.h>
#include "ringbuffer.h"

TEST(InitBuffer, TestCase1)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	init_buffer(&b, receive_buffer);
	EXPECT_EQ(b.head,receive_buffer);
	EXPECT_EQ(b.tail,receive_buffer);
	EXPECT_EQ(b.buffer,receive_buffer);	
}

TEST(EmptyBuffer, TestCase1)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	error_type err;
	b.buffer = receive_buffer;
	b.tail = b.buffer + 5;
	b.head = b.buffer + 15;
	err = empty_buffer(&b);
	EXPECT_EQ(b.head, b.tail); 
	EXPECT_EQ(b.buffer+15, b.head); 
	EXPECT_EQ(err, OK);
}


TEST(GetBufferState, ErrorInput)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	error_type err = BUFFER_OVER_FLOW;	
	b.head = receive_buffer+2;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	EXPECT_EQ(-1, get_buffer_state(&b, &err));
	EXPECT_EQ(err, BUFFER_OVER_FLOW);

}


TEST(GetBufferState, EmptyBuffer)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	error_type err = OK;	
	b.head = receive_buffer;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	EXPECT_EQ(0, get_buffer_state(&b, &err));
	EXPECT_EQ(err, EMPTY_BUFFER);

}

TEST(GetBufferState, TestCase)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	error_type err = OK;	
	b.head = receive_buffer+2;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	EXPECT_EQ(2, get_buffer_state(&b, &err));
	EXPECT_EQ(err, OK);

}

TEST(GetBufferState, PointerError)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	buffer_type b;
	error_type err = OK;	
	b.head = receive_buffer+BUFFER_SIZE+1;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	EXPECT_EQ(-1, get_buffer_state(&b, &err));
	EXPECT_EQ(err, POINTER_ERROR);

}

TEST(AddCharToBuffer, TestCase)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
	int i;
	unsigned char c ='o';
	b.buffer = receive_buffer;
	b.tail = receive_buffer+5;
	b.head = receive_buffer+255;
	error_type err = OK;

	i = add_char_to_buffer(&b,c,&err);
	EXPECT_EQ(251,i);
	EXPECT_EQ(b.head,receive_buffer);
	EXPECT_EQ(b.tail,receive_buffer+5);
	EXPECT_EQ(b.buffer,receive_buffer);
	EXPECT_EQ(receive_buffer[0],'a');	
}

TEST(AddCharToBuffer, BufferFull)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
	int i;
	unsigned char c ='o';

	b.buffer = receive_buffer;
	b.tail = receive_buffer;
	b.head = receive_buffer+BUFFER_SIZE-2;
	error_type err = OK;
	i = add_char_to_buffer(&b,c,&err);
	EXPECT_EQ(255,i);
	EXPECT_EQ(b.head,receive_buffer+BUFFER_SIZE-1);
	EXPECT_EQ(b.tail,receive_buffer);
	EXPECT_EQ(b.buffer,receive_buffer);
	EXPECT_EQ(receive_buffer[BUFFER_SIZE-2],'o');	
	EXPECT_EQ(err, BUFFER_FULL);

}

TEST(AddCharToBuffer, BufferOverFlow)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
	int i;
	unsigned char c ='o';

	b.buffer = receive_buffer;
	b.tail = receive_buffer;
	b.head = receive_buffer+BUFFER_SIZE-1;
	error_type err = BUFFER_FULL;
	i = add_char_to_buffer(&b,c,&err);
	EXPECT_EQ(255,i);
	EXPECT_EQ(b.head,receive_buffer+BUFFER_SIZE-1);
	EXPECT_EQ(b.tail,receive_buffer);
	EXPECT_EQ(b.buffer,receive_buffer);
	EXPECT_EQ(receive_buffer[0],0);	
	EXPECT_EQ(err, BUFFER_OVER_FLOW);

}

TEST(AddCharToBuffer, ErrorInput)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
	int i;
	unsigned char c ='o';
	b.buffer = receive_buffer;
	b.tail = receive_buffer+5;
	b.head = receive_buffer+255;
	error_type err = BUFFER_OVER_FLOW;

	i = add_char_to_buffer(&b,c,&err);
	EXPECT_EQ(-1,i);
	EXPECT_EQ(b.head,receive_buffer+255);
	EXPECT_EQ(b.tail,receive_buffer+5);
	EXPECT_EQ(b.buffer,receive_buffer);
	EXPECT_EQ(receive_buffer[0],'a');	
}

TEST(GetCharFromBuffer, TestCase)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    	error_type err = OK;
	unsigned char readchar;
	b.head = receive_buffer+10;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	readchar = get_char_from_buffer(&b, &err);

	EXPECT_EQ(readchar, 'a') ;
	EXPECT_EQ(err, OK);
 	
}

TEST(GetCharFromBuffer, EmptyBuffer)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    	error_type err = OK;
	unsigned char readchar;
	b.head = receive_buffer;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;
	readchar = get_char_from_buffer(&b, &err);

	EXPECT_EQ(readchar, (unsigned char)-1);
	EXPECT_EQ(err, EMPTY_BUFFER);
 	
}

TEST(GetCharFromBuffer, ErrorInput)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    	error_type err = POINTER_ERROR;
	unsigned char readchar;
	b.head = receive_buffer+10;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	readchar = get_char_from_buffer(&b, &err);

	EXPECT_EQ(readchar, (unsigned char) -1) ;
	EXPECT_EQ(err, POINTER_ERROR);
 	
}


TEST(PrintBuffer, TestCase)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    error_type err = OK;
	int amount = 0;
	b.head = receive_buffer;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;

	b.tail = b.buffer + 50;
	b.head = b.buffer + 48;
	amount = print_buffer(b, &err);
	EXPECT_EQ(254, amount);
}

TEST(PrintBuffer, EmptyBuffer)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    error_type err = OK;
	int amount = 0;
	b.head = receive_buffer;
	b.tail = receive_buffer;
	b.buffer = receive_buffer;
	amount = print_buffer(b, &err);
	EXPECT_EQ(0, amount);
	EXPECT_EQ(EMPTY_BUFFER, err);
}

TEST(PrintBuffer, ErrorInput)
{
	unsigned char receive_buffer[BUFFER_SIZE];
	struct buffer_type b;
    error_type err = POINTER_ERROR;
	int amount = 0;
	b.head = receive_buffer;
	b.tail = receive_buffer+50;
	b.buffer = receive_buffer;

	amount = print_buffer(b, &err);
	EXPECT_EQ(-1, amount);
	EXPECT_EQ(POINTER_ERROR, err);
}
