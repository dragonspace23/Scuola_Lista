#ifndef LIST_INCLUDE
#define LIST_INCLUDE

#include <stdio.h>
#include <stdlib.h>

enum mode {
	head,
	tail,
};

struct node {
	int info;
	node *next;
};

void add_node(int mode, node **list);

void print_nodes(node *list);
int count_nodes(node *list);
int is_list_empty(node *list);

void max_info(node *list);

node * sum_list(node *first_list, node *second_list);


#endif // !LIST_INCLUDE
