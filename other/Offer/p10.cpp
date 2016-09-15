/*二进制中1的位数*/
#include<iostream>

using namespace std;

int NumberOf1( int num )
{
    int counter = 0;
    
    while( num  )
    {
        counter++;
        num = num & ( num - 1 );    
    }

    return counter;    
}

int main()
{
    cout << NumberOf1( 5  );
    return 0;
}
