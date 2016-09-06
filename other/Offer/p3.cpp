ass Solution {
public:
    bool Find( vector<vector<int> > array,int target )
    {
            int row = 0;
            int cloumn = array[0].size() - 1;

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
