#ifndef TREE_H
#define TREE_H

#define TRUE 1
#define FALSE 0

// Main struct
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    char color;
};

// Type for pointer
typedef struct Node *type_pt_node;

// Prototypes
type_pt_node allocate(int);
int find(int, type_pt_node);
void add(type_pt_node*, int);
void delete(int, type_pt_node*);
void show_in_order(type_pt_node);
void show_in_preorder(type_pt_node);
void show_in_postorder(type_pt_node);

#endif //TREE_H