        /*          Example of references in cpp            */
        // its like pointers in c but we can references as second identifier for variable
        // as pointer ,references can't be NULL also they have to be initialize on when created
        //  reference can not be used for another object other than its initialized object

#include<iostream>

using namespace std;

int arr[] = {1,11,111,1111,11111};

int& setvalue(int i)
{
    return arr[i];
}
int main()
{
    int i =5;
    char c = 'c';
    string str1 = "ref";

    int& r = i;
    char& s = c;
    string& t = str1;

    cout<<r<<endl;
    cout<<s<<endl;
    cout<<t<<endl;
                            //    int *ptr = arr; can reduce function call of setvalue() by this
   setvalue(1) = 0;         //  same as *(ptr + 1) = 0;
    for(int j=0;j<5;j++)
            cout<<arr[j]<<endl;
    setvalue(4) = setvalue(0) + setvalue(1);
        for(int j=0;j<5;j++)
            cout<<arr[j]<<endl;
return 0;
}
