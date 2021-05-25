#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* createNode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data= data;
    n->left= NULL;
    n->right = NULL;

    return n;
}

void inOrder(struct node* first){   // taking entire linklist
    if(first!=NULL){                 //IMportant must check for NULL case.....
        inOrder(first->left);
        printf("%d ", first->data);
        inOrder(first->right);
    }
}

int main(){

    struct node *p0= createNode(5);
    struct node *p1= createNode(3);
    struct node *p2= createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4= createNode(4);


    p0->left = p1;
    p0->right = p2;
    p1->left = p3;
    p1->right = p4;


    inOrder(p0);


return 0;}









