/*打印1到最大的n位数*/
#include<iostream>
#include<cstring>

using namespace std;

bool increament( char* number )
{
    //记录是否溢出
    bool isOverflow = false;
    //记录进位的多少
    int nTakeOver = 0;
    int length = strlen( number );

    for( int i = length - 1; i >= 0; i-- )
    {
        //进位操作
        int sum = number[ i ] - '0' + nTakeOver;
        //只有最后以为才能加1
        if( i == length - 1 )
            ++sum;
        
        if( sum >= 10 )
        {
            //判断是否溢出
            if( i = 0 )
                isOverflow = 1;
            else
            {  
                sum -= 10;
                nTakeOver = 1;
                number[ i ] = '0' + sum;
            }
        }
        else
        {
            number[ i ] = '0' + sum;
            break;
        }    
    }

    return isOverflow; 
}


void printNumber( char* number )
{
    int index = 0;
    bool isBeginning0 = true;

    while( number[ index ] != '\0' )
    {
        if( number[ index ] != '0' ||  !isBeginning0 )
        {
            isBeginning0 = false;
            cout<< number[ index ];
        }
        index++;
    }
    cout<<"  ";
}

void print1ToMaxOfNDight( int n )
{
    //判断边界条件
    if( n <= 0 )
        return;
    //设置数字的各个位为0    
    char* number = new char[ n + 1 ];
    memset( number, '0', n );
    number[ n ] = '\0';

    while( !increament( number ) )
    {
        printNumber( number );
    }

    delete[] number;
}

int main()
{
    print1ToMaxOfNDight( 1 );
    return 0;
}
