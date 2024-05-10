#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0,y=0,dem[1000],res=0;
    cin>>n;
    double a[1000];
    string s[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string x="",result="";
    for(int i=0;i<n;i++){
        if(a[i]>0){
            x+=to_string(a[i])+',';
            d++;
        }
        else{
            s[y]=x;
            dem[y]=d;
            y++;
            x="";
            d=0;
        }
    }
    if(a[n-1]>0){
        s[y]=x;
        dem[y]=d;
    }
    for(int i=0;i<=y;i++){
        if(dem[i]==*max_element(dem,dem+y)){
            res++;
            result+=s[i]+"\n";
        }
    }
    cout<<res<<endl<<result;
}