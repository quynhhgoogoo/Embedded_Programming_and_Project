#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/*return length of string*/
int my_strlen(char *s){
	int len=0;
	while(*(s+len) != '\0'){
		len++;
	}
	return len;
}

/*return number of uppercase character*/
int str2upper(char *s){
	int i = 0,count =0;
	while(*(s+i)!='\0'){
		if(*(s+i)>='a' && *(s+i)<='z'){
			*(s+i)=*(s+i)-32;
			count++;
		}
		i++;
	}
	return count;
}

/*return number of lowercase character*/
int str2lower(char *s){
	int i =0, count = 0;
	while(*(s+i)!='\0'){
		if(*(s+i) >= 'A' && *(s+i)<='Z'){
			*(s+i)=*(s+i)+32;
			count++;
		}
		i++;
	}
	return count;
}

/*remove occurence number and return new string length*/
int str_strip_numbers(char *s){
	int i = 0, count =0;
	int len = my_strlen(s);
	while(*(s+i)!='\0'){
		if(*(s+i)>0||*(s+i)<9){
			count++;
		}
		i++;
	}
	return count;
}

/*copy two strings together*/
void mystrcpy(char *s, char *d){
	int i=0;
	while(*(s+i)!='\0'){
		*(d+i) = *(s+i);
		i++;
	}
	*(d+i)='\0';
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
	if(*(s+i)>*(d+i))
		return 1;
	if(*(s+i)<*(d+i))
		return -1;
	else
		return 0;

}

/*creaes duplicated string*/
char *strdupl(char *s){
	int i =0;
	char *d = (char*)malloc(sizeof(char*)*100);
	while(*(s+i)!='\0'){
		*(d+i) = *(s+i);
		i++;
	}
	*(d+i) = '\0';

	return d;
}

