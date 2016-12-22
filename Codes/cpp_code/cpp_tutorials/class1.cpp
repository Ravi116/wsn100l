/*
                EXAMPLE OF COPY CONSTRUCTOR
*/
#include<iostream>

using namespace std;
class linee
{
    int *ptr;
public:
    int getlength(void);        // get length
    linee(int len);             //parameterized constructor
    ~linee();                      //destructor
    linee(const linee &obj);    //copy constructor

};

linee::linee(int len)
{
    cout<<"linee constructor"<<endl;
    ptr = new int;
    *ptr = len;
}

linee::linee(const linee &obj)
{
    cout<<"into obj copy constructor"<<endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

linee::~linee()
{
    cout<<"The end"<<endl;
    delete ptr;
}
int linee::getlength()
{
    return *ptr+1;
}

void display(linee obj)
{
    cout<<"in copy we have: "<<obj.getlength()<<endl;

}
int main(void)
{
    linee line(123);
    cout<<line.getlength()<<endl;
    display(line);      // copy constructor created here
    linee line2 = line;
    display(line2);
    return 0;
}
