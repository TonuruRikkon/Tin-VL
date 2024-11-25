#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool am=false,zero=false;
    for (int i = 0; i < 4; i++)
    {
        double x;
        cin>>x;
        if(x<0&&am==false) am=true;
        else if(x<0&&am==true) am=false;
        else if(x==0.0){
            zero=true;
        }
    }
    if(zero==true) cout<<0;
    else if(am==true) cout<<-1;
    else if(am==false) cout<<1;

}