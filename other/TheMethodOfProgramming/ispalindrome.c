#include<stdio.h>
#include<string.h>
/*判断是否是回文串*/
int isPalindrome( char *str )
{
  //判断边界条件
  if(str == NULL) return 0;

  int j = strlen( str ) - 1;
  int i = 0;
 
  while( i < j )
  {
    if( str[i] == str[j] )
    {
      i++;
      j--;
    }
    else
      return 0;
  }

  return 1;
}
int main(int argc, char const *argv[]) {
  char str[] = "abcbaD";
  if( isPalindrome( str ) )
  {
    printf("是\n");
  }
  else
    printf("否\n");
  return 0;
}
