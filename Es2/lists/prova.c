#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[]) {
    LIST mylist;
    ItemType i;

    mylist = NewList();
    printf("[Fase di inizializzazione]: Creata lista\n");

    printf("[Fase di Controllo]: ");
    if (isEmpty(mylist))
        printf(" La lista e' vuota\n");
    else
        printf(" La lista non e' vuota \n");

    printf("\n");
    printf("[Fase di Inserimento dati]\n");

    printf("La lista contiene %d elementi\n", getLength(mylist));

    printf("Contenuto della lista: [");
    PrintList(mylist);
    printf("]\n");

    i.value = 4.004;
    mylist = EnqueueLast(mylist, i);

    printf("La lista contiene %d elementi\n", getLength(mylist));

    i.value = 3.34;
    mylist = EnqueueLast(mylist, i);

    printf("La lista contiene %d elementi \n", getLength(mylist));

    i.value = 0.42;
    mylist = EnqueueLast(mylist, i);

    printf("La lista contiene %d elementi\n", getLength(mylist));

    i.value = 1.2345;
    mylist = EnqueueLast(mylist, i);

    printf("La lista contiene %d elementi\n", getLength(mylist));

    i.value = 1.1823;
    mylist = EnqueueLast(mylist, i);

    printf("La lista contiene %d elementi\n", getLength(mylist));
    printf("\n");
    
    i.value = 777;
    mylist = EnqueueFirst(mylist, i);
    printf("[Nella lista ho aggiunto in testa il valore %f e ora contiene %d elementi]\n", i.value, getLength(mylist));

    printf("Contenuto della lista: [");
    PrintList(mylist);
    printf("]\n");

    printf("Elemento di testa ");
    PrintItem(getHead(mylist));
    printf("\n");

    printf("Elemento di coda ");
    PrintItem(getTail(mylist));
    printf("\n");

    printf("Ho rimosso l'ultimo elemento, [%f], ", getTail(mylist));
    DequeueLast(mylist);
    printf("e ora l'elemento di coda è [%f]\n", getTail(mylist));
    printf("\n");
    

    printf("[Fase di Estrazione dati]\n");
    i.value = 1.2345;
    printf("Estrazione elemento ");
    PrintItem(i);
    printf("\n");
    mylist = Dequeue(mylist, i);

    i.value = 9.9999;
    printf("Estrazione elemento ");
    PrintItem(i);
    printf("\n");
    mylist = Dequeue(mylist, i);

    i.value = 4.004;
    printf("Estrazione elemento ");
    PrintItem(i);
    printf("\n");
    mylist = Dequeue(mylist, i);

    printf("Estrazione primo elemento\n");
    mylist = DequeueFirst(mylist);

    printf("Contenuto della lista: [");
    PrintList(mylist);
    printf("]\n");

    printf("\n[Creazione di una nuova lista: ]\n");
    LIST orderedlist;
    orderedlist = NewList();
    i.value = 4;
    orderedlist = EnqueueLast(orderedlist, i);
    printf("La nuova lista contiene %d elementi\n", getLength(orderedlist));

    i.value = 7;
    orderedlist = EnqueueLast(orderedlist, i);
    printf("La nuova lista contiene %d elementi \n", getLength(orderedlist));

    i.value = 9;
    orderedlist = EnqueueLast(orderedlist, i);
    printf("La nuova lista contiene %d elementi\n", getLength(orderedlist));

    i.value = 15;
    orderedlist = EnqueueLast(orderedlist, i);    
    printf("La nuova lista contiene %d elementi\n", getLength(orderedlist));

    i.value = 54;
    orderedlist = EnqueueLast(orderedlist, i);
    printf("La nuova lista contiene %d elementi\n", getLength(orderedlist));
    printf("\n");

    i.value = 1;
    orderedlist = EnqueueOrdered(orderedlist, i);
    printf("La nuova lista contiene %d elementi; l'ultimo aggiunto è sottoposto ad ordinamento\n", getLength(orderedlist));
    printf("\n");

    printf("Contenuto della lista: [");
    PrintList(orderedlist);
    printf("]\n");










    printf("Fase di Distruzione dati\n");
    mylist = DeleteList(mylist);




    printf("Fase di Controllo: ");
    if (isEmpty(mylist))
        printf(" La lista e' vuota\n");
    else
        printf(" La lista non e' vuota \n");

    return 0;

} /* Main */
