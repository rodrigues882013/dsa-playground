#include <stdio.h>
#include <stdlib.h>
#include "../../src/trees/tree.c"


int main(int argc, char** args)
{
    type_pt_node head = NULL;

    insert(10, &head);
    insert(4, &head);
    insert(20, &head);
    insert(90, &head);
    insert(3, &head);
    insert(50, &head);
    insert(2, &head);
    insert(40, &head);
    insert(91, &head);
    insert(1, &head);

    delete(10, &head);

    printf("Everything is all right, we've already finished\n");
    return 0;
}