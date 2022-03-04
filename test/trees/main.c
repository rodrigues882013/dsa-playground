#include <stdio.h>
#include <stdlib.h>
#include "../../src/trees/tree.c"


int main(int argc, char** args)
{
    type_pt_node head = NULL;

    add(&head, 10);
    add(&head, 4);
    add(&head, 20);
    add(&head, 90);
    add(&head, 3);
    add(&head, 50);
    add(&head, 2);
    add(&head, 40);
    add(&head, 91);
    add(&head, 1);

    show_in_order(head);
    delete(10, &head);


    printf("Everything is all right, we've already finished\n");
    return 0;
}