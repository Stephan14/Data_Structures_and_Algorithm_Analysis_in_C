#include<stdio.h>

/*归并排序*/
void merge( int array[], int temp[], int left, int mid, int right )
{
  int num = right - left + 1;
  int i = left;
  int j = mid+1;
  int temp_index = left;

  //将两个数组进行合并
  while( i <= mid && j <= right )
  {
    if( array[ i ] < array[ j ] )
      temp[ temp_index++ ] = array[ i++ ];
    else
      temp[ temp_index++ ] = array[ j++ ];
  }

  //将数组剩余的部分合并
  while( i <= mid )
    temp[ temp_index++ ] = array[ i++ ];
  while( j <= right )
    temp[ temp_index++ ] = array[ j++ ];

  for( temp_index = 0; temp_index < num; temp_index++, right--)
    array[ right ] = temp[ right ];

}

void mergesort( int array[], int temp[], int i, int j )
{
  if( i < j )
  {
    int mid = i + ( j - i ) / 2;
    mergesort( array, temp, i, mid );
    mergesort( array, temp, mid + 1, j );
    merge( array, temp, i, mid, j );
  }
}

int main(int argc, char const *argv[]) {
  int index = 0;
  int temp[ 8 ];
  int array[] = { 12, 22, 23, 1, 34, 64, 45, 2 };
  mergesort( array, temp, 0, 7 );
  for( ; index < 8; index++ )
    printf("%d\t", array[ index ] );
  return 0;
}
