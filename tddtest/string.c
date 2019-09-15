#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/*return length of string*/
int my_strlen(char *s){
	int c=0;
	while(c!='\0'){
		c++;
	}
	return c
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
	while(*(s+c)!='\0''){
		if(*(s+c) >= 'A' && *(s+c)<='Z'){
			*(s+c)=*(s+c)+32;
			num++;
		}
		c++;
	}
}

/*remove occurence number and return new string length*/
int str_strip_number(char *s){
	char *oldstr = s;
	char *newstr = t;
	int k = 0;

	while(k!='\0'){
		if(*(s+k) >= 0 && *(s+k)<=9){
			newlen++;
			continue;
		}
		*(t+k)=*(s+k);
	}
	*(t+k+1)='\0'
	int newlen = my_str(len);
	return newlen;
}

/*compare two strings together*/
void mystrcpy(char *s, char *d){
	while(*s){
		*d = *s;
		d++;
		s++;
	}
	*d='\0';
}


