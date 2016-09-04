List<int> list;

/*从1,2,3....n中随机的取出几个数使其和为sum*/
void sumofnum( int sum , int n )
{
  if( sum <= 0 || n < 0 )
    return;
  if( sum == n )
  {
    list.reverse();
    for( List<int>::iterator it = list.begin(); it != list.end(); it++ )
      cout<<*it<<" "<<endl;
  }
  else
  { 
    //类似于01背包问题
    list.push_front( n );
    sumofnum( sum - n, n - 1 );
    list.pop_front();
    sumofnum( sum, n - 1 );
  }
}
