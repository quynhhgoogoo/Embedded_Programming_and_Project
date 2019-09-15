#include <gtest/gtest.h>
#include "string.h"
#include "math.h"

TEST(MytestCategory,MyTest1)
{
	    char *test_data="testing";
	        int len;

		    len=my_strlen(*test_data);
		        
		        EXPECT_EQ(7,len);
}

TEST(MytestCategory,MyTest2)
{
	    char test_data="testing2";
	        int len;

		    len=my_strlen(*test_data);
		        
		        EXPECT_EQ(8,len);
}

TEST(MytestCategory,MyTest3)
{
	    char test_data="TesTing";
	        int result;

		    result=str2upper(*test_data);
		        
		        EXPECT_EQ(5,result);
}

TEST(MytestCategory,MyTest4)
{
	    char test_data="";
	        int result;

		    result=str2upper(*test_data);
		        
		        EXPECT_EQ(0,result);
}

TEST(MytestCategory,MyTest5)
{
	    char test_data="TESTING";
	        int result;

		    result=str2lower(*test_data);
		        
		        EXPECT_EQ(7,result);
}

TEST(MytestCategory,MyTest6)
{
	    char test_data="TESTING?=";
	        int result;

		    result=str2lower(*test_data);
		        
		        EXPECT_EQ(7,result);
}

TEST(MytestCategory,MyTest7)
{
	    char test_data="TESTING987";
	        int result;

		    result=str_strip_numbers(*test_data);
		        
		        EXPECT_EQ(7,result);
}

TEST(MytestCategory,MyTest8)
{
	    char test_data=" ";
	        int result;

		    result=str_strip_numbers(*test_data);
		        
		        EXPECT_EQ(0,result);
}

TEST(MytestCategory,MyTest9)
{
	    char test_data="TESTING";
	        char test_data2="testing"
			    char result;

		    result=mystrcpy(*test_data2,*test_data);
		        
		        EXPECT_EQ("TESTINGtesting",result);
}

TEST(MytestCategory,MyTest10)
{
	    char test_data="TESTING";
	        char test_data2=""
			    int result;

		    result=mystrcpy(*test_data,*test_data2);
		        
		        EXPECT_EQ("TESTING",result);
}

TEST(MytestCategory,MyTest11)
{
	    char test_data="TESTING";
	        char test_data2="testing"
			    int result;

		    result=mystrcmp(*test_data,*test_data2);
		        
		        EXPECT_EQ(7,result);
}

TEST(MytestCategory,MyTest12)
{
	    char test_data="TESTING";
	        char test_data2="testing"
			    int result;

		    result=mystrcmp(test_data,test_data2);
		        
		        EXPECT_EQ(0,result);
}

TEST(MytestCategory,MyTest13)
{
	    char test_data="TESTING";
	        char *result;
		    char *result2=NULL;
		        result=mystrcmp(*test_data);
			    
			    EXPECT_EQ(result2,result);
}

TEST(MytestCategory,MyTest14)
{
	    char test_data="TESTING";
	        char result2;
		    char *result=mystrcmp(*test_data);
		        
		        EXPECT_EQ(result2,result);
}
