#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

/*Function will create a new list item and add that to end of list
*ll is pointing to head/last element of the list
return: -1 as error (no space left), index position in succes*/

int add_to_list(linked_list *ll, char *s){
	linked_list *temp = ll;
	linked_list*last = NULL;
	
	int index = temp->index;
	
	/*check if pointer is null*/
	if(s == NULL || ll == NULL){
		return -1;
	}
	else{
		/*Find out last node*/
		while(temp->next){
			temp = temp->next;
			index = temp->index;
		}
		
		/*create a new element*/
		linked_list *new_node = (linked_list*) malloc(sizeof(linked_list));
		
		new_node -> data = s;
		new_node -> next = NULL;
		new_node -> index = index+1;

		/*Point last node's link to new node*/
		temp->next = new_node;
		return new_node->index;
	}
}

/*Displays the required element (pointed by parameter linked_list *ll) in a list
  Return: -1 element not found , 0 ok*/

int display_item(linked_list *ll){
	linked_list *temp = ll;
	/*if list is empty*/
	if(ll == NULL){
		return -1;
	}
	else{
		//printf("%s", temp->data);
		temp = temp->next;
		return 0;
	}
}
/*List all elements in a list
  return: number of elements in list*/
  
int display_list(linked_list *ll){
	linked_list*temp=ll;
	int index = 0;
	
	if(ll == NULL){
		return -1;
	}
	else{
		while(temp!=NULL){
			//printf("%s", temp->data);
			temp = temp->next;
		}
		index +=1;
		return index;
	}
}
/*Search for a data *s from a list
Return: NULL if not found, pointer to */

linked_list *search_from_list(linked_list *ll, char *s){
	linked_list*temp = ll;
	/*if pointer is NULl*/
	if(s == NULL || ll == NULL){
		return NULL;
	}
	else{
		while(temp!=NULL){
			if(strcmp(s, temp->data) == 0){
				printf("Element found");
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
}
/*	Delete item from a list and free space
	Rest of list items index will be counted again
    Return value: -1 on error, length of remaining list*/
	
int delete_from_list(linked_list *ll, int index){
	linked_list*temp = ll;
	linked_list*prev = NULL;
	
	int max_len = display_list(ll), len;
	/*if pointer is null and index is not available*/
	if(ll == NULL || index <0 || index > max_len){
		return -1;
	}
	else{
		while(temp!=NULL){
			/*If node holds the key to be deleted*/
			if(temp->index == index){
				ll = temp->next;
				free(temp);
				len = display_list(ll);
				return len;
				break;
			}
			/*if node is not holding the key to be deleted*/
			else{
				prev = temp;
				temp = temp->next;
			}
		}
		/*Unlink node from linked list*/
		prev->next = temp->next;
		free(temp);
	}
}
