#include<stdio.h>

void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void qsort( int array[], int begin, int end )
{
  int index;
  int i = begin;
  int j = end;

  if( i < j )
  {
    while( 1 )
    {
      while( array[ ++i ] < array[ begin ] );//使用前置++
      while( array[ --j ] > array[ begin ] );

      if( i < j )
        swap( &array[i], &array[j] );
      else
        break;
    }
    swap( &array[ begin ], &array[ j ] );
    qsort( array, begin, j  );
    qsort( array, j + 1, end );
  }
}

int part2( int a[], int begin, int end )
{
  int i = begin - 1, j;

    for( j = begin; j < end; j++ )
    {
      if( a[ j ] <= a[ end ] )
      {
        i++;
        swap( &a[i], &a[j]);
      }
    }
    swap( &a[ ++i ], &a[ end ] );
    return i;
}

void qsort2( int a[], int begin, int end )
{
  int p;
  if( begin < end )
  {
    p = part2( a, begin , end );
    qsort2( a, begin, p - 1 );
    qsort2( a, p + 1, end );
  }
}
int main(int argc, char const *argv[]) {
  int array[] = { 4, 1, 199, 8, 9, 2, 3, 2, 1};
  qsort2( array, 0, 8 );
  int index  = 0;
  for( ; index < 9; index++ )
    printf("%d\t", array[index]);
  printf("\n");
  return 0;
}
