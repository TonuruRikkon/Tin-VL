#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,n;
    cin>>s>>n;
    int tempn=n;
    string str="";
    while (tempn>0)
    {
        str=char(tempn%10+'0')+str;
        tempn/=10;
    }
    
    if(s<=str.size()){
        cout<<n;
        return 0;
    }

    int sz=str.size();

    long long rem=0;

    for (int i = sz; i < s-sz; i++)
    {
        if(i==sz){
            long long temp=1;

            for (int i = 0; i < sz; i++)
            {
                temp*=10;
            }

            rem=temp%n;
            continue;
        }
        
        int temp=rem;
        temp*=10;
        rem=temp%n;
    }
    string strrem="";
    long long temprem=n-rem;
    while (temprem>0)
    {
        strrem=char(temprem%10+'0')+strrem;
        temprem/=10;
    }
    for (int i = 0; i < s-strrem.size(); i++)
    {
        if(i==0) cout<<1;
        else cout<<0;
    }
    cout<<n-rem;
    
    
}