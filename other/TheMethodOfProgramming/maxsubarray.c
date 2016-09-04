#include<stdio.h>

int maxsubarray( int arr[], int n )
{
  //初始化
  int index;
  int curmax = 0;
  int result = arr[ 0 ];

  for( index = 1; index < n; index++ )
  {
    if( curmax >= 0 )//判断前几个和是否大于零
      curmax += arr[ index ];
    else
      curmax = arr[ index ];
    if( curmax > result )
      result = curmax;
  }

  return result;
}
int main(int argc, char const *argv[]) {
  int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
  printf("%d", maxsubarray( a, 8) );
  return 0;
}
