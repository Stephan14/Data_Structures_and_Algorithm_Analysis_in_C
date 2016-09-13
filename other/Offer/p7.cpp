#include<iostream>
#include<stack>

using namespace std;

template< typename T >

class queue
{
    public:
        queue(){}
        ~queue(){}

        void appendTail( const T& node );
        T deleteHead();

    private:
        stack< T > stack1;
        stack< T > stack2;        
};

template< typename T >

void queue::appendTail( const T& node )
{
    stack1.push( node );
}

template< typename T >

T queue::deleteHead()
{
    
}

int main()
{
    return 0;
}
