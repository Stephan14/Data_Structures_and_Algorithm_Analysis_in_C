#include<iostream>
#include<stack>

using namespace std;

template< typename T >
class Myqueue
{
    public:
        Myqueue(){}
        ~Myqueue(){}

        void appendTail( const T& node );
        T deleteHead();

    private:
        stack< T > stack1;
        stack< T > stack2;        
};

template< typename T >
void Myqueue<T>::appendTail( const T& node )
{
    stack1.push( node );
}

template< typename T >
T Myqueue<T>::deleteHead()
{
    if( stack2.empty() )
    {
        while( !stack1.empty() )
        {
            stack2.push( stack1.top() );
            stack1.pop();
        }    
    }    

    if( stack2.empty() )
        cout << "队列中没有元素" << endl;
    T node = stack2.top();
    stack2.pop();

    return node;
}

int main()
{
    Myqueue< int > q;
    q.appendTail( 23  );
    q.appendTail( 45  );
    q.appendTail( 56  );

    cout << q.deleteHead() << endl;

    q.appendTail( 67  );
    cout << q.deleteHead() << endl;
    q.appendTail( 99 );
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    return 0;
}
