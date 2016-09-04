#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};


//二叉树镜像
void mirrorRecursively( struct Node * root )
{
    if( root == NULL || 
        ( root->left == NULL && root->right == NULL ) )
        return ;

    struct Node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if( root->left )
        mirrorRecursively( root->left );


    if( root->right )
        mirrorRecursively( root->right );

}

int main()
{
    return 0;
}
