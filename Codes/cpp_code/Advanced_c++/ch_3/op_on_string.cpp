#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main(void)
{
    cout<<"Please Enter two names: "<<endl;
    string first;
    string second;
    cin>>first>>second;
    if(first == second)
            cout<<"its same name twice"<<endl;
    if(first<second)
            cout<<first<<" is alphabetically before "<<second<<endl;
    if(first>second)
            cout<<first<<" is alphabetically after "<<second<<endl;

    return 0;
}
