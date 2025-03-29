#include<stdio.h> 
#include<stdlib.h>

#define MAX_SIZE 10

typedef int element;
typedef struct 
{
    element data[MAX_SIZE];
    int front;
    int rear;
} QueueType;

void error(char * message)
{
    fprintf(stderr,"%s",message);
    exit(1);
}

void init_Queue(QueueType *Q) 
{    
    Q-> rear = Q-> front = -1;
}

int is_empty(QueueType *Q)
{
    return (Q-> front  == Q -> rear);
}

int is_full(QueueType *Q)
{
    return (Q-> rear ==(MAX_SIZE-1)); 
}

void enqueue(QueueType *Q, element item)
{
    if(is_full(Q)) error("오류! 포화");
    Q->data[++(Q->rear)] = item;
}

element dequeue(QueueType *Q)
{
    if(is_empty(Q)) error("오류! 공백");
    return Q->data[++(Q->front)];
}

void print_queue(QueueType *Q)
{
    for(int i=0; i < MAX_SIZE; i ++)
    {
        if(i<=Q-> front|| i > Q-> rear) printf("  | ");

        else printf("%d | ",Q->data[i]);
    }
    printf("\n");
}

//실햄

int main()
{
    QueueType queue;
    init_Queue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    print_queue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    print_queue(&queue);


}
