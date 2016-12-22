/**
    Write a program that takes an operation followed by two operands and
    outputs the result. For example:
    + 100 3.14
    • 4 5
    Read the operation into a string called operation and use an if-statement
    to figure out which operation the user wants, for example, if (opera·
    tion=="+"). Read the operands into variables of type double. Implement
    this for operations called +, -, *, /, plus, minus, mul, and div with their
    obvious meanings .
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{

cout<<"Enter operation with numbers:(i.e,+ 100 3.14 or mul 4 5 etc.)"<<endl;
string operation;
double val1,val2;
cin>>operation>>val1>>val2;
cout<<"user input : "<<operation<<' '<<val1<<' '<<val2<<endl;

if((operation == "+") || (operation == "plus"))
    cout<<val1<<" + "<<val2<<" = "<<val1 + val2<<endl;
else if((operation == "-") || (operation == "minus"))
    cout<<val1<<" - "<<val2<<" = "<<val1 - val2<<endl;
else if((operation == "*") || (operation == "mul"))
    cout<<val1<<" * "<<val2<<" = "<<val1 * val2<<endl;
else if((operation == "/") || (operation == "div"))
    cout<<val1<<" / "<<val2<<" = "<<val1 / val2<<endl;
else
    cout<<"Invalid operation for now"<<endl;
    return 0;
}
