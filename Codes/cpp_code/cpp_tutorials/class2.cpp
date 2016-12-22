#include<iostream>
#include<string>

using namespace std;

class random_data
{
    string name;
public:
    void getname(random_data data);
    friend void change_name(random_data name);
};

void random_data::getname(random_data data)
{
    cin <<data.name;
}
void change_name(random_data data)
{
    string changer = "changed";
    data.name = changer;
}
int main()
{
    return 0;
}

