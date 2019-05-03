#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#ifdef _WIN32
#define clear() system("cls")
#endif // _WIN32

#ifdef __unix__
#define clear() system("clear")
#endif // __unix__

#define pause() printf("Premi Invio per continuare"); getchar()


int main(int argc, char **argv) {
	node *lista_uno = NULL;
	node *lista_due = NULL;

	int cont = 1;
	do {
		clear();
		
		int scelta;
		printf("1 - Aggiungere un nodo in testa\n2 - Aggiungere un nodo in coda\n3 - Rimuovere un nodo in testa\n4 - Rimuovere un nodo in coda\n5 - Stampa\n6 - Trovare il maggiore\n7 - Contare i nodi\n8 - Sommare le 2 liste\n9 - Uscire\nScelta: ");
		scanf("%d", &scelta);
		getchar();

		clear();

		int coda;
		node **ptr = NULL;
		switch (scelta) {
		case 1:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1)&&(coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			add_node(head, ptr);
			input_node(head, *ptr);

			pause();
			break;

		case 2:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1) && (coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			add_node(tail, ptr);
			input_node(tail, *ptr);

			pause();
			break;

		case 3:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1) && (coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			del_node(head, ptr);

			pause();
			break;

		case 4:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1) && (coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			del_node(tail, ptr);

			pause();
			break;
		case 5:
			printf("Lista 1\n");
			print_nodes(lista_uno);
			printf("Lista 2\n");
			print_nodes(lista_due);

			pause();
			break;

		case 6:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1) && (coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			max_info(*ptr);

			pause();
			break;

		case 7:
			do {
				printf("Coda [1/2]: ");
				scanf("%d", &coda);
				getchar();
			} while ((coda != 1) && (coda != 2));
			ptr = (coda == 1 ? &lista_uno : &lista_due);

			max_info(*ptr);

			pause();
			break;

		case 8:
			printf("Somma delle liste\n");
			print_nodes(sum_list(lista_uno, lista_due));

			pause();
			break;

		case 9:
			cont = false;
			break;
		}

		clear();
	} while (cont);

	return 0;
}