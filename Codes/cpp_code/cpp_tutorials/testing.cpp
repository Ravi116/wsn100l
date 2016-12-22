#include<iostream>
//#include<fstream>       // to open a file

using namespace std;

//void node1_recieved_data(char arra[]);
//void node2_recieved_data(char arra[])
void node1_recieved_data(void);
void node2_recieved_data(void);

#define YES "DETECTED"
#define NO  "NOT-DETECTED"

int arr0[6] = {3,10,20,15,0,10};

const char *node1_sensor_name[] = {"Node Id",
                "sensor 1 : LDR",
                "sensor 2 : Con. MIC",
                "sensor 3 : Humidity",
                "sensor 4 : PIR",
                "sensor 5 : Capacitive touch"};
const char *node1_data[] = {"Node ID = ",
                "Light Level(%) = ",
                "Sound Level (%)= ",
                "Humidity(RH%) = ",
                "Live(@_@) = ",
                "Touch = "};

const char *node2_sensor_name[] = {"Node Id",
                "sensor 1 : LM 35",
                "sensor 2 : MQ-9 GAS",
                "sensor 3 : BMP085",
                "sensor 4 : IR",
                "sensor 5 : Flex"};
const char *node2_data[] = {"Node ID = ",
                "Temperature(C) = ",
                "RS/R0 (ppm)= ",
                "Pressure (pa) = ",
                "Object = ",
                "Flex Mov. = "};

//uint8_t data[6];
int main()
{
/*char data[30];

ifstream infile;
infile.open("test.txt"); //this will open a file named test.txt
infile>>data;
*/
//if(data[3] == '1')
switch(arr0[0])
{
case(1):
    node1_recieved_data();
    break;
case(2):
    node2_recieved_data();
    break;
default:
    cout<<"invalid node id"<<endl;
}

return 0;
}

//void node1_recieved_data(char arra[])
void node1_recieved_data(void)
{
    int i,j;
    for(i = 0;i<6;i++)
    {
        cout<<endl<<*(node1_sensor_name+i)<<endl;
        cout<<endl<<*(node1_data+i);
        if(i == 5 || i == 4){
            if(arr0[i])
                cout<<YES<<endl;
            else
                cout<<NO<<endl;
        }
        else
            cout<<arr0[i]<<endl;
    }
}

void node2_recieved_data(void)
{
    int i,j;
    for(i = 0;i<6;i++)
    {
        cout<<endl<<*(node2_sensor_name+i)<<endl;
        cout<<endl<<*(node2_data+i);
        if(i == 4){
            if(arr0[i])
                cout<<YES<<endl;
            else
                cout<<NO<<endl;
        }
        else
            cout<<arr0[i]<<endl;
    }
}
