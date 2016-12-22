/**
*
*   Write a program in C++ that converts from miles to kilometers. Your
*   program should have a reasonable prompt for the user to enter a number
*   of miles. Hint: There are 1.609 kilometers to the mile.
*
*/


#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
    cout<<"Please Enter distance in miles"
        <<"\nyou can enter it as 13 or 13.6 etc.."<<endl;
    float miles;
    cin>>miles;
    float kilometers = miles * 1.609;
    cout<<miles<<" miles = "<<kilometers<<" kilometers"<<endl;

    return 0;
}
