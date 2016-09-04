#include<stdio.h>

#define ARRAY_LENGTH 5

int cmp_int( const void *a, const void *b )
{
  return *( int * ) a - *( int * ) b;
}

int main(int argc, char const *argv[]) {
  int num = 0, index = 0;
  int number_array[ ARRAY_LENGTH ];

  while( index < ARRAY_LENGTH )
      scanf("%d", &number_array[ index++ ]);

  qsort( number_array, ARRAY_LENGTH, sizeof( number_array[0] ), cmp_int );

  while( scanf( "%d", &num ) != EOF )
    number_array[ARRAY_LENGTH-1] = number_array[ARRAY_LENGTH-1] < num ? number_array[ARRAY_LENGTH-1] : num ;

  // for( index = 0; index < ARRAY_LENGTH; index++ )
  //   printf( "%d\t", number_array[index] );

  printf( "%d\n", number_array[ARRAY_LENGTH-1] );
  return 0;
}
