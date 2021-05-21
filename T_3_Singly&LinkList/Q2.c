#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int s;

void insertAtStart(struct Node** head_ptr,int data){
    printf("Inserts at begining\n");
    struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));

    new_node->data = data;
    new_node->next = (*head_ptr);
    new_node->prev = NULL;

    (*head_ptr) = new_node;

    s+=1;
}

void insertAtEnd(struct Node** head_ptr, int data){
    printf("Inserting at the end\n");
    struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));

    new_node->data = data;
    new_node->next = NULL;

    if(*head_ptr==NULL){
        *head_ptr = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        s+=1;
        return;
    }

    else{
    struct Node* last = (*head_ptr);

    while(last->next!=NULL){
        last=last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    s+=1;
    return;
    }

}


void insertAnywhere(struct Node** head_ptr, int data, int x){
    printf("Inserting after x\n");
    struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));

    new_node->data = data;

    struct Node* last = *head_ptr;

    while(last->data!=x){
        last=last->next;
    }

    new_node->prev = last;
    new_node->next = last->next;
    last->next = new_node;
    s+=1;
    return;
}

void DeleteMiddle(struct Node** head_ptr){
    printf("Deleting the middle node\n");
    int middle = round(s/2);

    if(middle==0){
        printf("Cannot Delete");
        return;
    }

    else if(middle==1){
        *head_ptr=NULL;
        s-=1;
        return;
    }

    struct Node* last =*head_ptr;

    int count = 1;

    while(count!=middle){
        last=last->next;
        count+=1;
    }

    struct Node* second_last = last->prev;
    second_last->next= last->next;
    s-=1;

}

void DeleteLast(struct Node** head_ptr){
    printf("Deleting the last node\n");

    struct Node* last = *head_ptr;

    while((last->next)->next!=NULL){
        last=last->next;
    }

    last->next=NULL;
    s-=1;

}

void printEven(struct Node** head_ptr){
    printf("Even nodes\n");

    int count=1;

    struct Node* last = *head_ptr;

    while(last!=NULL){
        if(count%2==0) printf("%d ",last->data);
        count+=1;
        last=last->next;
    }
    printf("\n");
}

void printSumOdd(struct Node** head_ptr){
    printf("Sum of odd nodes\n");
    int count=1;
    int sum=0;
    struct Node* last = *head_ptr;

    while(last!=NULL){
        if(count%2!=0) sum+=last->data;
        count+=1;
        last=last->next;
    }

    printf("%d\n",sum);
}


void DeleteAlternative(struct Node** head_ptr){
    printf("Deleting alternative nodes\n");
    if (*head_ptr == NULL) return;

    *head_ptr=(*head_ptr)->next;

    struct Node *previous, *current, *next_node;
    previous = *head_ptr;
    current = (*head_ptr)->next;
    while (previous !=NULL && current != NULL)
    {
        previous->next = current->next;
        next_node = current->next;
        if(next_node)
        {
            next_node->prev = previous;
            current = next_node->next;
        }
        else
        current = NULL;
        previous = next_node;
    }
}


static void reverse(struct Node** head_ptr)
{
    printf("Reversing the list\n");
     struct Node *temp = NULL;
     struct Node *current = *head_ptr;

     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
     }

     if(temp != NULL )
        *head_ptr = temp->prev;
}

void printList(struct Node* head)
{
    struct Node* last = head;
    while (last != NULL) {
        printf("%d  ", last->data);
        last = last->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int x;
    printf("Write no. to be inerted in begining\n");
    scanf("%d", &x);
    insertAtStart(&head, x);
    printList(head);
    printf("\n");

    printf("Write no. to be inerted at the end\n");
    scanf("%d", &x);
    insertAtEnd(&head, x);
    printList(head);
    printf("\n");

    printf("Write the no. and the no. after which it will come\n");
    scanf("%d",&x);
    int y;
    scanf("%d",&y);
    insertAnywhere(&head, x,y);
    printList(head);
    printf("\n");


    printf("Write no. to be inerted at the end\n");
    scanf("%d", &x);
    insertAtEnd(&head, x);
    printList(head);
    printf("\n");


    printf("Write no. to be inerted at the end\n");
    scanf("%d", &x);
    insertAtEnd(&head, x);
    printList(head);
    printf("\n");

        printf("Write no. to be inerted at the end\n");
    scanf("%d", &x);
    insertAtEnd(&head, x);
    printList(head);
    printf("\n");

        printf("Write no. to be inerted at the end\n");
    scanf("%d", &x);

    insertAtEnd(&head, x);
    printList(head);
    printf("\n");


    printEven(&head);
    printf("\n");
    printSumOdd(&head);
    printf("\n");



    reverse(&head);
    printList(head);
    printf("\n");




    DeleteLast(&head);
    printList(head);
    printf("\n");




    DeleteMiddle(&head);
    printList(head);
    printf("\n");




    DeleteAlternative(&head);
    printList(head);


}


