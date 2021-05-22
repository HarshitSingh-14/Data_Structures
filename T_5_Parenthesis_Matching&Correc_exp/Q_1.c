#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr,char x){
    if(isFull(ptr)){
        printf("stack full can't push ");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=x;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack Null, can't pop up\n");
        return -1;
    }
    else{
        char x= ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}

char stackTop(struct stack* ptr){
    return ptr->arr[ptr->top];
}

int match(char a, char b){
    if(a=='{'&&b=='}'){
        return 1;
    }
    if(a=='('&&b==')'){
        return 1;
    }
    if(a=='['&&b==']'){
        return 1;
    }
return 0;
}


int parenthesisMatch(char* check){
    struct stack *s;
    s->size=20;
    s->top=-1;
    s->arr=(char*)malloc(s->size*sizeof(char));
    char popc;


    for(int i =0;check[i]!='\0';i++)
    {
        if(check[i]=='('||check[i]=='{'||check[i]=='['){
            push(s,check[i]);
           }



        else if(check[i]==')'||check[i]=='}'||check[i]==']'){

            if(isEmpty(s)){
                return 0;
            }
            popc=pop(s);

            if(match(popc,check[i])){
                return 1;
            }
        }
    }




    if (isEmpty(s)){
        return 1;
    }
    else {
        return 0;
    }
}



int main()
{

    char *c = (char *)malloc (20*sizeof(char));
    printf("Write the expression :");
    gets(c);
    printf("\n\n");   // Why not working with single


        if(parenthesisMatch(c)){
        printf("The parenthesis is correct\n");
    }
    else{
        printf("is not balanced\n");
    }

    return 0;
}
