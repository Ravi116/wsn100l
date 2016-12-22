/**
*    4. Write a program that prompts the user to enter two integer values. Store
*    these values in int variables named val1 and vall. Write your program to
*    determine the smallest, largest, sum, difference, product, and ratio of
*    these values and report them to the user.
*/



#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
    cout<<"Enter two integers :-"<<endl;
    int val1,val2;
    cin>>val1>>val2;
    cout<<"you entered :- "<<val1<<" & "<<val2<<endl;

    if(val1>val2){
        cout<<val2<<"is smallest."<<endl;
        cout<<val1<<"is largest."<<endl;}
    else
        cout<<val1<<" is smallest."<<endl;
        cout<<val2<<" is largest."<<endl;
    cout<<"Sum of "<<val1<<" & "<<val2<<" is :"<<val1 + val2<<endl;
    cout<<"Product of "<<val1<<" & "<<val2<<" is :"<<val1 * val2<<endl;

    if(val1>val2){
    cout<<"Ratio of "<<val1<<" & "<<val2<<" is :"<<val1 / val2<<endl;
    cout<<"Difference of "<<val1<<" & "<<val2<<" is :"<<val1 - val2<<endl;}
    else{
    cout<<"Ratio of "<<val1<<" & "<<val2<<" is :"<<val2 / val1<<endl;
    cout<<"Difference of "<<val1<<" & "<<val2<<" is :"<<val2 - val1<<endl;}

return 0;
}
