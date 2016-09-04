#include<stdio.h>
#include<ctype.h>
/*将字符串转化成整型*/
int strtoint( char *str )
{
  int result = 0;
  int sign = 1;
  static int MAX_INT = (int)( (unsigned)~0 >> 1 );
  static int MIN_INT = -(int)( ( (unsigned)~0 >> 1 ) - 1 );
  
  //判断边界条件
  if( str == NULL )
    return 0;

  while( isspace( *str ) )
    ++str;
  if( *str == '-' || *str == '+' )
  {
    if( *str == '-')
      sign = -1;
    ++str;
  }

  while( isdigit( *str ) )
  {
    int n = *str - '0';
    if( sign > 0 && ( result > MAX_INT / 10 || ( result == MAX_INT / 10 && n > MAX_INT % 10 ) ) )
    {
      return MAX_INT;
      break;
    }
    else if( sign < 0 && ( result >(unsigned)MIN_INT / 10 || ( result == (unsigned)MIN_INT / 10 && n > (unsigned)MIN_INT % 10 ) ) )
    {
      return MIN_INT;
      break;
    }
    result = result * 10 + n;
    ++str;
  }

  return result * sign;
}

int main(int argc, char const *argv[]) {
  printf("%x\n", (unsigned)~0 );
  printf("%x\n", ~0 );
  printf("%x\n", 1 );
  printf("%x\n", 0 );
  char str[] = "-123";
  printf("%d\n", strtoint( str ) );
  return 0;
}
