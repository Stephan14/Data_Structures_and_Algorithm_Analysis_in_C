/*赋值运算符函数*/

#include<iostream>
#include<cstring>

using namespace std;

class CMyString
{
    public:
        CMyString( char *pData = NULL );
        CMyString( const CMyString& str );
        CMyString& operator=( const CMyString& str );

        void print();
        ~CMyString();
    private:
        char *m_pData;
};

//构造函数
CMyString::CMyString( char *pData ):m_pData( NULL )
{
    if( pData != NULL  )
    {
        m_pData = new char[ strlen( pData ) + 1 ];
        strcpy( m_pData, pData );       
    }
}

//析构函数
CMyString::~CMyString()
{
    if( m_pData != NULL )
    {
        delete[] m_pData;
        m_pData = NULL;
    }
}

//拷贝构造函数
CMyString::CMyString( const CMyString& str ):m_pData( NULL )
{
    if( str.m_pData != NULL  )
    {
        m_pData = new char[ strlen( str.m_pData ) + 1 ];
        strcpy( m_pData, str.m_pData );
    }
}

void CMyString::print()
{
    cout << m_pData << endl;
}

//返回值使用引用,允许连续赋值
//参数使用常量引用避免调用构造函数
/*
CMyString& CMyString::operator=( const CMyString &str )
{
    if( &str == this )
        return *this;
           
    delete[] m_pData;
    m_pData = NULL;

    m_pData = new char[ strlen(str.m_pData) + 1 ];    
    strcpy( m_pData, str.m_pData );

    return *this;    
}
*/

CMyString& CMyString::operator=( const CMyString &str )
{
    //判断对象是否相同
    if( this != &str )
    {
        CMyString strTemp( str );
        
        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;     
    } 
    //返回类型为引用值
    return *this;
}



int main()
{
    CMyString str1( (char *)"abc" );
    CMyString str2( (char *)"def" );
    cout <<"赋值之前：" << endl;
    str1.print();
    str2.print();
    str1 = str2;
    cout << "赋值之后:" << endl;
    str1.print();
    str2.print();
    return 0;
}
