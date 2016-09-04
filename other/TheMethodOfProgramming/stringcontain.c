#include<stdio.h>
#include<string.h>
/*字符串包含另一个字符串*/
int stringcontain( char *str1, char *str2 )
{
  int hash = 0;
  int index;

  for( index = 0; index < strlen( str1 ); index++ )
    hash |= ( 1 << ( str1[ index ] - 'a' ) );

  for( index = 0; index < strlen( str2 ); index++ )
  {
    //判断整数的奇偶性时也可以使用此性质
    if( ( hash & ( 1 << ( str2[ index ] - 'a' ) ) ) == 0 )
      return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {
  char str1[] = "abcde";
  char str2[] = "dey";
  if( stringcontain( str1, str2 ) )
    printf("包含\n");
  else
    printf("不包含\n");
  return 0;
}
