#include <bits/stdc++.h>
using namespace std;

void coutstr(string s){
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i];
        this_thread::sleep_for(40ms);
    }
}

int main()
{
    string welcome="What is your birthday?";
    coutstr(welcome); cout<<"\n";
    
    string inp;
    getline(cin,inp);
    vector<int> date(3);
    int temp=0,i=0;
    for(char x:inp){
        if(x<'0'||x>'9') {
            if(temp!=0){
                date[i]=temp;
                i++;
            }   
            temp=0;
        }
        else temp=temp*10+int(x-'0');
    }
    date[2]=temp;

    int d=date[0],m=date[1],y=date[3];

    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    string checking="Checking the date...",today="Today is day ", month="month ", year="year ";
    coutstr(checking);cout<<"\n";
    this_thread::sleep_for(1s);
    coutstr(today);cout<< datetime.tm_mday<<", ";coutstr(month);cout<<datetime.tm_mon+1<<", ";coutstr(year);cout<<datetime.tm_year+1900;cout<<"\n";
    if(d==datetime.tm_mday&&m==datetime.tm_mon+1) {
        coutstr("This is your "); cout<< datetime.tm_year+1900-y<<"th "; coutstr("birth day."); cout<<"\n";
        coutstr("Happy birth day!"); cout<<"\n";
    }
    else{
        coutstr("Today is not your birthday, open this on your birthday.\nHave a nice day!"); cout<<"\n";
    }
    system("pause");
}