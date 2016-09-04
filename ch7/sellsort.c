#include<stdio.h>

void sellsort( int array[], int number )
{
  int increament, index, j, temp;

  for( increament = number / 2; increament > 0; increament /= 2 )
  {
    for( index = increament; index < number; index++ )//忽略increament前几个元素，从creament开始到数组的最后，根据缩量进行比较
    {
      temp = array[ index ];
      for( j = index; j >= increament; j -= increament )//按照缩量从后向前遍历数组进行比较
      {
        if( temp < array[ j -increament ] )//默认j-increament已经排序,将当前的元素逐一进行比较
          array[j] = array[ j - increament ];
        else
          break;
      }
      array[j] = temp;
    }
  }

}

int main(int argc, char const *argv[]) {
  int n;
  int array[] ={ 23, 76, 3, 67, 99, 1, 7, 34, 23 };
  sellsort( array, 9);
  for( n = 0; n < 9; n++ )
    printf( "%d\t", array[n] );
  printf("\n");
  return 0;
}
