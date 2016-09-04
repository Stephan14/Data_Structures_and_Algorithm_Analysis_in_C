#include<iostream>

using namespace std;

struct Node{
    int vlaue;
    struct Node *next;
};

Node *findKthToTail( struct Node *head, unsigned int k )
{
    if( head == NULL || k == 0 )
        return NULL;

    struct Node *preNode1 = head;
    struct Node *preNode2 = NULL;

    for( unsigned int index = 0; index < k - 1; index++ )
    {
        if( preNode1->next != NULL  )
            preNode1 = preNode1-next;
        else
            return NULL;
    }

    preNode2 = head;
    while( preNode1->next != NULL )
    {
        preNode1 = preNode1->next;
        preNode2 = preNode2->next;
    }

    return preNode2;
}

int main()
{

    return 0;
}
