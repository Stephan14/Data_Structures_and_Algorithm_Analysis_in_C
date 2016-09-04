#include<iostream>

using namespace std;

class CMyString
{
    public:
        CMyString( char *pData = NULL );
        CMyString( const CMyString& str );
        ~CMyString();
    private:
        char *m_pData;
};

//返回值使用引用,允许连续赋值
//参数使用常量引用避免调用构造函数

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

CMyString& CMyString::operator=( const CMyString &str )
{
    if( this != &str )
    {
        CMyString strTemp( str );
        
        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = str.m_pData;
        m_pData = pTemp;     
    } 
    //返回类型为引用值
    return *this;
}



int main()
{
    return 0;
}
