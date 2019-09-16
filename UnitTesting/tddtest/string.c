#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/*return length of string*/
int my_strlen(char *s){
	int len=0;
	while(len!='\0'){
		len++;
	}
	return len;
}

/*return number of uppercase character*/
int str2upper(char *s){
	int c = 0;
	int num =0;
	while(c!='\0'){
		if(*(s+c)>='a' && *(s+c)<='z'){
			*(s+c)=*(s+c)-32;
			num++;
		}
		c++;
	}
	return num;
}

/*return number of lowercase character*/
int str2lower(char *s){
	int c =0;
	int num = 0;
	while(*(s+c)!='\0'){
		if(*(s+c) >= 'A' && *(s+c)<='Z'){
			*(s+c)=*(s+c)+32;
			num++;
		}
		c++;
	}
}

/*remove occurence number and return new string length*/
int str_strip_numbers(char *s){
	int i = 0;
	int len = my_strlen(s);
	while(*(s+i)!='\0'){
		if(*(s+i)>=0 && *(s+i)<=9){
			i++;
			while(i<len){
				*(s+i)=*(s+i+1);
			}
		}
		return i;
	}
}

/*copy two strings together*/
void mystrcpy(char *s, char *d){
	while(*s){
		*d = *s;
		d++;
		s++;
	}
	*d='\0';
}

/*compare two strings together and returns place of first different character*/
int mystrcmp(char*s, char *d){
	int i = 0;
	while(*(s+i)==*(d+i)){
		i++;

		if(*(s+i)=='\0' || *(d+i) == '\0'){
			break;
		}
	}
	if(*(s+i)==*(d+i))
		return 0;
	if(*(s+i)<*(d+i))
		return -1;
	else
		return 1;

}

/*creaes duplicated string*/
char *strdupl(char *s){
	char *d = (char*)malloc(sizeof(char*)*100);
	while(*s){
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}
