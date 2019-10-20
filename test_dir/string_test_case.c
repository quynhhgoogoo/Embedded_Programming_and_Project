#include <gtest/gtest.h>
#include "string.h"

/*string len*/
TEST(MytestCategory1,MyTest1)
{
	char *test_data="testing";
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(7,len);
}

TEST(MytestCategory1,MyTest2)
{
	char *test_data="";
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(0,len);
}

TEST(MytestCategory1,MyTest3)
{
	char *test_data=null;
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(-1,len);
}

TEST(MytestCategory1,MyTest4)
{
	char *test_data="###116";
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(6,len);
}

TEST(MytestCategory1,MyTest5)
{
	char *test_data;
	int len;

	len=my_strlen(test_data);
    	EXPECT_EQ(-1,len);
}
/*returns the number of changed uppercase character*/

TEST(MytestCategory2,MyTest6)
{
	char *test_data="Testi";
	int result;

	result=str2upper(test_data);
	EXPECT_EQ(4,result);
}

TEST(MytestCategory2,MyTest7)
{
	char *test_data="testI";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(4,result);
}

TEST(MytestCategory2,MyTest8)
{
	char *test_data="testi";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(5,result);
}

TEST(MytestCategory2,MyTest9)
{
	char *test_data="testi";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(5,result);
}

TEST(MytestCategory2,MyTest10)
{
	char *test_data="TESTI";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest11)
{
	char *test_data="##0273465*^§";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest12)
{
	char *test_data="";
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest8)
{
	char *test_data;
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory2,MyTest9)
{
	char *test_data=null;
	int result;

	result=str2upper(test_data);
    	EXPECT_EQ(-1,result);
}


/*return number of changed lower character*/
TEST(MytestCategory3,MyTest1)
{
	char *test_data="TESTI";
	int result;

	result=str2lower(test_data);
	EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest2)
{
	char *test_data="%TESTI#";
	int result;

	result=str2lower(test_data);
    	EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest3)
{
	char *test_data="testi";
	int result;

	result=str2lower(test_data);
    	EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest4)
{
	char *test_data="teSti";
	int result;

	result=str2lower(test_data);
    	EXPECT_EQ(4,result);
}

TEST(MytestCategory3,MyTest5)
{
	char *test_data="";
	int result;

	result=str2lower(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory3,MyTest6)
{
	char *test_data=null;
	int result;

	result=str_str2lower(test_data);
    	EXPECT_EQ(-1,result);
}

/*remove numbers and returns new length of string*/
TEST(MytestCategory4,MyTest1)
{
	char *test_data="test1ng23";
	int result;

	result=str_strip_numbers(test_data);
    	EXPECT_EQ(6,result);
}

TEST(MytestCategory4,MyTest2)
{
	char *test_data="test9ing&%3";
	int result;

	result=str_strip_numbers(test_data);
    	EXPECT_EQ(8,result);
}

TEST(MytestCategory4,MyTest3)
{
	char *test_data="#(&&¤)(//";
	int result;

	result=str_strip_numbers(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory4,MyTest4)
{
	char *test_data="";
	int result;

	result=str_strip_numbers(test_data);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory4,MyTest5)
{
	char *test_data=null;
	int result;

	result=str_strip_numbers(test_data);
    	EXPECT_EQ(-1,result);
}

/*copy string content*/
TEST(MytestCategory9,MyTest9)
{
	char *test_data="TESTING";
	char test_data2=(char)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data,test_data2);
}

TEST(MytestCategory10,MyTest10)
{
	char *test_data="testt2847¤%&/";
	char test_data2=(char)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data,test_data2);
}

TEST(MytestCategory10,MyTest10)
{
	char *test_data;
	char test_data2=(char)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    EXPECT_STREQ(test_data,test_data2);
}

TEST(MytestCategory10,MyTest10)
{
	char *test_data="";
	char test_data2=(char)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data,test_data2);
}

TEST(MytestCategory10,MyTest10)
{
	char *test_data=null;
	char test_data2=(char)malloc(sizeof(char*)*100);

	mystrcpy(test_data,test_data2);
    	EXPECT_STREQ(test_data,test_data2);
}


/*compare two strings together*/

TEST(MytestCategory11,MyTest11)
{
	char *test_data="hello world";
	char *test_data2="perkele";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory12,MyTest12)
{
	char *test_data="helloworld";
	char *test_data2="helloworld";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory12,MyTest12)
{
	char *test_data="hellow0rld#";
	char *test_data2="hellow0rld#";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(0,result);
}

TEST(MytestCategory12,MyTest13)
{
	char *test_data="helloworld";
	char *test_data2="";
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory12,MyTest13)
{
	char *test_data="helloworld";
	char *test_data2=null;
	int result;

	result=mystrcmp(test_data,test_data2);
    	EXPECT_EQ(-1,result);
}

/*return duplication of a string*/

TEST(MytestCategory13,MyTest13)
{
	char *test_data="hello world";
	char *result =strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

TEST(MytestCategory14,MyTest14)
{
	char *test_data="h3ll0 w0rld#";
	char *result=strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

TEST(MytestCategory14,MyTest14)
{
	char *test_data="";
	char *result=strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

TEST(MytestCategory14,MyTest14)
{
	char *test_data ="Halo";
	char *result = "Halo";
	
	*result = strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}

TEST(MytestCategory14,MyTest14)
{
	char *test_data=null;
	char *result=strdupl(test_data);
    	EXPECT_STREQ(test_data,result);
}