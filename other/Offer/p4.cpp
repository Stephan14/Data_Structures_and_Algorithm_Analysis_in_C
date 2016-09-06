#include<iostream>

using namespace std;


void repalceBlank( char strings[], int length )
{
	if( strings == NULL || length < 0 )
		return;
		
	//统计字符串的长度和空格的数量
	int originStringsLength = 0;
	int spaceStringsNumber = 0;
	int index = 0;
	while( strings[ index ] != '\0' )
	{
		++ originStringsLength;
		if( strings[ index ] == ' ' )
			++ spaceStringsNumber;
		index++;
	}

	//判断字符数组的长度是否允许
	int newOriginStringsLength = originStringsLength + 2 * spaceStringsNumber;
	if( newOriginStringsLength > length )
		return;
	
	--newOriginStringsLength;
	--originStringsLength;
	while( newOriginStringsLength > originStringsLength && originStringsLength >= 0 )
	{
		if( strings[ originStringsLength ] == ' ' )
		{
			strings[ newOriginStringsLength-- ] = '0';
			strings[ newOriginStringsLength-- ] = '2';
			strings[ newOriginStringsLength-- ] = '%';
		}
		else
			strings[ newOriginStringsLength-- ] = strings[ originStringsLength ];		
		--originStringsLength;
	}


}

int main()
{
	
	return 0;
}
