#include "tree.cpp"

int main()
{
    pt_no pt_tree = NULL, pt_aux;

    int key;

    do
    {
        printf("Type the number for insert in Tree or 0 to exit: ");
        scanf("%d", &key);

        if(key != 0)
        {
            pt_aux = (pt_no) malloc(sizeof(struct node));
            pt_aux->key = key;
            pt_aux->left = NULL;
            pt_aux->right = NULL;
            add(&pt_tree, pt_aux);
            free(pt_aux);
        }
    } while(key != 0);

    return 0;
}

