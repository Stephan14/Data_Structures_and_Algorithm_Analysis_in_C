#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};


bool hasSubTree( struct Node *tree1, struct Node *tree2 )
{
    bool result = false;
    //边界条件:判断指针是否为空
    if( tree1 != NULL && tree2 != NULL )
    {
        if( tree1->value == tree2->value )
            result = doesTree1HasTree2( tree2, tree1 );
        
        if( !result )
           result = hasSubTree( tree1->left, tree2 );

        if( !result )
           result = hasSubTree( tree1->right, tree2 ); 
    }
    
    return result;    
}

bool doesTree1HasTree2( struct Node* tree1, struct Node* tree2 )
{
    if( tree2 == NULL )
         return true;
    
    if( tree1 == NULL )
        return false;
    
    if( tree2->value != tree1->value )
        return false;

    return doesTree1HasTree2( tree1->left, tree2->left ) 
        && doesTree1HasTree2( tree1->right, tree2->right );
}

int main()
{

    return 0;
}
