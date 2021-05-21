#include<ctype.h>
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

void infixToPostfix(char *infix, char *postfix)
{struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->size=10;
s->top=-1;
s->arr= (char*)malloc(s->size*sizeof(char));


    int in = 0, post = 0;

    char ch, scan;

    push(s,'(');
    strcat(infix, ")");

    ch = infix[in];

    while(ch != '\0')
    {
        if(ch == '(')
        {
            push(s,ch);
        }

        else if(isdigit(ch) || isalpha(ch))
        {
            postfix[post] = ch;
            post++;
        }

        else if(isOperator(ch) == 1)
        {
            scan = pop(s);
            while(isOperator(scan) == 1 && precedence(scan) > precedence(ch))
            {
                postfix[post] = scan;
                post++;
                scan = pop(s);
            }

            push(s,scan);
            push(s,ch);
        }

        else if(ch == ')')
        {
            scan = pop(s);

            while(scan != '(')
            {
                postfix[post] = scan;
                post++;
                scan = pop(s);
            }
        }

        in++;
        ch = infix[in];
    }
    postfix[post] = '\0';

}

int main()
{

    char *infix = (char *)calloc(100, sizeof(char));
    char *postfix = (char *)calloc(100, sizeof(char));


    printf("Enter INFIX expression: \n");
    gets(infix);

    infixToPostfix(infix, postfix);

    puts(postfix);
    return 0;
}
