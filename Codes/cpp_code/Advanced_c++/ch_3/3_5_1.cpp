#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main(void)
{
    int number_of_words = 0;

    string previous = " ";
    string current;
    while(cin>>current)
    {
        ++number_of_words;
        if(previous == current)
                cout<<"Word number: "<<number_of_words<<"\nRepeated string. :"<<current<<endl;
        previous = current;
    }
    return 0;
}
