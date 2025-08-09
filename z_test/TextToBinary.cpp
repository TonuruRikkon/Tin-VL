#include <bits/stdc++.h>
using namespace std;

string TextToBi(char a)
{
    string ans="";
    int anhxa[8]={128,64,32,16,8,4,2,1};
    for (int i = 0; i < 8; i++)
    {
        if(a>=anhxa[i]){
            ans+='1';
            a-=anhxa[i];
        }
        else ans+='0';
    }
    return ans;
}

int main()
{
    string str;
    cin>>str;
    for (int i = 0; i < str.size(); i++)
    {
        cout<<TextToBi(str[i])<<' ';
    }
    
}