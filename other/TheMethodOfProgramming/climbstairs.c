#include<stdio.h>
int climbstairs( int n )
{
  int dp[ 3 ] = { 1, 1 };
  int index = 2;
  if( n < 2 )
    return dp[ n ];
  for( ; index <= n; index++ )
  {
    dp[ 2 ] = dp[ 0 ] + dp[ 1 ];
    dp[ 0 ] = dp[ 1 ];
    dp[ 1 ] = dp[ 2 ];
  }

  return dp[ 2 ];
}

long long Fibonacci( int n )
{
  if( n == 1 ) return 1;
  if( n == 2 ) return 2;
  return Fibonacci( n - 1 ) + Fibonacci( n - 2 );
}
int main(int argc, char const *argv[]) {
  printf("%d\n", climbstairs( 3 ) );
  printf("%lld\n", Fibonacci( 3 ) );
  return 0;
}
