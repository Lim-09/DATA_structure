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
    Q-> rear = Q-> front = 0;
}

int is_empty(QueueType *Q)
{
    return (Q-> front  == Q -> rear);
}

int is_full(QueueType *Q)
{
    return (Q-> rear == (Q-> front -1) % MAX_SIZE); // rear의 다음 칸이 front 인 경우
}

void enqueue(QueueType *Q, element item)
{
    if(is_full(Q)) error("오류! 포화");
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    Q->data[Q->rear] = item;
}

element dequeue(QueueType *Q)
{
    if(is_empty(Q)) error("오류! 공백");
    Q->front = (Q->front + 1) % MAX_SIZE;
    return Q->data[Q->front];
}

void print_queue(QueueType *Q)
{
    if(!is_empty(Q))
    {
        int i = Q->front; // front를 기준으로 움직여야 순서가 맞음
        do
        {
            i = (i + 1) % MAX_SIZE;
            printf("%d | ", Q->data[i]);
            if(i == Q->rear) break;
        } while (i != Q->front);   
    }
    printf("\n");
}

//실행

int main()
{
    QueueType CQ;
    init_Queue(&CQ);
    for(int i =1; i < MAX_SIZE;i++)
    {
        enqueue(&CQ,i);
        print_queue(&CQ);
    }
    dequeue(&CQ);
    dequeue(&CQ);
    dequeue(&CQ);
    print_queue(&CQ);
    enqueue(&CQ,10);
    print_queue(&CQ);
}