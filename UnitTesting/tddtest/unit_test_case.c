#include <gtest/gtest.h>
#include "string.h"
#include "math.h"

/*string len*/
TEST(MytestCategory1,MyTest1)
{
		char *s="testing";
			int len;

				len=my_strlen(s);
				    	EXPECT_EQ(7,len);
}

TEST(MytestCategory1,MyTest2)
{
		char *s="";
			int len;

				len=my_strlen(s);
				    	EXPECT_EQ(0,len);
}

TEST(MytestCategory1,MyTest3)
{
		char *s=NULL;
			int len;

				len=my_strlen(s);
				    	EXPECT_EQ(-1,len);
}

TEST(MytestCategory1,MyTest4)
{
		char *s="###116";
			int len;

				len=my_strlen(s);
				    	EXPECT_EQ(6,len);
}

TEST(MytestCategory1,MyTest5)
{
		char *s;
			int len;

				len=my_strlen(s);
				    	EXPECT_EQ(-1,len);
}
/*returns the number of changed uppercase character*/

TEST(MytestCategory2,MyTest6)
{
		char *s="Testi";
			int result;

				result=str2upper(s);
					EXPECT_EQ(4,result);
}

TEST(MytestCategory2,MyTest7)
{
		char *s="testI";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(4,result);
}

TEST(MytestCategory2,MyTest8)
{
		char *s="testi";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(5,result);
}

TEST(MytestCategory2,MyTest9)
{
		char *s="testi";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(5,result);
}

TEST(MytestCategory2,MyTest10)
{
		char *s="TESTI";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest11)
{
		char *s="##0273465*^§";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest12)
{
		char *s="";
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory2,MyTest13)
{
		char *s;
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory2,MyTest14)
{
		char *s=NULL;
			int result;

				result=str2upper(s);
				    	EXPECT_EQ(-1,result);
}


/*return number of changed lower character*/
TEST(MytestCategory3,MyTest15)
{
		char *s="TESTI";
			int result;

				result=str2lower(s);
					EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest16)
{
		char *s="%TESTI#";
			int result;

				result=str2lower(s);
				    	EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest17)
{
		char *s="testi";
			int result;

				result=str2lower(s);
				    	EXPECT_EQ(5,result);
}

TEST(MytestCategory3,MyTest18)
{
		char *s="teSti";
			int result;

				result=str2lower(s);
				    	EXPECT_EQ(4,result);
}

TEST(MytestCategory3,MyTest19)
{
		char *s="";
			int result;

				result=str2lower(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory3,MyTest20)
{
		char *s=NULL;
			int result;

				result=str_str2lower(s);
				    	EXPECT_EQ(-1,result);
}

/*remove numbers and returns new length of string*/
TEST(MytestCategory4,MyTest21)
{
		char *s="test1ng23";
			int result;

				result=str_strip_numbers(s);
				    	EXPECT_EQ(6,result);
}

TEST(MytestCategory4,MyTest22)
{
		char *s="test9ing&%3";
			int result;

				result=str_strip_numbers(s);
				    	EXPECT_EQ(8,result);
}

TEST(MytestCategory4,MyTest23)
{
		char *s="#(&&¤)(//";
			int result;

				result=str_strip_numbers(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory4,MyTest24)
{
		char *s="";
			int result;

				result=str_strip_numbers(s);
				    	EXPECT_EQ(0,result);
}

TEST(MytestCategory4,MyTest25)
{
		char *s=NULL;
			int result;

				result=str_strip_numbers(s);
				    	EXPECT_EQ(-1,result);
}

/*copy string content*/
TEST(MytestCategory9,MyTest26)
{
		char *s="TESTING";
			char s2=(char)malloc(sizeof(char*)*100);

				mystrcpy(s,s2);
				    	EXPECT_STREQ(s,s2);
}

TEST(MytestCategory10,MyTest27)
{
		char *s="testt2847¤%&/";
			char s2=(char)malloc(sizeof(char*)*100);

				mystrcpy(s,s2);
				    	EXPECT_STREQ(s,s2);
}

TEST(MytestCategory10,MyTest28)
{
		char *s;
			char s2=(char)malloc(sizeof(char*)*100);

				mystrcpy(s,s2);
				    EXPECT_STREQ(s,s2);
}

TEST(MytestCategory10,MyTest29)
{
		char *s="";
			char s2=(char)malloc(sizeof(char*)*100);

				mystrcpy(s,s2);
				    	EXPECT_STREQ(s,s2);
}

TEST(MytestCategory10,MyTest30)
{
		char *s=NULL;
			char s2=(char)malloc(sizeof(char*)*100);

				mystrcpy(s,s2);
				    	EXPECT_STREQ(NULL,s2);
}


/*compare two strings together*/

TEST(MytestCategory11,MyTest31)
{
		char *s="hello world";
			char *s2="perkele";
				int result;

					result=mystrcmp(s,s2);
					    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory12,MyTest32)
{
		char *s="helloworld";
			char *s2="helloworld";
				int result;

					result=mystrcmp(s,s2);
					    	EXPECT_EQ(0,result);
}

TEST(MytestCategory12,MyTest33)
{
		char *s="hellow0rld#";
			char *s2="hellow0rld#";
				int result;

					result=mystrcmp(s,s2);
					    	EXPECT_EQ(0,result);
}

TEST(MytestCategory12,MyTest34)
{
		char *s="helloworld";
			char *s2="";
				int result;

					result=mystrcmp(s,s2);
					    	EXPECT_EQ(-1,result);
}

TEST(MytestCategory12,MyTest35)
{
		char *s="helloworld";
			char *s2=NULL;
				int result;

					result=mystrcmp(s,s2);
					    	EXPECT_EQ(-1,result);
}

/*return duplication of a string*/

TEST(MytestCategory13,MyTest36)
{
		char *s="hello world";
			char *result =strdupl(s);
			    	EXPECT_STREQ(s,result);
}

TEST(MytestCategory14,MyTest14)
{
		char *s="h3ll0 w0rld#";
			char *result=strdupl(s);
			    	EXPECT_STREQ(s,result);
}

TEST(MytestCategory14,MyTest37)
{
		char *s="";
			char *result=strdupl(s);
			    	EXPECT_STREQ(s,result);
}

TEST(MytestCategory14,MyTest38)
{
		char *s ="Halo";
			char *result = "Halo";
				
				result = strdupl(s);
				    	EXPECT_STREQ(s,result);
}

TEST(MytestCategory14,MyTest39)
{
		char *s=NULL;
			char *result=strdupl(s);
			    	EXPECT_STREQ(s,result);
}
