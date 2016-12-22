#include<iostream>
#include<string>

using namespace std;

    typedef struct {             //structure to hold data of sensors
            int temp;              //using typedef we can create data type of structure so we dnt have to use struct all time
            int pressure;
            int humidity;
        }snesors;

void print_struct( snesors *node)
{
cout<<node->temp<<endl;
cout<<node->pressure<<endl;
cout<<node->humidity<<endl;
}

int main(void)
{

   // struct snesors *str_ptr;        // pointer to structure snesors

    snesors node1;           //declaring node1 of type sensors
    node1.temp = 25;
    node1.pressure = 30;
    node1.humidity = 50;
    print_struct(&node1);       //passing pointer of structure to function
    //str_ptr = &node1;
    //cout<<str_ptr->temp;
    return 0;
}
