#include<stdio.h>
#include<string.h>
/*左循环移动字符串*/
//翻转字符串
void strreverse( char *str ,int i, int j)
{
  while( i < j )
  {
    char ch = str[i];
    str[i++] = str[j];
    str[j--] = ch;
  }
}

//左循环移动字符串
void leftroutestring( char *str, int n, int m )
{
 //负面条件
  m = m % n;

  strreverse( str, 0, m-1);
  strreverse( str, m, n-1 );
  strreverse( str, 0, n-1 );
}


int main(int argc, char const *argv[]) {

  char str[10] = "abcdef";
  leftroutestring( str, strlen( str ), 3 );
  printf("%s\n", str );
  return 0;
}
