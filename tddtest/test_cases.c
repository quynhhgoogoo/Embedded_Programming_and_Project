#include <gtest/gtest.h>
#include "string.h"

TEST(Test_strlen,MyTest1)
{
	char test_data[]="testing";
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(7,len);
}

TEST(Test_strlen,MyTest2)
{
	char test_data[]="";
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(0,len);
}

TEST(Test_upper,MyTest3)
{
	char test_data[]="TesTing";
	char test[]="TESTING";
	int result;

	result=str2upper(test_data);
	EXPECT_EQ(5,result);
	//EXPECT_STREQ(test,test_data);
}

TEST(Test_upper,MyTest4)
{
	char test_data[]="1234abcd";
	char test[]="1234ABCD";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(4,result);
	//EXPECT_STREQ(test,test_data);
}

TEST(Test_lower,MyTest5)
{
	char test_data[]="TESTING";
	char test[]="testing";
	int result;

	result=str2lower(test_data);
    	EXPECT_EQ(7,result);
	//EXPECT_STREQ(test,test_data);
}

TEST(Test_lower,MyTest6)
{
	char test_data[]="TESTING?=";
	char test[]="testing?=";
	int result;

	result=str2lower(test_data);
	EXPECT_EQ(7,result);
	EXPECT_STREQ(test,test_data);
}

TEST(Test_strip,MyTest7){
    char sample[]="abc123zxc";
    char test[]="abczxc";
    int m = str_strip_numbers(sample);
    EXPECT_EQ(m,6);
    EXPECT_STREQ(sample,test);
}

TEST(Test_strip,MyTest8){
    char sample[]="123321";
    char test[]="";
    int m = str_strip_numbers(sample);
    EXPECT_EQ(m,0);
    EXPECT_STREQ(sample,test);
}

TEST(Test_cpy,MyTest9)
{
	char *test_data="TESTING";
	char *test_data2=(char*)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data2,test_data);
}

TEST(Test_cpy,MyTest10)
{
	char *test_data=" ";
	char *test_data2=(char*)malloc(sizeof(char*)*100);
	//char result;

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data2,test_data);
}

TEST(Test_cmp,MyTest11)
{
	char test_data[]="TESTING";
	char test_data2[]="abcdef";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(-1,result);
}

TEST(Test_cmp,MyTest12)
{
	char test_data[]="TESTING";
	char test_data2[]="TESTING";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(0,result);
}

TEST(Test_dupl,MyTest13)
{
	char test_data[]="TESTING";
	char *result=strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

TEST(Test_dupl,MyTest14)
{
	char test_data[]="TESTING";
	char *result=strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

