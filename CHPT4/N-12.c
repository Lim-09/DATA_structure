#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100


typedef char element;
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

// 여기서 부터 코드 
// 11번 문자열 압축

void strlow(char str[]) // 소문자 변환
{
    int i = 0;
    while(str[i])
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]= str[i]+32;
        }
        i++;
    }
}

void push_str(StackType *s, char str[]) // 스택에 문자열 거꾸로 넣기
{
   for(int i = strlen(str)-1;i >= 0; i--)
   {
        push(s,str[i]);
   }
}

int main()
{
char str[] = "aaaAbBb";
int count = 1; // 글자 수 세기
char ne, ce; // 다음 문자 현재 문자
StackType s;

init_stack(&s);
strlow(str);
push_str(&s,str);
ce= pop(&s); // 첫글자 꺼내서지정

printf("압축된 문자열: ");

while(is_empty(&s)==0)
{
    ne = pop(&s);
    if(ce != ne) // 다음 문자가 현재 문자랑 다름
    {
        printf("%d%c",count,ce); // 현재 문자 개수 출력
        count = 1; // 개수 초기화
    }
    else // 같은 문자의 경우
    {
        count++;
    }
    ce= ne;
    if(is_empty(&s)) printf("%d%c",count,ce);// 스택이 비었다면 꺼내서 저장한 나머지 문자도 출력
}
printf("\n");
}