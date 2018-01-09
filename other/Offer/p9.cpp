/*斐波那契数列*/
#include<iostream>
#include<utility>

using namespace std;
//利用long long类型解决大数字问题
//空间复杂度为O(1),时间复杂度为O(logn)
long long Fibonacci2( unsigned int n )
{
    int num[ 2 ] = { 0, 1 };
    if( n < 2 )
        return num[ n ];

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    
    //利用循环解决·
    for( unsigned int i = 2; i <= n; i++ )
    {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;    
    }
    
    return fibN;
} 

//时间空间复杂度为O(logn)
std::pair<uint64_t, uint64_t> Fibonacci1(uint64_t i) {
	if (i > 0) {
		auto n = Fibonacci1(i / 2);
		auto t0 = n.first;
		auto t1 = n.second;	

		if (i % 2) {
			return {t0 * t0 + t1 * t1, (2 * t0 + t1) * t1};
		} else {
			return {(2 * t1 -t0) * t0, t0 * t0 + t1 * t1};
		}
	}
	return {0, 1};
}

int main()
{
    cout << Fibonacci1( 4 ).second;    
    return 0;
}
