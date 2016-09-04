#include<stdio.h>
#include<string.h>

/*最长回文子串*/
int longestpalindrome( char *str )
{
  int i = 0, j, max = 0, temp_length = 0;
  if( str == NULL )
    return 0;
  int length = strlen( str );

  //i为回文的中心位置
  for( i = 0; i < length; i++ )
  {
    //回文长度为奇数
    if( length % 2 )
    {
      for( j = 0; ( i - j >= 0 ) && ( i + j < length ); j++ )
      {
        if( str[ i - j ] != str[ i + j ] )
          break;
        temp_length = j * 2 + 1;
      }
      if( temp_length > max )
        max = temp_length;
    }
    //回文长度为偶数
    else
    {
      for( j = 0; ( i - j >= 0 ) && ( i + 1 + j < length ); j++ )
      {
        if( str[ i - j ] != str[ i + 1 + j ] )
          break;
        temp_length = ( j + 1 ) * 2 ;
      }
      if( temp_length > max )
        max = temp_length;
    }
  }

  return max;
}
int main(int argc, char const *argv[]) {
  printf("%d\n", longestpalindrome("abba") );
  return 0;
}
