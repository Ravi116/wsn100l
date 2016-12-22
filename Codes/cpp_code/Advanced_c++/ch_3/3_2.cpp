#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main(void)
{
    cout<<"Please enter a integer. "<<endl;
    int num;
    cin>>num;
    cout<<"num = "<<num<<endl;
    cout<<"num + 1: "<<num + 1<<endl;
    cout<<"twice: "<<num + num<<endl;
    cout<<"Squared: "<<num*num<<endl;
    cout<<"half: "<<num/2<<endl;
    double sqr = sqrt(num);
    cout<<"Square root: "<<sqr<<endl;

    cout<<"Please enter a integer. "<<endl;
    int num1;
    cin>>num1;
int result =  num/num1 * num1 + num % num1;
    cout<<result<<endl;
    return 0;
}
