#include <gtest/gtest.h>
#include "string.h"
#include "math.h"

/*string len*/
TEST(StringLen,Normal)
{
	char *s="testing";
	int len;

	len=my_strlen(s);
    	EXPECT_EQ(7,len);
}

TEST(StringLen,EmptyString)
{
	char *s="";
	int len;

	len=my_strlen(s);
    	EXPECT_EQ(0,len);
}

TEST(StringLen,NullString)
{
	char *s=NULL;
	int len;

	len=my_strlen(s);
    	EXPECT_EQ(-1,len);
}

TEST(StringLen,SpecialChar)
{
	char *s="###116";
	int len;

	len=my_strlen(s);
    	EXPECT_EQ(6,len);
}

TEST(StringLen,NotDefined)
{
	char *s;
	int len;

	len=my_strlen(s);
    	EXPECT_EQ(-1,len);
}
/*returns the number of changed uppercase character*/

TEST(UpperCase,Normal1)
{
	char *s="Testi";
	int result;

	result=str2upper(s);
	EXPECT_EQ(4,result);
}

TEST(UpperCase,Normal2)
{
	char *s="testI";
	int result;

	result=str2upper(s);
    	EXPECT_EQ(4,result);
}

TEST(UpperCase,Normal3)
{
	char *s="testi";
	int result;

	result=str2upper(s);
    	EXPECT_EQ(5,result);
}

TEST(UpperCase,Normal4)
{
	char *s="TESTI";
	int result;

	result=str2upper(s);
    	EXPECT_EQ(0,result);
}

TEST(UpperCase,SpecialChar)
{
	char *s="##0273465*^§";
	int result;

	result=str2upper(s);
    	EXPECT_EQ(0,result);
}

TEST(UpperCase,EmptyString)
{
	char *s="";
	int result;

	result=str2upper(s);
    	EXPECT_EQ(0,result);
}

TEST(UpperCase,NotDefined)
{
	char *s;
	int result;

	result=str2upper(s);
    	EXPECT_EQ(-1,result);
}

TEST(UpperCase,NullString)
{
	char *s=NULL;
	int result;

	result=str2upper(s);
    	EXPECT_EQ(-1,result);
}


/*return number of changed lower character*/
TEST(LowerCase,Normal1)
{
	char *s="TESTI";
	int result;

	result=str2lower(s);
	EXPECT_EQ(5,result);
}

TEST(LowerCase,SpecialChar)
{
	char *s="%TESTI#";
	int result;

	result=str2lower(s);
    	EXPECT_EQ(5,result);
}

TEST(LowerCase,Normal2)
{
	char *s="testi";
	int result;

	result=str2lower(s);
    	EXPECT_EQ(5,result);
}

TEST(LowerCase,Normal3)
{
	char *s="teSti";
	int result;

	result=str2lower(s);
    	EXPECT_EQ(4,result);
}

TEST(LowerCase,EmptyString)
{
	char *s="";
	int result;

	result=str2lower(s);
    	EXPECT_EQ(0,result);
}

TEST(LowerCase,NullString)
{
	char *s=NULL;
	int result;

	result=str_str2lower(s);
    	EXPECT_EQ(-1,result);
}

/*remove numbers and returns new length of string*/
TEST(RemoveNumbers,Normal1)
{
	char *s="test1ng23";
	int result;

	result=str_strip_numbers(s);
    	EXPECT_EQ(6,result);
}

TEST(RemoveNumbers,SpecialChar1)
{
	char *s="test9ing&%3";
	int result;

	result=str_strip_numbers(s);
    	EXPECT_EQ(8,result);
}

TEST(RemoveNumbers,SpecialChar2)
{
	char *s="#(&&¤)(//";
	int result;

	result=str_strip_numbers(s);
    	EXPECT_EQ(0,result);
}

TEST(RemoveNumbers,EmptyString)
{
	char *s="";
	int result;

	result=str_strip_numbers(s);
    	EXPECT_EQ(0,result);
}

TEST(RemoveNumbers,NullString)
{
	char *s=NULL;
	int result;

	result=str_strip_numbers(s);
    	EXPECT_EQ(-1,result);
}

/*copy string content*/
TEST(CopyString,Normal1)
{
	char *s="TESTING";
	char s2=(char)malloc(sizeof(char*)*100);

	mystrcpy(s,s2);
    	EXPECT_STREQ(s,s2);
}

TEST(CopyString,SpecialCase)
{
	char *s="testt2847¤%&/";
	char s2=(char)malloc(sizeof(char*)*100);

	mystrcpy(s,s2);
    	EXPECT_STREQ(s,s2);
}

TEST(CopyString,NotDefined)
{
	char *s;
	char s2=(char)malloc(sizeof(char*)*100);

	mystrcpy(s,s2);
    EXPECT_STREQ(s,s2);
}

TEST(CopyString,EmptyString)
{
	char *s="";
	char s2=(char)malloc(sizeof(char*)*100);

	mystrcpy(s,s2);
    	EXPECT_STREQ(s,s2);
}

TEST(CopyString,NullString)
{
	char *s=NULL;
	char s2=(char)malloc(sizeof(char*)*100);

	mystrcpy(s,s2);
    	EXPECT_STREQ(NULL,s2);
}


/*compare two strings together*/

TEST(CompareString,DiffString)
{
	char *s="hello world";
	char *s2="perkele";
	int result;

	result=mystrcmp(s,s2);
    	EXPECT_EQ(-1,result);
}

TEST(CompareString,SameString)
{
	char *s="helloworld";
	char *s2="helloworld";
	int result;

	result=mystrcmp(s,s2);
    	EXPECT_EQ(0,result);
}

TEST(CompareString,SpecialChar)
{
	char *s="hellow0rld#";
	char *s2="hellow0rld#";
	int result;

	result=mystrcmp(s,s2);
    	EXPECT_EQ(0,result);
}

TEST(CompareString,EmptyString)
{
	char *s="helloworld";
	char *s2="";
	int result;

	result=mystrcmp(s,s2);
    	EXPECT_EQ(-1,result);
}

TEST(CompareString,NullString)
{
	char *s="helloworld";
	char *s2=NULL;
	int result;

	result=mystrcmp(s,s2);
    	EXPECT_EQ(-1,result);
}

/*return duplication of a string*/

TEST(StringDuplicate,MyTest36)
{
	char *s="hello world";
	char *result =strdupl(s);
    	EXPECT_STREQ(s,result);
}

TEST(StringDuplicate,MyTest14)
{
	char *s="h3ll0 w0rld#";
	char *result=strdupl(s);
    	EXPECT_STREQ(s,result);
}

TEST(StringDuplicate,MyTest37)
{
	char *s="";
	char *result=strdupl(s);
    	EXPECT_STREQ(s,result);
}

TEST(StringDuplicate,MyTest38)
{
	char *s ="Halo";
	char *result = "Halo";
	
	*result = strdupl(s);
    	EXPECT_STREQ(s,result);
}

TEST(StringDuplicate,MyTest39)
{
	char *s=NULL;
	char *result=strdupl(s);
    	EXPECT_STREQ(NULL,result);
}