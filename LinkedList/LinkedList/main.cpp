
#include <iostream>
using namespace std;

#define MAX_NODE 100

struct node {
    int data;
    struct node * link;
};
typedef struct node list_node;
typedef list_node * list_ptr;

list_ptr create(int n) {
    list_ptr first=NULL, temp=NULL;
    int i;
    for(i=0; i < n; i++)
    {
        temp = (list_ptr)malloc(sizeof(list_node));
        temp->data=(i+1); /* 리스트의 값 */
        temp->link=first; /* 새로운 노드를 리스트의 맨 앞에 삽입한다. */
        first = temp;
    }
    return first;
}

void print_list(list_ptr ptr) {
    printf("The list contains: ");
    for( ; ptr; ptr = ptr->link)
        printf("%4d", ptr->data);
    printf("\n");
}

void insertlast(list_ptr ptr)
{
    list_ptr last=NULL, temp;
    last=ptr;
    for(  ;last->link != NULL; last=last->link)
    { }
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=7; temp->link=NULL;
    last->link=temp;
}

list_ptr insertfirst(list_ptr ptr)
{
    list_ptr temp, first;
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=0; temp->link=ptr;
    first=temp;
    return first;
}

void insertfirst2(list_ptr *ptr)
{
    list_ptr temp, first;
    temp=(list_ptr)malloc(sizeof(list_node));
    temp->data=-1; temp->link=*ptr;
    *ptr=temp;
}

int main()
{
    list_ptr ptr = NULL;
    ptr = create(6); /* 6개의 노드를 가진 연결리스트를 만든다 */
    print_list(ptr);
    insertlast(ptr); print_list(ptr);
    ptr=insertfirst(ptr);print_list(ptr);
    insertfirst2(&ptr);print_list(ptr);
}
