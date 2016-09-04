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
    printf("%d ", arr[ index ] );
}

void netherlandsflags( int arr[], int n )
{
  int begin = 0;//指向值为0的元素
  int current = 0;//指向值为1的元素
  int end = n - 1;//指向值为2的元素
  
  //主要是处理current的变化
  while( current <= end )//注意此处使用end判断而不是n
  {
    if( arr[ current ] == 0 )
    {
        swap( &arr[ begin ], &arr[ current ] );
        current++;
        begin++;
    }
    else if( arr[ current ] == 1 )
      current++;
    else
    {
      swap( &arr[ current ], &arr[ end ] );
      end--;
      //此时current不变化
    }
    printf("第%d次交换：", current );
    print( arr, 11 );
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  int arr[] = { 1, 2, 0, 0, 2, 1, 2, 2, 1, 1, 0};
  netherlandsflags( arr, 11 );
  print( arr, 11 );
  return 0;
}
