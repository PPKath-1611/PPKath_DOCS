#include<stdio.h>

typedef struct
{
   int top;
   int a[50];
}stack;

void push(stack *s, int n)
{
    s->a[s->top++] = n;
}

int pop(stack *s)
{
    return(s->a[s->top--]);
}

int main()
{
    stack s = {.top = 0};
    int n,x,i,e=1;
    printf("Enter the base:\n");
    scanf("%d", &x);
    printf("Enter the power\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        push(&s, i);
    while(s.top != -1)
    {
        x = x * s.a[s.top];
        pop(&s);
    }
    printf("%d", x);   
    return 0;
}
