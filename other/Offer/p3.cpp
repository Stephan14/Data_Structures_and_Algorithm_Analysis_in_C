/*二维数组中查找*/
 
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool findTarget( vector<vector<int> > array,int target )
    {
            int row = 0;
            int cloumn = array[ 0 ].size() - 1;

            while(  row < array.size() && cloumn >= 0 )
            {
                if( array[ row ][ cloumn ] == target )
                    return true;
                else if( array[ row ][ cloumn ] < target )
                    row++;
                else if( array[ row ][ cloumn ] > target )
                    cloumn--;
            } 

            return false;
    }
};

int main()
{
    Solution s;
    int m[][ 4 ] = {
        { 1, 2, 8, 9 },
        { 2, 4, 9, 12 },
        { 4, 7, 10, 13 },
        { 6, 8, 11, 15 },
    };
        
    vector< int > v1( &m[ 0 ][ 0 ], &m[ 0 ][ 0 ] + 4 ); 
    vector< int > v2( &m[ 1 ][ 0 ], &m[ 1 ][ 0 ] + 4 );
    vector< int > v3( &m[ 2 ][ 0 ], &m[ 2 ][ 0 ] + 4);
    vector< int > v4( &m[ 3 ][ 0 ], &m[ 3 ][ 0 ] + 4);

    vector< vector<int> > v;
    v.push_back( v1 );
    v.push_back( v2 );
    v.push_back( v3 );
    v.push_back( v4 );

    cout << v[0].size() << endl;
    if( s.findTarget( v, 15  ) )
    {
        cout<< "存在" << endl;
    }
    else
    {
        cout<< "不存在" << endl;
    }
    return 0;
}
