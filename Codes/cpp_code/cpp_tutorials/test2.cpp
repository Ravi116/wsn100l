#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(void){
    int i,j;

    //set the seed
    srand((unsigned)time(NULL));

// generate 10 random numbers
    for(i=0;i<10;i++){

//actual random number generation
        j = rand();

        cout<<"random number is"<<j<<endl;

    }
return 0;
}
