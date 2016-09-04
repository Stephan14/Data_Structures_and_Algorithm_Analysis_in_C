#include<stdio.h>
void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort( int array[], int number )
{
  int i, j, bound = number;

  while( bound != 0 )
  {
    j = 0;
    for( i = 0; i < bound - 1; i++ )
    {
      if( array[ i ] > array[ i + 1 ] )
      {
        swap( &array[ i ], &array[ i + 1 ] );
        j = i + 1;
      }
    }
    bound = j;
  }
}


void bubblesort2(int array[], int number)
{
  int i, j;
  for( i = 0; i < number; i++ )
  {
    for( j = 0; j < number - 1; j++ )
      if( array[ j ] > array[ j + 1 ] )
        swap( &array[ j ], &array[ j + 1 ]);
  }
}
int main(int argc, char const *argv[]) {
  int arrray[] = { 223, 1, 34, 56, 7, 8, 9, 23 };
  bubblesort2( arrray, 8 );
  int i ;
  for( i = 0; i < 8; i++ )
    printf("%d\t", arrray[i] );
  printf("\n" );
  return 0;
}
