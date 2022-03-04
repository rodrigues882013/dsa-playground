#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)


type_pt_node allocate(int data)
{
    type_pt_node new_node = (type_pt_node) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->color = 0;

    return new_node;
}

int get_height(type_pt_node head)
{
    if (head == NULL)
    {
        return 0;
    }
    else if (head->left == NULL && head->right == NULL)            
    {
        return 1;
    }
    else if (head->left == NULL)
    {
        return 1 + get_height(head->right);
    } 
    else if (head->right == NULL)
    {
        return 1 + get_height(head->left);
    }
    else
    {
        return 1 + MAX(get_height(head->left), get_height(head->right));
    }
}

type_pt_node* right_rotate(type_pt_node* node)
{
    type_pt_node* subtree = &(*node)->left;
    type_pt_node* temp = &(*subtree)->right;
 
    // Perform rotation
    (*subtree)->right = *node;
    (*node)->left = temp;

    return &(*subtree);
}

type_pt_node* left_rotate(type_pt_node* node)
{
    type_pt_node* subtree = &(*node)->right;
    type_pt_node* temp = &(*subtree)->left;
 
    // Perform rotation
    (*subtree)->left = *node;
    (*node)->right = temp;

    return &(*subtree);
}

void rebalance(type_pt_node* node, int data)
{
    // Get height for right subtree
    int height_right = get_height((*node)->right);

    // Get height for left subtree
    int height_left = get_height((*node)->left);

    // Calculate balance factor
    int balance = height_left - height_right;

    if (balance < -1)
    {
        if (data < (*node)->right->data)
        {
            //Right-Left
            (*node)->right = right_rotate(&(*node)->right);
            *node = right_rotate(&(*node));
        }
        else
        {
            //Left
            *node = left_rotate(&(*node));
        }
    }
    else if (balance > 1)
    {
        if (data > (*node)->left->data)
        {
            //Left-Right
            (*node)->left = left_rotate(&(*node)->left);
            *node = left_rotate(&(*node));
        }
        else
        {
            // Right
            *node = right_rotate(&(*node));
        }

    }
}

void insert(type_pt_node* root, int data)
{
    
    if (*root == NULL)
    {
        *root = allocate(data);
    }
    else
    {

        if (data > (*root)->data)
        {
            insert(&(*root)->right, data);
        }
        else if (data < (*root)->data)
        {
            insert(&(*root)->left, data);
        }
        else if (data > (*root)->data)
        {
            printf("ERROR: Data already present");
            return;
        } 
    }

    // Check if the three keep the invariant
    rebalance(&(*root), data);
}

type_pt_node find_in_order_sucessor(type_pt_node start_point)
{
    if (start_point->left == NULL)
    {
        return start_point;
    }
    else 
    {
        return find_in_order_sucessor(start_point->left);
    }
}

type_pt_node find_in_order_predecessor(type_pt_node start_point)
{
    if (start_point->left == NULL)
    {
        return start_point;
    }
    else 
    {
        return find_in_order_sucessor(start_point->left);
    }
}

void delete_node(int data, type_pt_node *head)
{
    if (*head == NULL)
    {
        return;
    }
    else
    {
        if (data > (*head)->data)
        {
            delete_node(data, &(*head)->right);
        }
        else if (data < (*head)->data)
        {
            delete_node(data, &(*head)->left);
        }
        else if (data == (*head)->data)
        {
            if ((*head)->left == NULL && (*head)->right == NULL)
            {
                *head = NULL;
            }
            else if ((*head)->left == NULL)
            {
                *head = (*head)->right;
            } 
            else if ((*head)->right == NULL)
            {
                *head = (*head)->left;
            } 
            else
            {
                type_pt_node successor = find_in_order_sucessor((*head)->right);
                (*head)->data = successor->data;

                // The rightmost node
                delete_node(successor->data, &(*head)->right);
            }
        }
    }

    // Check if the three keep the invariant
    rebalance(&(*head), data);
}

void add(type_pt_node* head, int data)
{
    insert(head, data);
}

void delete(int data, type_pt_node *head)
{
    delete_node(data, head);
    
}

int find(int data, type_pt_node head)
{
    if (head == NULL) 
    {
        return FALSE;
    }
    else
    {

        if (data > head->data)
        {
            return find(data, head->right);
        }
        else if (data < head->data)
        {
            return find(data, head->left);
        }
        else
        {
            return head->data;
        }
        
    }
}

void show_in_order(type_pt_node head)
{
    if (head == NULL) 
        return;
    
    show_in_order(head->left);
    printf("%d ", head->data);
    show_in_order(head->right);
}

void show_in_preorder(type_pt_node head)
{
    if (head == NULL) 
        return;

    printf("%d ", head->data);
    show_in_preorder(head->left);
    show_in_preorder(head->right);
}

void show_in_postorder(type_pt_node head)
{
    if (head == NULL) 
        return;
        
    show_in_postorder(head->left);
    show_in_postorder(head->right);
    printf("%d ", head->data);

}