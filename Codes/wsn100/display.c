
#include<LiquidCrystal.h>

#define YES "DETECTED"
#define NO  "NOT-DETECTED"

LiquidCrystal lcd(7,6,5,4,3,2);

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


void init_lcd()
{
    lcd.begin(20,4);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   SIGMA TRAINERS  ");
    lcd.setCursor(0,1);
    lcd.print("         &         ");
    lcd.setCursor(0,2);
    lcd.print("        KITS       ");
    lcd.setCursor(0,3);
    lcd.print("       WSN100L     ");
    delay(2000);
    lcd.clear();
}


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

