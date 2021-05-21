#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int size=0;

int peek(struct stack* s, int i){
        int temp = s->top-i+1;
    if(s->top - i +1 < 0 ){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else {
        return s->arr[temp];
    }
}


int isFull(struct stack* ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
//        printf("The stack is not full");
        return 0;
    }
}


int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
  //      printf("the stack is empty");
        return 1;
    }
    else{
    //    printf("The stack is not empty");
        return 0;
    }
}

void push(struct stack* ptr, int x){
    if(isFull(ptr)){
        printf("Stack is overflow(FULL) ");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top]=x;
    }
    size++;
}

int pop(struct stack* ptr){
    if (isEmpty(ptr)){
        printf("is empty cant remove element ");
        return -1;
    }
    else{
            int x=ptr->arr[ptr->top];
            ptr->top--;
            return x;
            size--;
    }

}

stackOut(struct stack* ptr){
if(ptr->top==-1){
    printf("The stack is empty, nothing to print\n");


    }
else
        for(int i=(ptr->top); i>-1;i--){
            printf("%d\n",ptr->arr[i]);
        }
    }


int main(){
    struct stack *s=(int*)malloc(sizeof(struct stack));
    s->top =-1;
    s->size=10;
    s->arr=(int*)malloc(sizeof(int)*s->size);



    push(s,1);
    push(s,2);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,0);
    pop(s);
stackOut(s);

printf("The value at the index is %d is %d", 2, peek(s,2));
return 0;
}
