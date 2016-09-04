#include<stdio.h>
void swap( int *a, int *b )
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void print( int arr[], int n )
{
  int index;
  for( index = 0; index < n; index++ )
    printf("%d\t", arr[ index ] );
}

void oddeventsort( int arr[], int n )
{
  int index, first = -1, last = 0;
  for( index = 0; index < n; index++ )
  {
    if( arr[ index ] % 2 )
    {//last指向奇数
      first++;
      swap( &arr[ first ], &arr[ index ] );
    }
    /*测试
    printf("%d次交换", index + 1 );
    print( arr, n );
    printf("\n");
    */
  }
  swap( &arr[ first + 1 ], &arr[ index - 1 ] );
}


int main(int argc, char const *argv[]) {
  int arr[] = { 11, 22, 32, 45, 22, 13 };
  oddeventsort( arr, 6 );
  int index = 0 ;
  for( ; index < 6; index++ )
    printf("%d\t", arr[ index ] );
  return 0;
}
