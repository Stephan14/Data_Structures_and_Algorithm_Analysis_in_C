#include<stdio.h>
#include<string.h>
/*KMP查找算法*/
void getNext( char *str, int *next)
{
  int plength = strlen( str );
  int k = -1;
  int j = 0;
  next[0] = -1;

  while( j < plength - 1 )
  {
    //str[j]表示前缀str[k]表示后缀
    if( k == -1 || str[j] == str[k] )
    {
      ++k;
      ++j;
      next[j] = k;
    }
    else
      k = next[k];
  }
}

int kmpserach( char *text, char *pattern, int *next )
{
  int textlength = strlen( text );
  int patternlength = strlen( pattern );
  int i = 0;
  int j = 0;

  if( text == NULL || text == NULL )
    return 0;
  while( i < textlength && j < patternlength )
  {
    if( j == -1 || text[i] == pattern[j] )
    {
      i++;
      j++;
    }
    else
      //将模式字符串移动j-next[j]位
      j = next[j];
  }
  if( j == patternlength )
    return i - j;
  else
    return -1;
}

int main(int argc, char const *argv[]) {
  char text[10] = "sfdsgfsdg";
  char pattern[10] = "sgf";
  int next[10];

  getNext( pattern, next );
  printf("%d\n", kmpserach( text, pattern, next ) );
  return 0;
}
