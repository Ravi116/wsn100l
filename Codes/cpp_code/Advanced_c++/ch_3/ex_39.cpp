/**
    9. Write a program that converts spelled-out numbers such as "zero" and
    "two" into digits, such as 0 and 2. When the user inputs a number, the
    program should print out the corresponding digit. Do it for the values 0,
    1, 2, 3, and 4 and write out "not a number I know" if the user enters
    something that doesn't correspond, such as "stupid computer!"
*/



#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
cout<<"Spell out a number between 0-4:"<<endl;
string number;
cin>>number;

    if(number == "zero")
        cout<<"Corresponding digit for"<<number<<" is "<<'0'<<endl;
    else if(number == "one")
        cout<<"Corresponding digit for"<<number<<" is "<<'1'<<endl;
    else if(number == "two")
        cout<<"Corresponding digit for"<<number<<" is "<<'2'<<endl;
    else if(number == "three")
        cout<<"Corresponding digit for"<<number<<" is "<<'3'<<endl;
    else if(number == "four")
       cout<<"Corresponding digit for"<<number<<" is "<<'0'<<endl;
    else
        cout<<"not a number i know"<<endl;

return 0;
}
