include<iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

void deleteNode( Node **head, Node *deletedNode )
{
    if( head == NULL || deletedNode == NULL )
        return;

    //要删除的节点不是尾节点
    if( deletedNode->next != NULL )
    {
        struct Node* tmp = deletedNode->next;

        deletedNode->value = deletedNode->value;
        deletedNode->next = deleteNode->next->next;
        
        delete tmp;
        tmp = NULL;    
    }
    //删除只有一个节点的链表
    else if( *head == deletedNode  )
    {
        *head = NULL;
        delete deletedNode;
        deletedNode = NULL;
    }
    //删除尾节点,需要从头节点开始遍历
    else
    {
        struct Node* first = *head;
        
        while( first->next != deletedNode )
            first = first->next;
        
        first->next = NULL;
        delete deletedNode;
        deletedNode = NULL;
    }
}



int main ()
{
    
    return 0;
}

