typedef struct linked_list linked_list;

struct linked_list{
	char *data;
	int index;	/*position of the element in the list*/
	struct linked_list *next;
};

/*create new list item and add to the end of the list*/
int add_to_list(linked_list *ll, char *s);

/*display required element in a list*/
int display_item(linked_list *ll);

/*list all elements in a list*/
int display_list(linked_list *ll);

/*search for data *s from a list*/
linked_list *search_from_list(linked_list *ll, char *s);

/*delete item from a list and free space*/
int delete_from_list(linked_list *ll, int index);
