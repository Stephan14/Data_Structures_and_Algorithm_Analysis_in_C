#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;

};


struct Node *consturctCore( int *startPreorder, int *endPreorder, int *startInorder, int *endInorder );

struct Node *consturct( int *preorder, int *inorder, int length )
{
    if( preorder == NULL || inorder == NULL || length < 0 )
        return NULL;

    return consturctCore( preorder, preorder + length - 1, inorder, inorder + length - 1 );
}


struct Node *consturctCore( int *startPreorder, int *endPreorder, int *startInorder, int *endInorder )
{
    int rootValue = startPreorder[ 0 ];
    struct Node *root = new Node();
    root->value = rootValue;
    root->right = root->left = NULL;

    if( startPreorder == endPreorder )
    {
        if( startInorder == endInorder && *startPreorder == *startInorder )
            return root;
        else
            return NULL;
    }
    /*在中序遍历中找到根节点的值*/
    int *rootInorder = startInorder;
    while( *rootInorder != rootValue && rootInorder <= endInorder )
        rootInorder++;
    if( rootInorder == endInorder && rootValue != *rootInorder  )
        return NULL;

    int leftLength = rootInorder - startInorder;
    int * leftPreorderEnd = startPreorder + leftLength;
      
    if( leftLength > 0 )
        root->left =  consturctCore( startInorder + 1, leftPreorderEnd, startInorder, rootInorder - 1 );
    if( leftLength < endInorder - startInorder )
        root->right = consturctCore( leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder );

    return root;
}

void printAfterOrder( struct Node *root )
{
    if( root == NULL )
        return; 
    if( root->left != NULL )
        printAfterOrder( root->left );
    if( root->right != NULL )
        printAfterOrder( root->right );
    cout << root->value << "  " << endl;
} 


int main()
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8  };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    struct Node * root = consturct( pre, in, 8 );
    printAfterOrder( root );    
    return 0;
}
