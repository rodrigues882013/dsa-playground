#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

type_pt_node allocate(int data)
{
    type_pt_node new_node = (type_pt_node) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->color = 0;

    return new_node;
}

int max(int a, int b) {
    return a<b ? a : b;
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
        return 1 + max(get_height(head->left), get_height(head->right));
    }
}

type_pt_node rotate_to_right(type_pt_node* head)
{
    type_pt_node subtree = (*head)->left;
    type_pt_node temp = subtree->right;
 
    // Perform rotation
    subtree->right = *head;
    (*head)->left = temp;

    return subtree;
}

type_pt_node rotate_to_left(type_pt_node* head)
{
    type_pt_node subtree = (*head)->right;
    type_pt_node temp = subtree->left;
 
    // Perform rotation
    subtree->left = *head;
    (*head)->right = temp;

    return subtree;
}

void avl_balance(type_pt_node* head, int data)
{
    // Get height for right subtree
    int height_right = get_height((*head)->right);

    // Get height for left subtree
    int height_left = get_height((*head)->left);

    // Calculate balance factor
    int balance = height_left - height_right;

    if (balance < -1)
    {
        if (data < (*head)->right->data )
        {
            //Right-Left
            (*head)->right = rotate_to_right(&(*head)->right);
            (*head) = rotate_to_left(&(*head));
        }
        else
        {
            //Left
            (*head) = rotate_to_left(&(*head));
        }
    }
    else if (balance > 1)
    {
        if (data > (*head)->left->data )
        {
            //Left-Right
            (*head)->left = rotate_to_left(&(*head));
            (*head) = rotate_to_right(&(*head));
        }
        else
        {
            // Right
            (*head) = rotate_to_right(&(*head));
        }

    }
}

void insert_node(type_pt_node new_node, type_pt_node* head)
{
    
    if (new_node == NULL) 
    {
        printf("ERROR: It was not allocated");
        return;
    }

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {

        if (new_node->data > (*head)->data)
        {
            insert_node(new_node, &(*head)->right);
        }
        else if (new_node->data < (*head)->data)
        {
            insert_node(new_node, &(*head)->left);
        }
        else if (new_node->data > (*head)->data)
        {
            printf("ERROR: Data already present");
            return;
        } 
    }

    // Check if the three keep the invariant
    avl_balance(&(*head), new_node->data);
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
    avl_balance(&(*head), data);
}

void insert(int data, type_pt_node* head)
{
    insert_node(allocate(data), head);
}

void delete(int data, type_pt_node *head)
{
    delete_node(data, head);
    
}

int find(int data, type_pt_node head){
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