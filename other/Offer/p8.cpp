/*旋转数组的最小数字*/
#include<iostream>

using namespace std;

int minElement( int *arr, int length )
{
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    
    while( arr[ index1 ] >= arr[ index2 ] )
    {
       if( index2 - index1 == 1 )
       {
            indexMid  =  index2;
            break;
       }

       indexMid = ( index1 + index2 ) / 2;
        cout << "indexMid" << indexMid << endl;
       if( arr[ index1 ] <= arr[ indexMid ] )
           index1 = indexMid;
       else if( arr[ index2 ] >= arr[ indexMid ] )
           index2 = indexMid;
    }

    return arr[ indexMid ];   
}

int main()
{
    int arr[] = { 6, 7, 88, 99, 1, 2, 3  };
    cout << minElement( arr, 7 ) << endl;
    return 0;
}
