#include<iostream>

using namespace std;

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reorderOddEven( int array[], int length )
{
    if( array == NULL || length < 0 )
        return;
    
    int* preIndex = array;
    int* lastIndex = array + length - 1;
    
    cout << "1.1"<<endl;
    //注意判断preindex与lastindex之间的关系
    while( preIndex < lastIndex )
    {
        while(  *preIndex & 0x1  != 0  && ( preIndex < lastIndex ) ) 
            preIndex++;
        while( ( *lastIndex & 0x1 )  == 0  && ( lastIndex > preIndex ) ) 
            lastIndex--;
        if( preIndex < lastIndex )
            swap( preIndex, lastIndex );               
    }
}

int main()
{
    int temp[] = { 34, 21, 7, 44, 78, 5, 9, 1 };
    cout << "0" << endl;
    reorderOddEven( temp, 8 );
    cout << "2" << endl;
    for( int i = 0; i < 8; i++ )
        cout<< temp[ i ] <<"  ";
    return 0;
}
