/*          Examples of usage of pointers for more read ptr2.cpp           */

#include<iostream>

using namespace std;

int main()
{
    int *ptr = NULL;        //Null pointer:-a ptr that points to nothing or 0(memory address).

    cout<<"Null pointer"<<'\n'<<ptr<<endl;
/* we can test a pointer is null or not by following method.
*    int *ptr1;         //ptr1 is not null,but ptr is null.
*    if(!ptr1)
*      cout<<"pointer is null"<<endl;
*    else
*      cout<<"pointer is not null";
*/

 //pointer arithmetic increment and decrement
    cout<<"Pointer arithmetic"<<endl;
    int val[]={10,20,30};
    int *ptr1;
    ptr1 = val;             //points to var[0]
    ptr1++;                 //points to var[1] = 20
    cout<<*ptr1<<endl;
    ptr1--;                 //points to var[0] = 10
    cout<<*ptr1<<endl;
    (ptr1++);
     ptr1++;                //points to var[2] = 30
    cout<<*ptr1<<endl;

return 0;
}
