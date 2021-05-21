#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* s){
    return s->arr[s->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char x){
    if(isFull(ptr)){
        printf("Stack full can't push\n", x);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = x;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack empty can't pop\n");
        return -1;
    }
    else{
        char x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}

int precedence(char ch){
        if(ch=='^')
            return 3;
    else if(ch == '*' || ch=='/')
        return 2;
    else if(ch == '+' || ch=='-')
        return 1;
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/'||ch=='^')
        return 1;
    else
        return 0;
}


char* infixToPostfix(char* infix){//**IMPORTANT Must See**[char* -->To pass the entire String]
struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->size=10;
s->top=-1;
s->arr= (char*)malloc(s->size*sizeof(char));
//structure



char* postfix =(char*)malloc((strlen(infix)+1) * sizeof(char));  //POstfix ...Dynamic memory


int i=0;  //to calculate the no.of digit of infix
int j=0;  // for postfix


while(infix[i]!='\0')
{
    if(!isOperator(infix[i])){   //transfer
        postfix[j]=infix[i];
        j++;
        i++;
    }
    else {
        if(precedence(infix[i])> precedence(stackTop(s))){
                push(s,infix[i]);
                i++;
           }
           else{
            postfix[j]=pop(s);
            j++;
        }
    }
}
while(!isEmpty(s))
{
    postfix[j]=pop(s);
    j++;
}
postfix[j]='\0';


    return postfix;
}



int main()
{
    char *infix = "a+b-c";

    printf("POSTFIX of Infix is %s", infixToPostfix(infix));

    return 0;
}
