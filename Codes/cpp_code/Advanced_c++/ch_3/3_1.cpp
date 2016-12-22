#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }

int main(void)
{
float age;
string name;
cout<<"Please your name and age"<<endl;
cin>>name>>age;
age *= 12;
cout<<"Hello: "<<name<<endl;
cout<<"your age in month is: "<<age<<endl;
    return 0;
}
