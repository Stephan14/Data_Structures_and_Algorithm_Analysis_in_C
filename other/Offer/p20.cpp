#include<iostream>

using namespace std;

void printMatrixInCircle( int numbers[][4], int columns, int rows, int start )
{
    int endY = columns - start - 1;
    int endX = rows - start - 1;
    
    cout << **numbers;
    //从左到右打印一行
    for( int i = start; i <= endY; i++ )
    {
//        cout<< "start=" << start << "i=" << i ; 
        cout << numbers[ start ][ i ] << "  ";
    }
    //从上到下打印一行
    if( start < endY )
    {
        for( int i = start + 1; i <= endX; ++i )
        {   
//            cout<< "start=" << start << "i=" << i ; 
            cout << *( *( numbers + i ) + endY ) << "  ";
        }
    }
    //从左到右打印一行
    if( start < endX && start < endY )
    {
        for( int i = endY - 1; i >= start; i-- )
        {
//            cout<< "start=" << start << "i=" << i ;
            cout << *( *( numbers + endX ) + i ) << "  ";
        }
    }
    //从上到下打印一行
    if( start < endX & start < endY - 1 )
    {
        for( int i = endX - 1; i >= start; i-- )
        {
//            cout<< "start=" << start << "i=" << i;
            cout << * ( *( numbers + i ) + start ) << "  ";
        }
    }
} 

void printMatrixClockwisely( int numbers[][4], int columns, int rows )
{
    if( numbers == NULL || columns < 0 || rows < 0 )
        return;

    int start = 0;

    while( columns > start * 2 && rows > start * 2 )
    {      
        printMatrixInCircle( numbers, columns, rows, start ); 
        ++start;
    } 
}

int main()
{

    int m[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    printMatrixClockwisely( m, 4, 5 );
    
    return 0;
}
