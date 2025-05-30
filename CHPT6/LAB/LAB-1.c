#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    char str[20];
}element;

typedef struct Listnode
{
    element data;
    struct Listnode *link;
} Listnode;

void error(char *msg)
{
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

Listnode* insert_f(Listnode *head, element val) // 앞에 노드 추가
{
    Listnode *node = (Listnode *)malloc(sizeof(Listnode));
    node -> data = val;
    node -> link = head;
    head = node; 
    return head; // 포인터 매개 변수의 주소를 복사해서 값에 접근은 안했기 때문에 원본의 변화는 없음.
}

Listnode* insert(Listnode *head, Listnode *pre, element val) // 중간 삽입
{
    Listnode *node = (Listnode *)malloc(sizeof(Listnode));
    node -> data = val;
    node -> link = pre -> link;
    pre -> link = node; // 포인터 매개변수의 주소를 복사 후 그걸 접근했기 때문에 원본 값도 변함. 헤드에 업데이트 안해도 상관X
    return head;
}

Listnode* delete_f(Listnode *head) // 앞을 삭제
{
    if(head == NULL) return NULL;
    Listnode *rmv = head;
    head = rmv -> link;
    free(rmv); // 주소를 복사 후 주소에 할당된 공간을 삭제하기에 원본도 삭제 된다. 그래서 위에서 할당된 새주소를 넣어줘야됨.
    return head;
}

Listnode* delete(Listnode *head, Listnode *pre) // 중간 삭제
{
    Listnode *rmv = pre -> link;
    pre -> link = rmv -> link; // 포인터 매개변수의 주소를 복사 후 그걸 접근했기 때문에 원본 값도 변함. 헤드에 업데이트 안해도 상관X
    free(rmv);
    return head;
}

void print_listnode(Listnode *head)
{
    Listnode *tg = head;
    while(tg != NULL)
    {
        printf("%s -> ",tg -> data.str); // 문자 출력으로 변경,  구조체의 요소(문자열) 출력
        tg = tg -> link;
    }
    printf("NULL \n");
}

int main()
{
    Listnode *head = NULL;
    element data;
    strcpy(data.str,"hello"); //문자열 넣기
    head = insert_f(head,data);
    print_listnode(head);

    strcpy(data.str,"world"); //문자열 넣기
    head = insert_f(head,data);
    print_listnode(head);

    strcpy(data.str,"test"); //문자열 넣기
    head = insert_f(head,data);
    print_listnode(head);
}