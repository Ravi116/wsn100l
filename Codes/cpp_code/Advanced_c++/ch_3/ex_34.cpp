/**
*    6. Write a program that prompts the user to enter three integer values, and
*    then outputs the values in numerical sequence separated by commas. So,
*    if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
*    values are the same, they should just be ordered together. So, the input 4
*    5 4 should give 4, 4, 5.
*/



#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void)
{
     cout<<"Enter three integers :-"<<endl; //promt user to enter three numbers
    int val1,val2,val3;
    cin>>val1>>val2>>val3;
    cout<<"you entered :- "<<val1<<','<<val2<<" & "<<val3<<endl;

    if(val1 >= val2){               // check if val1 is greater or equal to val2
        if(val1 >= val3){           //if above statement is true than check val1 is greater or equal to val3
                if(val2>=val3)      //if above statement is true than check val2 is greater or equal to val3
                  cout<<"Correct order is"<<val3<<','<<val2<<','<<val1<<endl;//if true than print order
                else                //if  val3 is greater or equal to val2
                  cout<<"Correct order is"<<val2<<','<<val3<<','<<val1<<endl;// print order
        }
        else                        //if val3 is greater or equal to val1
           cout<<"Correct order is"<<val2<<','<<val1<<','<<val3<<endl;
    }
    else{                       //if val2 is greater than val1
        if(val2 >= val3){       //if above statement is true than check val2 is greater or equal to val3
                if(val1>=val3)  //if above statement is true than check val1 is greater or equal to val3
                  cout<<"Correct order is"<<val3<<','<<val1<<','<<val2<<endl;
                else            //if  val3 is greater or equal to val1
                  cout<<"Correct order is"<<val1<<','<<val3<<','<<val2<<endl;
        }
        else        //if  val3 is greater or equal to val2
           cout<<"Correct order is"<<val1<<','<<val2<<','<<val3<<endl;
    }


    return 0;
}
