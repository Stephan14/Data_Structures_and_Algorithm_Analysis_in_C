#include<iostream>

using namespace std;

template <typename T>

void StackWithMin<T>::push( const T& value )
{
    m_date.push( value );

    if( m_min.size() == 0 || value < m_min.top() )
        m_min.push( value );
    else
        m_min.push( m_min.top() );    
}


template <typename T>

void StackWithMin::pop()
{   
    //判断栈中是否有数据    
    if( m_min.size() > 0 && m_date.size() > 0 )
    {
        m_date.pop();
        m_min.pop();
    }
}

template <typename T>

void StackWithMin::min()
{
    if( m_date.size() > 0 && m_min.size() > 0 )
        return m_min.top();
}
int main()
{


}
