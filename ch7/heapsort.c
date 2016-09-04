#include<stdio.h>
void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
//下表在i~n中的元素进行交换
//构建大根堆
void max_percdown( int *arr, int i, int n )
{
  int temp, child;
  //注意此循环的循环体的设置
  for( temp = arr[i]; 2 * i + 1 < n; i = child )
  {
    child = 2 * i + 1;
    if( child != ( n - 1 ) && arr[ child + 1 ] > arr[ child ] )
      child++;
    if( arr[ child ] > temp )
      arr[i] = arr[ child ];
    else
      break;
  }
  arr[ i ] = temp;
}

void min_percdown( int *arr, int i, int n )
{
  int temp, child;
  //注意此循环的循环体的设置
  for( temp = arr[i]; 2 * i + 1 < n; i = child )
  {
    child = 2 * i + 1;
    if( child != ( n - 1 ) && arr[ child + 1 ] < arr[ child ] )
      child++;
    if( arr[ child ] < temp )
      arr[i] = arr[ child ];
    else
      break;
  }
  arr[ i ] = temp;
}

void heapsort( int *arr, int n )
{
  int i;
  //从后向前遍历
  for( i = n / 2; i >= 0; i-- )
    min_percdown( arr, i, n );
  for( i = n - 1; i >= 0; i-- )
  {
    swap( &arr[i], &arr[0] );
    min_percdown( arr, 0, i );
  }
}
int main(int argc, char const *argv[]) {
  int i = 0;
  int arr[] = { 78, 3, 45, 22, 56 };
  heapsort( arr, 5);
  for( ; i < 5; i++ )
    printf("%d\t", arr[i] );
  return 0;
}
