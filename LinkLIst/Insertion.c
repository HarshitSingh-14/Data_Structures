#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  // pointer MUST
};    // BECOMES datatype

void linkedListTraversal(struct Node *ptr){// ponter to travel
    while(ptr!=NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// [1] NEW NODE in STARTING
struct Node insertAtFirst(struct Node *head,int data1){ // pointer
    struct Node *ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data = data1;
        ptr->next = head;

    return *ptr;
};
// [3] insett At LAST
struct Node *insertAtEnd(struct Node *head , int data1){
    struct Node * ptr =(struct Node*) malloc(sizeof(struct Node));
    ptr-> data =data1;
    struct Node *p = head;  // intialise p
    while(p->next!=NULL){
        p=p->next;
    }
    p->next =ptr;
    ptr->next =NULL;
    return head;
}


// [2] Insert in Between
struct Node *insertAtIndex(struct Node *head, int data1 , int index){
struct Node *ptr = (struct Node *) malloc (sizeof(struct Node)); // newNode
struct Node *p = head;  //to intialise p toStartingthan MOVE
int i = 0;
    while(i!=index-1)
    {
        p=p-> next;
        i++;    // get p to 1 before
    }
    ptr-> data = data1;
    ptr-> next = p-> next;

    p->next = ptr;

    return head;
};

// INsert aAfter a NODE
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data1){
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr-> data =data1;
    ptr -> next = prevNode-> next;

    prevNode->next =ptr;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocate memory in Heap of linked list
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node ));
    fourth= (struct Node*) malloc(sizeof(struct Node));

    //link each other...
    head-> data = 7;
    head -> next = second;

    second-> data =23;
    second-> next= third;

    third-> data =2;
    third-> next =fourth;

    fourth->data =11;
    fourth -> next =NULL;

    linkedListTraversal(head);
    printf("\n");
    //head = insertAtFirst(head,1);
    head = insertAtIndex(head, 2356, 1);
    linkedListTraversal(head);
    printf("\n");
    head = insertAtEnd(head, 9);
    linkedListTraversal(head);
    printf("\n");

    head = insertAfterNode(head ,second,23412512);
    linkedListTraversal(head);



}
