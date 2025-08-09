#include <bits/stdc++.h>
using namespace std;
    
char numb[8]={'I','V','X','L','C','D','M'};
int val[8]={1,5,10,50,100,500,1000};
int anhxa['Z'];

int ktra(string str,int i){
    int ans=val[anhxa[str[i]]];
    if(i!=0)
    {
        if(str[i]!='I'){
            if(val[anhxa[str[i]]]>val[anhxa[str[i-1]]]){
                ans-=val[anhxa[str[i-1]]]*2;
            }
        }
    }
    return ans;
}

int main()
{
    memset(anhxa,-1,sizeof(anhxa));
    anhxa['I']=0;anhxa['V']=1;anhxa['X']=2;anhxa['L']=3;anhxa['C']=4;anhxa['D'];anhxa['M']=6;
    string str;
    cin>>str;
    int ans=0;
    for (int i = 0; i < str.size(); i++)
    {
        ans+=ktra(str,i);
    }
    cout<<ans;
}