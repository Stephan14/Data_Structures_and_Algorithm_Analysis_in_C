#include<stdio.h>

void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void qsort( int *array, int left, int right  )
{
  int i = left;
  int j = right;

  if( i < j )
  {
    while( 1 )
    {
      while( array[ ++i ] < array[ left ] ){}
      while( array[ --j ] > array[ left ] ){}
      if( i < j )
        swap( &array[ i ], &array[ j ] );
      else
        break;
    }
    swap( &array[ j ], &array[ left ] );

    qsort( array, left, j - 1 );
    qsort( array, j + 1, right );
  }
}

void twosum( int *array, int sum, int n )
{
  qsort( array, 0, n );
  int left = 0;
  int right = n - 1;
  //类似与二分查找
  while( left < right )
  {
    if( ( array[ left ] + array[ right ] ) == sum  )
    {
      printf("%d\t %d\t", array[ left ], array[ right ] );
      break;
    }else if( ( array[ left ] + array[ right ] ) >= sum )
      right--;
    else if( ( array[ left ] + array[ right ] ) <= sum )
      left++;
  }
}
int main(int argc, char const *argv[]) {
  int i = 0;
  int a[] = { 23, 12, 45, 67, 34, 44, 90, 3 };
  //qsort( a, 0, 8);
  twosum( a, 26, 8);
  for( ; i < 8; i++ )
    printf("%d\t", a[i] );
  return 0;
}
