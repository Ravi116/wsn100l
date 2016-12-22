/*
*   This code contains example of class,derived class,class access modifier(private,public,protected),default constructor,
*   parameterized constructor and destructor.
*   to understand constructor and destructor ,read output of this file along side of description of int main() ,
*   you will get idea of how objects are coming into the scope and removed from it at the end of program.
*
*/

#include<iostream>
#include<ctime>

using namespace std;

/**
*   class is like a structure with some protection features.
*   we can define functions within class.use '::' scope resolution operator to declare function outside of class.
*   private class members can only be accessed by class members and functions.
*   by default class member are private.we can define them as need as public,private,protected.
*/
class read_data{
    protected:        //protected variables to used by data class
    int t;
    int p;
    public:         //functions to modify variables
        read_data();        //general constructor
        ~read_data();        //general destructor
        void set_t(int num)
                  {
                    t = num;
                  }
        void set_p(int num){
                        p = num;
                    }
        int get_t(void);
        int get_p(void);
        int total(void);
 };
//declaration of general constructor
read_data::read_data(void)
{
    cout<<'\n'<<"constructer of read_data is created"<<endl;
}
read_data::~read_data(void)
{
    cout<<'\n'<<"Destructer is created,memory freed."<<endl;
}

int read_data::get_t(void)
{
    return t;
}

int read_data::get_p(void)
{
    return p;
}

 int read_data::total(void)
 {
    return get_t() + get_p() ;
 }

 /**Derived class (child class of read_data)
 *  Derived classes can use (protected) members of their parent classes.
 *  derived classes can't use private members of their parent class.
 *  Derived classes can have their own members as well as can use parents public and protected members.
 */

 class data:read_data
 {
     //by default private
     int k;
/**
*   Here constructor is declare,it will be executed whenever we create new member of that class.
*   constructor does not have any data type and they have same name as class.
*   constructor can be used to define initial values of important class members.
*/
public:
    data(int j);            // parameterized constructor
    ~data();
/**
*   A destructor is a special member function of a class that is executed whenever
*   an object of it's class goes out of scope or whenever the delete expression is
*   applied to a pointer to the object of that class.
*/
    void set_tt(int num)        //sets value of t from class read_data
    {
         t = num;
    }
    int get_tt(void)
    {
        return t;
    }
    void set_k(int);
     int get_k(void);
 };

//declaration of parameterized constructor ,which will set value of k
data::data(int j)
{
    cout<<'\n'<<"constructer of data is created"<<endl;
    k = j;
}
data::~data(void)
{
    cout<<'\n'<<"Destructer of data class is created"<<endl;
}
void data::set_k(int x)
{
    k = x;
}
int data::get_k(void)
{
    return k;
}

/**
*   using initialization to initialize fields
*/

class test
{

    int i;
    int j;
    int k;
    public:
    void getall(void){
        cout<<i<<j<<k;
    }
    test(int x,int y,int z);
    ~test();
};

test::test(int x,int y,int z):i(x),j(y),k(z)
{
    cout<<'\n'<<"initialize multiple fields using constructor"<<endl;
}
test::~test(void)
{
    cout<<'\n'<<"Destructer of test class is created"<<endl;
}

int main()
{
/**
* statements having clock_t,timer variables are used to measure time(clock ticks) passed during execution of this code.
*same can be used for any other code.
*/
clock_t timer;          //declare
timer = clock();

 read_data node1;   //create a class named node1
    node1.set_t(10);    // set t= 10
    node1.set_p(20);    //set p = 20
//  cout<<node1.p;      will give error as p is private use node1.get_p();
cout<<node1.get_t()<<node1.total()<<endl;

cout<<"testing of constructer of derived class"<<endl;

/*This will create a class named node2 with initial value of k=12 using parameterized constructor*/
data node2(12);         //create class named node2
cout<<"k defined by our construcor : "<<node2.get_k()<<endl;

node2.set_tt(15);
node2.set_k(25);
cout<<node2.get_tt()<<node2.get_k()<<endl;

cout<<"Another example of constructor"<<endl;
//here we are setting all member of class node3 using constructor
test node3(1,2,3);
node3.getall();

timer = clock() - timer ;           //deduct time passed from current clock output
cout<<"it took "<<timer/*this is ticks */<<(float)timer/CLOCKS_PER_SEC<<endl;
 return 0;
}
