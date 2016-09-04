#include<iostream>
#include<cmath>

using namespace std;

bool errno = false;


bool equal( double a, double b )
{
    if( fabs( a - b) < 0.00001 )
        return true;
    else
        return false;
}

double powerWithUnsignedExponent( double base, unsigned int exponent )
{
    double result = 1.0;

    for( int i = 1; i <= exponent; ++i )
    {
        result *= base;
    }

    return result;
}

double power( double base, int exponent )
{
    if( equal( base, 0.0 ) && exponent < 0 )
    {
        errno = true;
        return 0.0;        
    }

    if( exponent < 0 )
    {
        return 1.0 / powerWithUnsignedExponent( base, (unsigned int)( -exponent ) );
    }
    else
        return powerWithUnsignedExponent( base, (unsigned int)( exponent ) );
}


int main()
{
    cout<< power( 3.4, 2 ) << endl;    
    return 0;
}
