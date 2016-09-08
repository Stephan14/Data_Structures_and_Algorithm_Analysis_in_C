#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

//第一个参数必须是指针的指针，因为当向一个空的链表中
//插入一个节点时，这个节点就是头结点，必须改变头结点
void addToTail( struct Node ** listHead, int value )
{
    struct Node *tempNode = new Node();
    tempNode->value = value;
    tempNode->next  = NULL;
    
    //插入的节点为头结点
    if( *listHead == NULL  )
        *listHead = tempNode;
    else
    {
        struct Node *tempHead = *listHead;
        while( tempHead->next != NULL )
            tempHead = tempHead->next;

        tempHead->next = tempNode;
    }

}

void removeNode( struct Node **listHead, int value )
{
    if( listHead == NULL || *listHead == NULL )
        return NULL;

    struct Node toBeDeleted = NULL;
    //删除的节点为头结点
    if( ( *listHead )->value == value )
    {
        toBeDeleted = *listHead;
        *listHead = ( *listHead )->next;        
    }    
    else
    {
        struct Node * tempHead = *listHead;
        //直接从第二个节点开始判断   
        while( tempHead->next != NULL && tempHead->next->value != value )
            tempHead = tempHead->next;

        if( tempHead->next != NULL && tempHead->next->value == value )
        {
            toBeDeleted = tempHead->next;
            tempHead->next = tempHead->next->next;            
        }
               
        if( toBeDeleted != NULL )
        {
            delete toBeDeleted;
            toBeDeleted = NULL;
        }

    }
}
int main()
{

    return 0;
}
