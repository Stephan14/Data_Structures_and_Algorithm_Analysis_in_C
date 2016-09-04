#include<stdio.h>
/*最大乘积子数组*/
//动态规划最终要的是动态转化方程的转化
double maxproductsubstring( double arr[], int n )
{
  //初始化
  int index;
  double maxcur = mincur = arr[ 0 ];
  double  maxresult = arr[ 0 ];

  for( index = 1; index < n; index++ )
  {
    double end1 = maxcur * arr[ index ], end2 = mincur * arr[ index ];
    maxcur = max( max( end1, end2 ), arr[ index ] );//maxcur表示数组以index结尾的最大积的子数组
    mincur = min( min( end1, end2 ), arr[ index ] );//maxcur表示数组以index结尾的最小积的子数组
    maxresult = max( maxcur, mincur );
  }

  return maxresult;
}


int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
