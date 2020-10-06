#include<stdio.h>

typedef struct{
    int top;
    char a[100];
}stack;

void push(stack *s, char x)
{
    s->top++;
    s->a[s->top] = x;
}

char pop(stack *s)
{
    return s->a[s->top--];
}

int main()
{
    int i;
    stack s;
    char x[50];
    s.top = -1;
    printf("Enter the sequence:\n");
    gets(x);
    for(i=0;x[i] != '\0';i++)
    {
        if(x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            push(&s, x[i]);
        }
        else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            pop(&s);
        }
        else if(x[i] == '(' && s.a[s.top] == ')' || x[i] == '[' && s.a[s.top] == ']' || x[i] == '{' && s.a[s.top] == '}')
        {
            pop(&s);
        }
    }
    if(s.top == -1)
        printf("\nExpression is BALANCED!\n");
    else
    {
        printf("Expression is UNBALANCED!\n");
    }
    return 0;
}
