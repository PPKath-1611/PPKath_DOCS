#include<stdio.h>

typedef struct
{                                                                                         
    int rear;                                      
    int front;
    int data[50];                                                                                        
}queue;

void Enqueue(queue *q, int n)
{
    q->data[q->rear++] = n;
}

int Dequeue(queue *q)
{
    return(q->data[q->front++]);
} 

int main()
{
    queue q = {.rear = 0, .front = 0};
    int i,n,k,res=0;
    printf("Enter number of People:\n");
    scanf("%d", &n);
    printf("How many people to skip:\n");
    scanf("%d", &k);
    for(i=2;i<=n;i++)
    {                                   /* To find targeted Points as per value of k */
        res = (res + k) % i;
    }
    Enqueue(&q, res + 1);
    printf("Survivor is %d", q.data[q.front]);   /* To get the Survivor which is at front */
    return 0;
}
