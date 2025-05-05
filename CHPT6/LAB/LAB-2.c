#include <stdio.h>
#include <stdlib.h>

typedef int element;

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
        printf("%d -> ",tg -> data);
        tg = tg -> link;
    }
    printf("NULL \n");
}

Listnode *searching(Listnode *head, int fval)
{
    Listnode *fnode = head;
    int count =0;
    while(fnode != NULL)
    {
        count ++;
        if(fnode -> data == fval)
        {
            printf("%d번쨰 노드에서 %d를 찾았습니다.\n",count,fval);
            return fnode;
        }
        fnode = fnode -> link;
    }
    printf("%d를 찾지 못했습니다.\n",fval);
    return NULL;
}

int main()
{
    Listnode *head;
    for(int n=10; n != 0; n--)
        head = insert_f(head,n);
    print_listnode(head);

    searching(head,4);
    searching(head,100);
}
