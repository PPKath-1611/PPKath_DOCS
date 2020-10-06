#include<stdio.h>
#include<math.h>

typedef struct{
    int top;
    int a[100];
}stack;

void push(stack *s, int k)
{
    s->a[s->top] = k;
    s->top++;
}
int pop(stack *s)
{
    s->top--;
    return s->a[s->top];
}
int main()
{
    int n,x=0,p=0,t;
    stack s;
    s.top = 0;
    printf("Enter the binary number\n");
    scanf("%d", &n);
    t = n;
    while (t != 0)
    {
        x = x + (t % 10) * pow(2,p);
        t = t /10;
        p++;
    }
    push(&s, x);
    printf("Decimal form for %d number is: ", n);
    while (s.top != 0)
    {
        printf("%d", pop(&s));
    }
    
    return 0;
}
