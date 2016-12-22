/**
*unsafe conversions
*/

#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main(void)
{
    double d = 0.0;
    while(cin>>d)
    {
        int i = d;
        char c = i;
        int i2 = c;
        cout<<" \td == "<<d
            <<" \ti == "<<i
            <<" \tc == "<<c
            <<" \ti2 == " <<i2<<endl;
    }
    return 0;
}
