#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv) {

	int scelta, uscire = 0;
	node *list;

	do{	
		printf("Scegliere che operazione eseguire:\n0)Aggiungere un nodo\n1)Inserire valore.\n2)Stampa\n3)Trovare il max\n4)Contare i nodi\n5)Sommare le due liste\n");
		scanf("%d", &scelta);
	
		switch (scelta){
			case 0:
				add_node();
				break;
			case 1:
				input_node();
				break;
			case 2:
				print_nodes();
				break;
			case 3:
				max_node();
				break;
			case 4:
				count_nodes();
				break;
			case 5:
				add_nodes();
				break;
		}
		
		printf("Per uscire premere 1");
		scanf("%d", &uscire);
	}while(uscire != 1);
	return 0;
}


