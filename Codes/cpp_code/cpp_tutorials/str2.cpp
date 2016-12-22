        /*      Example of string class in c++      */
#include<iostream>
#include<string>

using namespace std;
typedef int length;
int main(void)
{
    string str1 = "hello";
    string str2 = "string";
    string str3;
    length len;

    // cout<<&len<<endl;        //adrress of defined variable

    len = str2.size();      //length of str2
    cout<<len<<endl;
    str3 = str1 + str2;     //concatenate str2 to str1
    cout<<str3<<endl;
    str3 = str2;            //copy str2 to str3
    cout<<str3<<endl;
    return 0;
}
