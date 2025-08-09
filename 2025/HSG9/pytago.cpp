#include <bits/stdc++.h>
using namespace std;

int to_int(string str){
    int ans=0;
    for (int i = 0; i < str.size(); i++)
    {
        ans*=10;
        ans+=str[i]-'0';
    }
    return ans;
}

long long check(int a,int b,int c){
    long long max_=max(a,max(b,c));
    long long min_=min(a,min(b,c));
    long long mid_=(a+b+c)-(max_+min_);
    if(min_*min_+mid_*mid_==max_*max_)
    return sqrt(min_*min_+mid_*mid_);
    return 0;
}

int main()
{
    string inp,a="",b="",c="";long long ans=0;
    cin>>inp;
    for (int i = 1; i < inp.size(); i++)
    {
        for (int j = i+1; j < inp.size(); j++)
        {
            a=inp.substr(0,i);
            b=inp.substr(i,j-i);
            c=inp.substr(j,inp.size()-j);
            long long temp=check(to_int(a),to_int(b),to_int(c));
            ans=max(ans,temp);
        }
        
    }
    cout<<ans;
}