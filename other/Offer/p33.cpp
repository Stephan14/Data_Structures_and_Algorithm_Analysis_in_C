#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAX 101
#define MAX_NUM 10

char str_combine1[ 2*MAX_NUM ],str_combine2[ 2*MAX_NUM ];

int compare( const void* str1, const void* str2 )
{
    strcpy( str_combine1, *( const char ** )str1 );
    strcat( str_combine1, *( const char ** )str2 );

    strcpy( str_combine2, *( const char ** )str2 ); 
    strcat( str_combine2, *( const char ** )str1 );

    return strcmp( str_combine1, str_combine2 );   
}

void printMinNumber( int *numbers, int length )
{
    if( numbers == NULL || length < 0 )
        return;

    char *strNumber[ MAX ];  
    for( int index = 0; index < length; index++ )
    {
        strNumber[ index ] = new char[ MAX_NUM ];
        sprintf( strNumber[ index ], "%d", numbers[ index ] );
    }

    qsort( strNumber, length, sizeof( char * ), compare );

    for( int index = 0; index < length; index++ )
        cout << strNumber[ index ];
    cout << endl;

    for( int index = 0; index < length; index++ )
        delete[] strNumber[ index ];
    
}
int main()
{
    int n, numbers[ MAX ];
    while( cin >> n )
    {
        for( int index = 0; index < n; index++ )
            scanf( "%d", &numbers[ index ] );
        printMinNumber( numbers, n );

    }
    return 0;
}
