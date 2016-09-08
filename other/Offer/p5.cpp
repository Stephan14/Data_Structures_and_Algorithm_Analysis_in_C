#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

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
        pNode = nodes.top;
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
    return 0;
}
