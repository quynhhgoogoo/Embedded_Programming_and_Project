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

TEST(Test_strlen,MyTest3)
{
	        char test_data[]="Hello!!!";
		        int len;

			        len=my_strlen(test_data);
				        EXPECT_EQ(8,len);
}

TEST(Test_strlen,MyTest4)
{
	        char test_data[]="\0";
		        int len;

			        len=my_strlen(test_data);
				        EXPECT_EQ(0,len);
}

TEST(Test_upper,MyTest1)
{
		char test_data[]="TesTing";
			int result;

				result=str2upper(test_data);
					EXPECT_EQ(5,result);
}

TEST(Test_upper,MyTest2)
{
		char test_data[]="1234abcd";
			int result;

				result=str2upper(test_data);
				    	EXPECT_EQ(4,result);
}

TEST(Test_upper,MyTest3)
{
	        char test_data[]="";
		        int result;

			        result=str2upper(test_data);
				        EXPECT_EQ(0,result);
}

TEST(Test_upper,MyTest4)
{
	        char test_data[]="\0";
		        int result;

			        result=str2upper(test_data);
				        EXPECT_EQ(0,result);
}

TEST(Test_lower,MyTest1)
{
		char test_data[]="TESTING";
			int result;

				result=str2lower(test_data);
				    	EXPECT_EQ(7,result);
}

TEST(Test_lower,MyTest2)
{
		char test_data[]="TESTING?=";
			int result;

				result=str2lower(test_data);
					EXPECT_EQ(7,result);
}

TEST(Test_lower,MyTest3)
{
	        char test_data[]="";
		        int result;

			        result=str2lower(test_data);
				        EXPECT_EQ(0,result);
}

TEST(Test_lower,MyTest4)
{
	        char test_data[]="\0";
		        int result;

			        result=str2lower(test_data);
				        EXPECT_EQ(0,result);
}

TEST(Test_strip,MyTest1){
	    char sample[]="abc123zxc";

	        int m = str_strip_numbers(sample);
		    EXPECT_EQ(m,6);
}

TEST(Test_strip,MyTest2){
	    char sample[]="";

	        int m = str_strip_numbers(sample);
		    EXPECT_EQ(m,0);
}

TEST(Test_strip,MyTest3){
	    char sample[]="123!@#";

	        int m = str_strip_numbers(sample);
		    EXPECT_EQ(3,m);
}

TEST(Test_strip,MyTest4){
	    char sample[]="\0";

	        int m = str_strip_numbers(sample);
		    EXPECT_EQ(m,0);
}

TEST(Test_cpy,MyTest1)
{
		char *test_data="TESTING";
			char *test_data2=(char*)malloc(sizeof(char*)*100);

				mystrcpy(test_data,test_data2);
				    	EXPECT_STREQ(test_data2,test_data);
}

TEST(Test_cpy,MyTest2)
{
		char *test_data=" ";
			char *test_data2=(char*)malloc(sizeof(char*)*100);

				mystrcpy(test_data,test_data2);
				    	EXPECT_STREQ(test_data2,test_data);
}

TEST(Test_cmp,MyTest1)
{
		char test_data[]="TESTING";
			char test_data2[]="abcdef";
				int result;

					result=mystrcmp(test_data,test_data2);
					    	EXPECT_EQ(-1,result);
}

TEST(Test_cmp,MyTest2)
{
		char test_data[]="TESTING";
			char test_data2[]="TESTING";
				int result;

					result=mystrcmp(test_data,test_data2);
					    	EXPECT_EQ(0,result);
}

TEST(Test_dupl,MyTest1)
{
		char test_data[]="TESTING";
			char *result=strdupl(test_data);
			    	EXPECT_STREQ(test_data,result);
}

TEST(Test_dupl,MyTest2)
{
		char test_data[]="TESTING";
			char *result=strdupl(test_data);
			    	EXPECT_STREQ(test_data,result);
}

