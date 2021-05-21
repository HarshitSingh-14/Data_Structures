#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

int peek(int position, struct Node* top){
struct Node* ptr= top;
for(int i =0 ; i< position-1&&ptr!=NULL;i++ )
    {
        ptr = ptr-> next;
    }
if(ptr!=NULL){
                    return ptr->data;
             }

else    {
            return -1;
        }
}

int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void printList(struct Node* ptr){

    while (ptr!=NULL)
    {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
    }
}


int isFull(struct Node* top){
    //struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if(top=NULL){
        return 1;
    }
    else{
        return 0;
    }
}


struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack is full");
    }
    else{
        // Must CREATE Linklist we need..

        struct Node* n=(struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top= n;
        return top;
    }
}

// TRY POP....
int pop(struct Node** top){   // Must SEE and Use double pointer whenever NOT to give linklist in return
    if(isEmpty(*top)){       // *top instead of top --> to pass linklist
        printf("Stack is 0");
    }
    else{
        struct Node* temp = *top;
        *top= (*top)->next; // skip the top{..THE FIRST..}
        int x= temp->data;
        free(temp);
        return x;
    }
}

int main(){
    struct Node* top=NULL;
    top = push(top,8);
        top = push(top,3);
    top = push(top,9);
    top = push(top,1);
    pop(&top);

    printList(top);

    printf(" %d", peek(1, top));

return 0;
}
