#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str,ans="";
    int d=1;
    cin>>str;
    cout<<str<<"!"<<str.size()<<endl;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==str[i+1]){
            d++;
            cout<<d<<endl;
        }
        else{
            if(d>1)ans+=to_string(d)+str[i];
            else if(d==1) ans+=str[i];
            d=1;
        }
    }
    cout<<ans;
}