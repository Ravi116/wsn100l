/**
*ask for persons name and create frame around it
*/

#include <iostream>
#include <string>

//using namespace std;

int main()
{
    std::cout<<"enter your name"<<std::endl;

    std::string name;   //define name
    std::cin>>name;     //initialize name and store data into standard buffer
    //1.cin reads from white space to white space
    //i.e. if we enter hello world to cin it will only read hello as input,rest is discarded.
    //2.cin,cout uses buffer to store data,data is given out by flushing the buffer.
    //buffer can be flushed by 3 ways:
    //(if buffer gets full ,library will flush it automatically)
    //(if library might be asked to read from iostream(use of cout))
    //(manually flushing buffer)

    const std::string greeting = "Hello, " + name + "!";
    //using + we can concatenate two strings
    const std::string spaces(greeting.size(),' ');
    const std::string second = "*" + spaces + "*";
    const std::string first(second.size(),'p');

        std::cout<<std::endl;
        std::cout<<first<<std::endl;
        std::cout<<second<<std::endl;
        std::cout<<"*"<<greeting<<"*"<<std::endl;
        std::cout<<second<<std::endl;
        std::cout<<first<<std::endl;
    return 0;
}
