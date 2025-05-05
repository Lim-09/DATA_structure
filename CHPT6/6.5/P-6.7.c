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

Listnode* insert_f(Listnode *head, int val) // 앞에 노드 추가
{
    Listnode *node = (Listnode *)malloc(sizeof(Listnode));
    node -> data = val;
    node -> link = head;
    head = node; 
    return head; // 포인터 매개 변수의 주소를 복사해서 값에 접근은 안했기 때문에 원본의 변화는 없음.
}

Listnode* insert(Listnode *head, Listnode *pre, int val) // 중간 삽입
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

int main()
{
    Listnode *L1 = NULL;
    L1 = insert_f(L1,1);
    print_listnode(L1);
    L1 = insert_f(L1,2);
    print_listnode(L1);
    Listnode *pre = L1; // 앞에 3을 넣기 전의 헤드 노드(2)를 선행으로 지정 
    L1 = insert_f(L1,3);
    print_listnode(L1);
    insert(L1,pre,4); // 노드의 주소를 복사 후 접근 헤서 직접 변경, 헤드는 변경 안시키므로 헤드에 반환 값 넣을 필요 X
    print_listnode(L1);
    L1 = delete_f(L1); // 기존 헤드(3)의 공간을 삭제 해버리기에 새주소를 다시 넣어줘야됨
    print_listnode(L1);
    delete(L1,pre); // 노드의 주소를 복사 후 접근 헤서 직접 변경, 헤드의 주소는 변경 안시키므로 헤드에 반환 값 넣을 필요 X
    print_listnode(L1);

}