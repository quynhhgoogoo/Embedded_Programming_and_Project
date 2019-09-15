#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s)
{
		int c=0;
			while(*(s+c) != '\0')
						c++;
				return c;
}

int str2upper(char *s)
{
		int c=0;
			int i=0;
				while(*(s+c) != '\0')
						{
									if(*(s+c) >= 'a' && *(s+c) <= 'z')
												{
																*(s+c) = *(s+c) -32;
																			i++;
																					}
											c++;
												}
					return i;
}

int str2lower(char *s)
{
		int c=0;
			int i=0;
				while(*(s+c) != '\0')
						{
									if(*(s+c) >= 'A' && *(s+c) <= 'Z')
												{
													                        *(s+c) = *(s+c) + 32;
																			i++;
																					}
									                c++;
												}
					return i;
}

int str_strip_numbers(char *s)
{
		char *dest=s;
			char *src=s;
				int c=0;
					while(*src)
							{
										if(*(src+c)>=0 && *(src+c)<=9)
													{
																	c++;
																				continue;
																						}
												*(dest+c) = *(src+c);
													}
						*dest = '\0';
							int len = my_strlen(dest);
								return len;
}

void mystrcpy(char *s, char*d)
{
		while (*s)
				{
							*d=*s;
									s++;
											d++;
												}
			*d='\0';
}

int mystrcmp(char *s, char *d)
{
		while (*s == *d)
				{
					      		if (*s == '\0' || *d == '\0')
								        		break;
							        	s++;
									      		d++;
												}
		   	if (*s == *d)
				      		return 0;
			   	else if (*s<*d)
					      		return -1;
					else
								return 1;
}

char *strdupl(char *s)
{
		char *d=(char*)malloc(sizeof(char*)*100);
			mystrcpy(d,s);
				return d;
}

