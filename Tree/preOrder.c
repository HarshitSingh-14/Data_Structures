#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* createnode(int data){

    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left= NULL;
    n->right= NULL;

    return n;
}

void printTreepre(struct node* root){
    if(root!=NULL){
        printf("%d",root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    struct node *n0=createnode(1);
    struct node *n1=createnode(2);
    struct node *n2=createnode(3);
    struct node *n3=createnode(4);
    struct node *n4=createnode(5);


    n0->left = n1;
    n0->right =n2;
    n1->left=n3;
    n1->right =n4;

    printTreepre(n0);
}
