/*          Example of pointer/array (passed to) or (returned from) function             */

//include
#include<iostream>
#include<ctime>

using namespace std;

// Function prototype
void getseconds(unsigned long *par);        //pointer to a function example
double getaverage(int *arr,int size);       //array to a function example

/*To see example of function returning pointer ,refer to arr_ptr.cpp and read itn *getrandom();*/
int main(void)
{
unsigned long sec;
int balaji[5] = {1,10,100,1000,10000};
double avg;

getseconds(&sec);                       //passing address pointer to function
cout<<"SECONDS:- "<<sec<<endl;

avg = getaverage(balaji,5);             //passing address of arr[0] with size of array
cout<<"AVERAGE IS :-"<<avg<<endl;

return 0;
}


//pointer to a function example
void getseconds(unsigned long *par)
{
    *par = time(NULL);      //get the current value of seconds
    return;
}

//array to function
double getaverage(int *arr,int size)
{
    int i,sum = 0;
    double avg;

    for(i=0;i<size;i++)         //get sum of all elements of array
        sum += arr[i];

    avg = (double)sum / size;
    return avg;                 //return average
}
