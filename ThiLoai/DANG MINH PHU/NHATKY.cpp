#include <bits/stdc++.h> 
using namespace std;

int main()
{
    freopen("NHATKY.INP","r",stdin);
    freopen("NHATKY.OUT","w",stdout);
    long long s,ans=0,temp=0;
    int n,am=0;
    cin>>n;
    cin.ignore();
    string str;
    getline(cin,str);
    cin>>s;
    map<int,int> a;
    for(char x:str){
        if(x=='-') am=1;
        else if(x>='0'&&x<='9'){
            temp=temp*10+(x-'0');
        }
        else{
            if(am==1&&temp!=0) a[0-temp]++;
            else if(am==0&&temp!=0) a[temp]++;
            temp=0;
            am=0;
        }
    }
    if(am==1&&temp!=0) a[0-temp]++;
    else if(am==0&&temp!=0) a[temp]++;
    temp=0;
    am=0;
    for(auto x:a){
        if(s-x.first==x.first){
            ans+=a[x.first]/2;
            a[x.first]=0;
        }
        else{
            ans+=a[s-x.first]*a[x.first];
            a[s-x.first]=0;
            a[x.first]=0;
        }
    }
    cout<<ans;
}