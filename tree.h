//
// Created by felipe on 02/10/17.
//

#ifndef TREE_H
#define TREE_H

struct node{
    int key;
    struct node *left;
    struct node *right;


};
extern void add(node**, node*);
extern void show(node*);
extern void remove(int);
extern int find(int);

typedef struct node *pt_no;


#endif //TREE_H
