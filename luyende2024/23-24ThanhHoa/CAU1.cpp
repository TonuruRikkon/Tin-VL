#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s=0,hoi,ans=-1;
    string str;
    cin>>str;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]!='?') s+=(i+1)*(str[i]-'0');
        else if(str[i]=='?') hoi=i+1;
    }
    if(hoi==1){
        for (int i = 1; i <= 9; i++)
        {
            if((s+(i*(hoi)))%7==0){
                ans=i;
                break;
            }
        }
    }
    else{
        for (int i = 0; i <= 9; i++)
        {
            if((s+(i*(hoi)))%7==0){
                ans=i;
                break;
            }
        }
    }
    cout<<ans;
    
    
}