/*this code is example of array and how to use pointers to use array from function
* as well as we can use pointers instead of array notations.
*/

#include<iostream>      //std::cout,std::endl

//this two are required to generate random numbers in c/c++ codes.
#include<ctime>
#include<cstdlib>       //std::srand,std::rand
using namespace std;

typedef int itn;            //just for fun :mistake done below itn instead for int change it if you dont like

itn *getrandom(void)        //generate random numbers also example of function pointer
{
static int r[10];           //declare your local variable static when returning pointer from function

srand((unsigned)time(NULL));

for(int i=0;i<10;i++)       //save 10 random numbers in array r[]
{
r[i]=rand();
cout<<r[i]<<endl;
}

return r;           //returns address of r[0]
}


int main(void)
{
    int arr[5] = {10,5,2,7,1};      //array declaration
    int *ptr;                       //pointer of type int

    ptr = arr;                        //p points to arr[0]

    for(int i=0;i<5;i++){
        cout<<"*ptr + "<<i<<":- ";
        cout<<*(ptr+i)<<endl;
        }

    int *p = getrandom();           //*p == r[0] means p points to r[0]

    for(int i=0;i<10;i++){
                cout<<"*p + "<<i<<":- ";
                cout<<*(p+i)<<endl;
                }
return 0;
}
