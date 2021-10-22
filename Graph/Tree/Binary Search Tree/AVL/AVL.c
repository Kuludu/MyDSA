#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    int height;
    struct Node *left_son;
    struct Node *right_son;
}node;

int height(node *t)
{
    return !t ? -1 : t->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void inOrderTraversal(node *t)
{
    if (t) 
    {
        inOrderTraversal(t->left_son);
        printf("%d\n", t->data);
        inOrderTraversal(t->right_son);
    }
}

node * search(node *t, int x)
{
    if (!t) 
    {
        return NULL;
    }
    else if (t->data > x)
    {
        return search(t->left_son, x);
    }
    else if (t->data < x)
    {
        return search(t->right_son, x);
    }

    return t;
}

void singleRotateLeft(node *t2) 
{
    node *t1 = t2->left_son;
    t2->left_son = t1->right_son;
    t1->right_son = t2;

    t1->height = max(height(t1->left_son), height(t1->right_son)) + 1;
    t2->height = max(height(t2->left_son), height(t2->right_son)) + 1;
}

void singleRotateRight(node *t2)
{
    node *t1 = t2->left_son;
    t2->right_son = t1->left_son;
    t1->left_son = t2;
}

void doubleRotateLR(node *t3)
{
    singleRotateRight(t3->left_son);
    singleRotateLeft(t3);
}

void doubleRotateRL(node *t3)
{
    singleRotateLeft(t3->right_son);
    singleRotateRight(t3);
}

node * insert(node *t, int x)
{
    if (!t) 
    {
        t = malloc(sizeof(node));
        t->data = x;
    } 
    else if (t->data > x) 
    {
        t->left_son = insert(t->left_son, x);
        if (2 == height(t->left_son) - height(t->right_son))
        {
            if (x < t->left_son->data)
            {
                singleRotateLeft(t);
            }
            else
            {
                doubleRotateLR(t);
            }
        }
    } 
    else if (t->data < x)
    {
        t->right_son = insert(t->right_son, x);
        if (2 == height(t->right_son) - height(t->left_son))
        {
            if (x > t->right_son->data)
            {
                singleRotateRight(t);
            }
            else
            {
                doubleRotateRL(t);
            }
        }
    } else {
        printf("Redundant.\n");
    }

    return t;
}

int main() 
{
    printf("Demostration of AVL.\n");

    node *avl = NULL;

    avl = insert(avl, 1);
    avl = insert(avl, 4);
    avl = insert(avl, 2);
    avl = insert(avl, 7);
    avl = insert(avl, 10);
    avl = insert(avl, 7);

    inOrderTraversal(avl);

    if (!search(avl, 100))
    {
        printf("Not found!\n");
    }

    return 0;
}