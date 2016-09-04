#include<stdio.h>


void PrintDigit( int number )
{
  if( number / 10 )
    PrintDigit( number / 10 );
  printf("%d", number % 10 );

}
int main(int argc, char const *argv[]) {
  //PrintDigit(0 );
  primtf("%d", -5);
  return 0;
}
