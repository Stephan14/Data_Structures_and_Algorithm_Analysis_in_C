#include<stdio.h>

int rabbitbreed( int month )
{
  int index = 2;
  int dp[ 3 ] = { 1, 1 };
  if( month <= 2 )
    return dp[ month - 1 ];

  for( ; index < month; index++ )
  {
    dp[ 2 ] = dp[ 0 ] + dp[ 1 ];
    dp[ 0 ] = dp[ 1 ];
    dp[ 1 ] = dp[ 2 ];
  }

  return dp[ 2 ];
}

int main(int argc, char const *argv[]) {
  printf("%d\n", rabbitbreed( 5 ) );
  return 0;
}
