#include <gtest/gtest.h>
#include "linkedlist.h"

/***************************************************************************/
TEST(addtest,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(head,str6);
    EXPECT_EQ(6,i);

}

TEST(addtest,NullChar) {
    char *str1 = 0;
    int i;
    
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
    head->next=NULL; 
    head->data=str1; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(-1,i);
}

TEST(addtest,NullPointer) {
    char str1[10] = "Test";
    int i;
	
	linked_list *head =NULL;
	
    i=add_to_list(head,str1);
    EXPECT_EQ(i,-1);
}
/***************************************************************************/
TEST(display_list,empty)
{
    int result;
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    display_list(head);

}

TEST(display_list, NullPointer)
{
    int i;
    linked_list *find = NULL;
    i = display_item(find);
    EXPECT_EQ(i,-1);
}

TEST(display_list, EmptyNode)
{
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->next=NULL;
    head->data=NULL;
    i = display_item(head);
    EXPECT_EQ(i,0);
}
/***************************************************************************/
TEST(display_item,add_to_list)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    display_item(head->next);
    EXPECT_EQ(head->next->index,1);
    EXPECT_EQ(i,1);
    EXPECT_STREQ(head->next->data,str1);

    i=add_to_list(head,str2);
    display_item(head->next->next);
    EXPECT_EQ(head->next->next->index,2);
    EXPECT_EQ(i,2);
    EXPECT_STREQ(head->next->next->data,str2);

    i=add_to_list(head,str3);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->index,3);
    EXPECT_EQ(i,3);
    EXPECT_STREQ(head->next->next->next->data,str3);

    i=add_to_list(head,str4);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->next->index,4);
    EXPECT_EQ(i,4);
    EXPECT_STREQ(head->next->next->next->next->data,str4);

    i=add_to_list(head,str5);
    display_item(head->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->index,5);
    EXPECT_EQ(i,5);
    EXPECT_STREQ(head->next->next->next->next->next->data,str5);

    i=add_to_list(head,str6);
    display_item(head->next->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->next->index,6);
    EXPECT_EQ(i,6);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);

}

TEST(display_item, NullPointer)
{
    int i;
    linked_list *find = NULL;
    i = display_item(find);
    EXPECT_EQ(i,-1);
}

TEST(display_item, EmptyNode)
{
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->next=NULL;
    head->data=NULL;
    i = display_item(head);
    EXPECT_EQ(i,0);
}

/***************************************************************************/
TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    display_list(head);
}
/***************************************************************************/
TEST(search,normal)
{
    char str[15]="List Start";
    char str1[15]="second";
    char str2[15]="third";

    linked_list *found;
    struct linked_list *head;

    head = (struct linked_list*) malloc(sizeof(linked_list));
    head->data=str;
    head->index=0;


    head->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->data=str1;
    head->next->index=1;

    head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->next->index=2;
    head->next->next->data=str2;

    head->next->next->next->next = NULL;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ(found->index,2);
    EXPECT_STREQ(str2,found->data);
}

TEST(search,not_found)
{
    char str[15]="List Start";

    linked_list *found;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ((int *)found,(int *)NULL);
}

TEST(search, DifferentString)
{
    char str[15]="string1";
    char str1[15]="diff";
    char str2[15]="embedded";
	
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
    linked_list *result1 = (struct linked_list*) malloc(sizeof(linked_list));
    linked_list *result2 = (struct linked_list*) malloc(sizeof(linked_list));
      
    head->next=NULL;
    head->data=str;
    head->index=0;
	
    add_to_list(head,str1);
    add_to_list(head,str2);
    
	result1=search_from_list(head,(char *)"thirdmore");
    result2=search_from_list(head,(char*)"sec");
    
	EXPECT_EQ(NULL,result1);
    EXPECT_EQ(NULL,result2);
}

/***************************************************************************/
/*TEST(sort,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    sort_list(head);

    display_list(head);

}

/***************************************************************************/
TEST(delete,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    int len = delete_from_list(head,2);

	EXPECT_EQ(6,len);
}

/***************************************************************************/
TEST(delete,multi) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i, len;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    for(i=0; i<40; i++)
        add_to_list(head,str1);

    len = delete_from_list(head,12);
    len = delete_from_list(head,22);
    len = delete_from_list(head,25);
    len = delete_from_list(head,32);
    len = delete_from_list(head,38);

    len = delete_from_list(head,380);
	
	EXPECT_EQ(-1,len);
}

TEST(delete, NullPointer) {
    char str[15]="List Start";
    char str1[10]="zero";
    int i;
	linked_list *head = NULL;
    i=delete_from_list(head,0);
    EXPECT_EQ(-1,i);

}

TEST(delete, HeadNode)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i = 0;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    linked_list *temp = NULL;
    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    temp = head->next;
    add_to_list(head,str2);
    add_to_list(head,str3);
    add_to_list(head,str4);
    add_to_list(head,str5);
    add_to_list(head,str6);
    i = delete_from_list(head,0);
    EXPECT_EQ(i, 7);
    EXPECT_EQ(temp->index, 1);
}

TEST(delete, TailNode) 
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i = 0;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
    head->next=NULL;
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
    add_to_list(head,str3);
    add_to_list(head,str4);
    add_to_list(head,str5);
    add_to_list(head,str6);
    i = delete_from_list(head,1);
    EXPECT_EQ(i, 6);
    EXPECT_EQ(NULL, head->next->next->next->next->next->next);
}


/***************************************************************************/
/*TEST(empty,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    empty_list(head);
}*/