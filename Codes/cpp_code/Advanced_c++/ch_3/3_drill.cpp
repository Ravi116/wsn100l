/**
*a letter to your friend BASED ON USER input
*/

#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main(void)
{
    string first_name;
    cout<<"Please Enter first name of person you want to write to:"<<endl;
    cin>>first_name;
    cout<<"Dear"<<first_name<<','<<endl;
    cout<<"How are you?\n"
        <<"i am fine.\n"
        <<endl;
    string friend_name;
    cout<<"Enter your friend's name"<<endl;
    cin>>friend_name;
    cout<<"Have you seen "<<friend_name<<" lately?"<<endl;
    char friend_gender = 0;
    cout<<"Enter your friend's gender"<<endl;
    cin>>friend_gender;
    if(friend_gender == 'm')
        cout<<"IF you see "<<friend_name<<" ,Ask him to call me back."<<endl;
    else if(friend_gender == 'f')
                cout<<"IF you see "<<friend_name<<" ,Ask her to call me back."<<endl;
    else
                cout<<"please check your input"<<endl;

int friend_age = 0;
    cout<<"Enter your friend's age"<<endl;
    cin>>friend_age;
    cout<<"I heard you just had a birthday and you are now "
        <<friend_age<<" old."<<endl;

    if((friend_age >= 110)||(friend_age <= 0))
        cout<<"You are kidding"<<endl;
    if((friend_age > 0)&&(friend_age < 12))
        cout<<"Next year you will be"<<friend_age+1<<endl;
    if(friend_age == 17)
            cout<<"Next year you will be able to vote"<<endl;
    if(friend_age >= 70)
       cout<<"I hope you are enjoying your retirement."<<endl;

        cout<<"yours sincerely,"<<'\n'<<'\n'<<"my name."<<endl;
        return 0;
}

