#ifndef LIST_INCLUDE
#define LIST_INCLUDE

#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	node *next;
};

void add_node(node **list);
void input_node(node *list);
void print_nodes(node *list);
int count_nodes(node *list);
int is_list_empty(node *list);

void max_node(node *list);


#endif // !LIST_INCLUDE
