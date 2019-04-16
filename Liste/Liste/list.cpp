#include "list.h"

void add_node(int mode, node **list) {
	if (mode == head) {
		node *temp = (node*)malloc(sizeof(node));
		temp->info = NULL;
		temp->next = *list;
		*list = temp;
	}
	else if (mode == tail) {
		if (*list) {
			node *ptr = *list;
			while (ptr->next) {
				ptr = ptr->next;
			}

			ptr->next = (node*)malloc(sizeof(node));
			ptr = ptr->next;
			ptr->next = NULL;
			ptr->info = NULL;
		}
		else {
			*list = (node*)malloc(sizeof(node));
			(*list)->next = NULL;
			(*list)->info = NULL;
		}
	}
}

void input_node(int mode, node *list) {
	node *ptr = list;

	if (mode == tail) {
		while (ptr->next) {
			ptr = ptr->next;
		}
	}

	printf("Inserire valore\nValore: ");
	scanf("%d", &ptr->info);
	getchar();
}

void print_nodes(node *list) {
	if (is_list_empty(list))
		printf("Lista vuota\n");
	else {
		printf("Valore 1: %d\n", list->info);

		int i = 2;
		node *ptr = list;
		while (ptr->next) {
			ptr = ptr->next;
			printf("Valore %d: %d\n", i, ptr->info);
			i++;
		}
	}
}

int count_nodes(node *list) {
	if (is_list_empty(list))
		return 0;

	node *ptr = list->next;
	int i = 1;
	while (ptr->next) {
		i++;
		ptr = ptr->next;
	}

	return i;
}

int is_list_empty(node *list) {
	return list ? 0 : 1;
}

void max_info(node *list) {
	if (is_list_empty(list))
		printf("Lista vuota\n");
	else {
		int max = list->info;

		node *ptr = list;
		while (ptr->next) {
			if (ptr->info > max)
				max = ptr->info;

			ptr = ptr->next;
		}

		printf("Max: %d\n", max);
	}
}

node *sum_list(node *first_list, node *second_list) {
	if (is_list_empty(first_list))
		return second_list;
	else if (is_list_empty(second_list))
		return first_list;
	else if (is_list_empty(first_list) && is_list_empty(second_list))
		return NULL;
	else {
		node *third_list = NULL;
		
		while ((first_list->next) && (second_list->next)) {
			add_node(head, &third_list);
			third_list->info = first_list->info + second_list->info;

			first_list = first_list->next;
			second_list = second_list->next;
		}

		node *ptr = third_list;
		while (ptr->next) {
			ptr = ptr->next;
		}

		if (first_list->next) {
			ptr->next = first_list->next;
		}
		else if(second_list->next) {
			ptr->next = second_list->next;
		}

		return third_list;
	}

}