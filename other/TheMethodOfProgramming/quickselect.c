#include<stdio.h>

void swap( int *a, int *b )
{
  int temp = *a;
  *a  = *b;
  *b = temp;
}

void qucikselect( int array, int k, int left, int right )
{
  int i, j;
  int pivot = array[ left ];
  if( left <= right )
  {
    i = left;
    j = rifht - 1;
    while(1)
    {
      while( array[ ++i ] < pivot ){}
      while( array[ --j ] > pivot ){}
      if( i < j )
        swap( &array[ i ], &array[ j ] );
      else
        break;
    }
    //将比pivot大的数与最后一个互换
    swap( &array[i], &array[ right - 1 ] );

    if( k <= i )
      qucikselect( array, k, left, i -1 );
    else if( k > i + 1 )
      quickselect( array, k, i + 1, right );
  }
  else
  {
    /*插入排序*/
  }

}

int main(int argc, char const *argv[]) {

  return 0;
}
