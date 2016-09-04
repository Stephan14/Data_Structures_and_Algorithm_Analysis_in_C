#include<iostream>

using namespace std;

struct Node{
    int value;
    struct Node *next;
};

strcut Node *reverseList( strcut Node *head )
{
    strcut Node *reverseListHead = NULL;
    strcut Node *tempNode1 = head;
    strcut Node *tempNode2 = NULL;

    while( tempNode1 != NULL )
    {
        strcut Node *temp = tempNode1;
        //当到达尾节点时设置新的头节点
        if( tempNode1->next == NULL )
            reverseListHead = tempNode1;
        tempNode1 = tempNode1->next;
        temp->next = tempNode2;
        tempNode2 = temp;
    }

    return reverseListHead;
}
int main()
{


}
