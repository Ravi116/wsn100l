/*          Examples of usage of array of pointers (for more read ptr3.cpp)           */

#include<iostream>
#include<iomanip>       // to include setw()

using namespace std;

#define MAX 3

int main(void)
{
    int i,j;
    int var[MAX] = {10,100,1000};
    int *ptr[MAX];                                  //declared array of integer pointers
    int **ptr2[MAX];                                //array of pointer which points to pointers of integer

    //assign each element addrress of val array
    for(i=0;i<MAX;i++){
        ptr[i] = &var[i];
        ptr2[i] = &ptr[i];                         //assigning address of ptr2[i]=&ptr[i]=&var[i]
    }

    //lets check value of our pointers,will print array in reverse order

    for(i = (MAX-1);i >= 0;i--)                     //decrementing pointers
    {
        cout<<"*ptr value:-"<<*ptr[i]<<endl;
        cout<<"**ptr2 value:-"<<**ptr2[i]<<'\n'<<endl;
    }



/*      array of pointers of characters     */
    char *ptr1[MAX] ={  "Sigma",
                        "trainers",
                        "& Kits"};

    char **ptr3[MAX];                               //pointers of character pointers

   //assigning address of ptr1
    for(i=0;i<MAX;i++){
        ptr3[i] = &ptr1[i];
    }

    for(i=0,j=10;i < MAX;i++,j += 5)
        {
            cout<<setw(j);                                    //set word width of size j
            cout<<"*ptr1 value:"<<ptr1[i]<<'\n'<<endl;        //will print string given in ptr1[]
            cout<<"**ptr3 value:"<<*ptr3[i]<<'\n'<<endl;
        }               //this output looks ugly,it can be made good looking by adjusting "setw(value)"
    return 0;
}
