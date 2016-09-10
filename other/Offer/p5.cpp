#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int value;
    struct Node *next;
};


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
        return;

    struct Node *toBeDeleted = NULL;
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

void printList( struct Node *list )
{
    while( list != NULL )
    {
        cout << list->value << "  " << endl;
        list = list->next;
    }
}
void printListReversinglyIteratively( struct Node * listHead )
{
    stack<struct Node *> nodes;

    struct Node *pNode = listHead;
    while( pNode != NULL )
    {
        nodes.push( pNode );
        pNode = pNode->next;
    }    

    while( !nodes.empty() )
    {
        pNode = nodes.top();
        cout << pNode->value;
        nodes.pop();
    }
}

void printListReversinglyRecursively( struct Node *listHead )
{
    if( listHead != NULL )
    {
        if( listHead->next != NULL )
        {
            printListReversinglyRecursively( listHead->next );
        }
        //将输出工作放在后面执行
        cout << listHead->value;
    }
}


int main()
{
    struct Node *head = NULL;
    addToTail( &head, 3 );
    addToTail( &head, 23 );
    addToTail( &head, 1 );
    addToTail( &head, 8 );

    printList( head );
    cout << "倒序输出" << endl;
    printListReversinglyIteratively( head );
    removeNode( &head, 3 );
    removeNode( &head, 23 );
    removeNode( &head, 1 );
    removeNode( &head, 8 );
    return 0;
}
