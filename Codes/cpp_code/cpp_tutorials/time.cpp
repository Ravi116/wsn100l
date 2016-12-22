        /*          Example of time lib         */
//need little work on this topic for

#include<iostream>
#include<ctime>
using namespace std;

int main(void)
{
    const char *weekdays[] = {"sunday","Monday","tuesday","wednesday","thursday","friday","saturday"};

    time_t now = time(0);
    cout<<now<<endl;            //No. of seconds since january 1,1970
    char *dt = ctime(&now);

    cout<<dt<<endl;             //convert now to string form

    tm *gmtm = gmtime(&now);            //gmt time
    dt = asctime(gmtm);                 //utc time
    cout<<dt<<endl;

    tm *ltm = localtime(&now);
    cout<<"year: "<<1900+ltm->tm_year<<endl;            //year
    cout<<"month: "<<1+ltm->tm_mon<<endl;               //month
    cout<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;       //hour:minute:seconds
    cout<<ltm->tm_wday<<'\t'<<ltm->tm_yday<<endl;                        //week day:year day
    cout<<"today is "<<*(weekdays+ltm->tm_wday)<<endl;                                 //name of week day
    cout<<"Tommorow is "<<*(weekdays + ltm->tm_wday + 1)<<endl;
    return 0;
}
