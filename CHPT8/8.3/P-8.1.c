#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Treenode
{
    struct Treenode *L, *R;
    element data;
} Treenode;

int main()
{
    Treenode *root = (Treenode*)malloc(sizeof(Treenode));
    root -> data = 20;
    Treenode *n1 = (Treenode*)malloc(sizeof(Treenode));
    n1 -> data = 10;
    Treenode *n2 =(Treenode*)malloc(sizeof(Treenode));
    n2 -> data = 11;
    root -> L = n1;
    root -> R = n2;
    /*
            20
           /  \
          10  11 
    
    */
}