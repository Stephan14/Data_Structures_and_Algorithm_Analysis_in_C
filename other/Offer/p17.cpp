#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node* next;
};


struct Node *merge( struct Node *head1, struct Node *head2 )
{
    struct Node *mergeHead = NULL;

    if( head1 == NULL )
        return head2;
    else if( head2 == NULL )
        return head1;


    if( head1->value < head2->value )
    {
        mergeHead = head1;
        mergeHead->next = merge( head1->next, head2 );    
    }
    else
    {
        mergeHead = head2;
        mergeHead->next = merge( head2, head1->next );
    }
    
    return mergeHead;
    
}
int main()
{
    
    return 0;
}
