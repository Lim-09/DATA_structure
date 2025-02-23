#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef int element;
typedef struct 
{
    element data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) 
{    
    s-> top = -1;
}

int is_empty(StackType *s)
{
    return (s-> top == -1);
}

int is_full(StackType *s)
{
    return (s-> top ==(MAX_SIZE-1)); 
}

void push(StackType *s, element item)
{
    if(is_full(s))
    {
        fprintf(stderr,"스택 포화!");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr,"스택 공백!");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr,"스택 공백!");
        exit(1);
    }
    else return s->data[s->top];
}

int main()
{
    char brackets[] = "(((((()";
    char c;
    int counter = 0, length = strlen(brackets);
    StackType s;
    init_stack(&s);

    printf("수식: %s\n",brackets);
    printf("괄호 수: ");

    for(int i =0; i < length; i++)
    {
        c = brackets[i];
        switch(c)
        {
            case '(': //왼쪽 괄호이면 괄호번호 출력 후 번호를 스택에 저장
                printf(" %d ",++counter); 
                push(&s,counter);
            break;
            
            case ')': //오른쪽 괄호이면 스택에서 최근에 저장된 괄호번호를 꺼내서 출력
                printf(" %d ",pop(&s));
            break;
        }
    }
    printf("\n");
}