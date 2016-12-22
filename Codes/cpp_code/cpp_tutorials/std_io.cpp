        /*          Example of standard input and output            */
#include<iostream>

using namespace std;

int main()
{
    char name[30] = "iys not between 20 to 30...";
    int age;
    cout <<"enter your name and age"<<endl;
    cin  >> age;
    if(age>=20 && age<=30)
    cout<< age;
    else
        cerr<<name<<endl;
    return 0;
}
