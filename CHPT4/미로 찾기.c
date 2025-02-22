#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define MAZE_SIZE 6

#define MAX_SIZE 100

typedef struct // 2차원 미로 임으로 행, 열 좌표 값으로 교체
{
    short row;
    short col;
}element;

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

// 여기서 부터 미로 코드

element here = {1,0}, start = {1,0}; // 현재위치와 시작 위치 할당(초기화)

    char maze[MAZE_SIZE][MAZE_SIZE]=
    {
        {'1','1','1','1','1','1'},
        {'e','0','0','0','1','1'},
        {'1','1','0','1','1','1'},
        {'1','1','0','1','1','1'},
        {'1','0','0','0','0','x'},
        {'1','1','1','1','1','1'}
    };

void push_loc(StackType *s, int r, int c)
{
    if(r<0 || c<0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.')
    {
        element tmp;
        tmp.row = r;
        tmp.col = c;
        push(s,tmp);
    }
}

void maze_print()
{
    printf("\n");
    for(int r=0; r< MAZE_SIZE; r++)
    {   for(int c=0; c< MAZE_SIZE; c++)
            printf("%c",maze[r][c]);
        printf("\n");
    }
}

int main()
{
    int r, c;
    StackType s;

    init_stack(&s);
    here = start;
    while(maze[here.row][here.col]!= 'x')
    {
        r = here.row;
        c = here.col;
        maze[r][c] = '.';
        maze_print();
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c-1);
        push_loc(&s, r, c+1);
        
        if(is_empty(&s)) //갈 수 있는 경로가 스택에 없는 경우
        {
            printf("실패");
            return 0;
        }
        else
            here = pop(&s);
    }
    printf("성공");
    return 0;
}