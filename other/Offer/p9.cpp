/*斐波那契数列*/
#include<iostream>

using namespace std;
//利用long long类型解决大数字问题

long long Fibonacci( unsigned int n )
{
    int num[ 2 ] = { 0, 1 };
    if( n < 2 )
        return num[ n ];

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    
    //利用循环解决·
    for( unsigned int i = 2; i <= n; i++ )
    {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;    
    }
    
    return fibN;
}


int main()
{
    cout << Fibonacci( 4 );    
    return 0;
}
