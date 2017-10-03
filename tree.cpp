#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//pt_no pt_corr;


void add(node **self, node *no)
{
    if (*self == NULL)
    {
        *self = no;

    }
    else
    {
        if((*self)->key < no->key)
        {
            add(&(*self)->left, no);
        }
        else
        {
            add(&(*self)->right, no);
        }
    }
}

void show(node *root)
{
    printf("%d\n", root->key);
}

void remove(int key)
{

}

int find(int key)
{
    return 0;
}
