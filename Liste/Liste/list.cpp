#include "list.h"

void add_node(int mode, node **list) {
	if (mode == head) {
		node *temp = (node*)malloc(sizeof(node));
		temp->info = NULL;
		temp->next = *list;
		list = &temp;
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

			printf("Valore: ");
			scanf("%d", &ptr->info);
		}
		else {
			*list = (node*)malloc(sizeof(node));
		}
	}
}

void input_node(node *list) {
	printf("Inserire valore\nValore: ");
	scanf("%d", &list->info);
}

void print_nodes(node *list) {
	if (is_list_empty)
		printf("Lista vuota\n");
	else {
		printf("Lista\nValore 1: %d\n", list->info);

		int i = 2;
		node *ptr = list->next;
		while (ptr->next) {
			printf("Valore %d: %d\n", i, ptr->info);
			i++;
			ptr = ptr->next;
		}
	}
}

int count_nodes(node *list) {
	if (is_list_empty)
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
	return list ? 1 : 0;
}

void max_info(node *list) {
	if (is_list_empty)
		printf("Lista vuota\n");
	else {
		int max = list->info;

		node *ptr = list->next;
		while (ptr->next) {
			if (ptr->info > max)
				max = ptr->info;

			ptr = ptr->next;
		}

		printf("Max: %d", max);
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
		
		do {
			add_node(head, &third_list);
			third_list->info = first_list->info + second_list->info;

			first_list = first_list->next;
			second_list = second_list->next;
		} while ((first_list->next) && (second_list->next));

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