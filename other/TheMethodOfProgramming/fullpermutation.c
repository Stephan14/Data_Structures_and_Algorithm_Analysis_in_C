#include<stdio.h>
/*字符串的全排列*/
void swap( char *a, char *b )
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void fullpermutation( char *str, int from, int to )
{
  int index;

  // if( to <= 1 )
  //   return;
  //判断边界条件
  if( from == to )
  {
    int i;
    for( i = 0; i <= to; i++ )
      printf("%c\t", str[i] );
    printf("\n");

  }
  else{
  //回溯
    for( index = from; index <= to; index++ )
    {
      swap( &str[from], &str[index] );
      fullpermutation( str, from + 1, to );
      swap( &str[from], &str[index] );
    }
  }
}

int main(int argc, char const *argv[]) {
  char str[] = "adcs";
  fullpermutation( str , 0, 3 );
  return 0;
}
