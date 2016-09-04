#include<stdio.h>

void insertsort( int array[], int amount )
 {
  int index, j;
  for( index = 1; index < amount; index++ )
  {
    int temp = array[ index ];

    for( j = index ; j > 0 && array[ j-1 ] > temp ; j-- )
      array[ j ] = array[ j - 1 ];

    array[ j ] = temp;
  }
}

int main(int argc, char const *argv[]) {
  int j;
  int array[] = { 1, 6, 99, 3, 56, 2, 1};
  insertsort( array, 7 );
  for( j = 0; j < 7; j++ )
    printf("%d\t", array[j] );
  printf("\n" );
  return 0;
}
