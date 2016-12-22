/**
    Write a program to test an integer value to determine if it is odd or even.
    As always, make sure your output is clear and complete. In other words,
    don't just output "yes" or "no." Your output should stand alone, like
    "The value 4 is an even number." Hint: See the remainder (modulo) operator
    in §3.4.
*/



#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
cout<<"Enter an integer value :"<<endl;
int val;
cin>>val;

if(val % 2)     //check if number is divided by 2 or not
    cout<<"The value "<<val<<" is odd number."<<endl;
else
    cout<<"The value "<<val<<" is even number."<<endl;
return 0;
}
