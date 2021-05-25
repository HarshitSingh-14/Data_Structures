#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n=(struct node*)malloc(sizeof (struct node));
    n->data =data;
    n->left =NULL;
    n->right =NULL;

    return n;
}

void printNode
int main(){

    struct node*n=createNode(1);
    struct node*n1=createNode(2);
    struct node*n2=createNode(3);


    n->left=n1;
    n->right=n2;

    return 0;

}
