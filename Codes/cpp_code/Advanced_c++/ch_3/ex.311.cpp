/**
    1 . Write a program that prompts the user to enter some number of pennies
    ( 1-cent coins), nickels (S-cent coins), dimes ( 10-cent coins), quarters (25-
    cent coins), half dollars (50-cent coins), and one-dollar coins ( 100-cent
    coins) . Q!Iery the user separately for the number of each size coin, e.g.,
    "How many pennies do you have ?" Then your program should print
    out something like this:
    You have  23 pennies.
    You have  17 nickels.
    You have  14 dimes.
    You have  7 quarters.
    You have  3 half dollars.
    The value of all of your coins is 573 cents.
    You may have  to usc your imagination to get the numbers to add up
    right-justified, but try; it can be done. Make some improvements: if only
    one of a coin is reported, make the output grammatically correct, e.g.,
    " 14 dimes" and "1 dime" (not "1 dimes") . Also, report the sum in dollars
    and cents, i.e., $5.73 instead of 573 cents.
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
    cout<<"Hello user"<<endl;

    cout<<"How many pennies do you have ?"<<endl;
    int pennies = 0;
    cin>>pennies;

    cout<<"How many nickels do you have ?"<<endl;
    int nickels = 0;
    cin>>nickels;

    cout<<"How many dimes do you have ?"<<endl;
    int dimes = 0;
    cin>>dimes;

    cout<<"How many quarters do you have ?"<<endl;
    int quarters = 0;
    cin>>quarters;

    cout<<"How many half dollars do you have ?"<<endl;
    int half_dollars = 0;
    cin>>half_dollars;


    cout<<"How many dollars do you have ?"<<endl;
    int dollars = 0;
    cin>>dollars;

if(pennies == 1)
    cout<<"You have "<<pennies<<" penny"<<endl;
else
    cout<<"You have "<<pennies<<" pennies"<<endl;

if(nickels == 1)
    cout<<"You have "<<nickels<<" nickel"<<endl;
else
    cout<<"You have "<<nickels<<" nickels"<<endl;

if(dimes == 1)
    cout<<"You have "<<dimes<<" dime"<<endl;
else
    cout<<"You have "<<dimes<<" dimes"<<endl;

if(quarters == 1)
    cout<<"You have "<<quarters<<" quarter"<<endl;
else
    cout<<"You have "<<quarters<<" quarters"<<endl;

if(half_dollars == 1)
    cout<<"You have "<<half_dollars<<" half_dollar"<<endl;
else
    cout<<"You have "<<half_dollars<<" half_dollars"<<endl;

if(dollars == 1)
    cout<<"You have "<<dollars<<" dollar"<<endl;
else
    cout<<"You have "<<dollars<<" dollars"<<endl;

  double total = 0;
    total = (pennies + (5 * nickels) + (10 * dimes) + (25 * quarters) + (50 * half_dollars) + (100 * dollars));
    cout<<"Ohhhh,you have coins of total "<<total/100<<" $."<<endl;
    return 0;
}
