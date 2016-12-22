    /*      Example of c type string operations in c++.     */
#include<iostream>
#include<cstring>       //include to use all same functions from string.h

using namespace std;
int leng;
int main(void)
{
    char str1[15]="hello";
    char str2[15]="string";
    char str3[15] = {0};
    int len = 0;

    strcpy(str3,str1);      //copy str1 to str3
        cout<<str3<<endl;
    strcat(str3,str2);      //concatenate str2 to at the end of str1
        cout<<str3<<endl;
    len = strlen(str3);     //length of str3
        cout<<len<<endl;
    int i = strcmp(str3,str1);      //compare str1 and str2
        cout<<i<<endl;              //-1 if str1<str2,1 if str1>str2,0 if str1==str2
return 0;
}
