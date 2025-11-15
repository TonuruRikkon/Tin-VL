#include <bits/stdc++.h>
using namespace std;

string tong(string a,string b)
{
    string ans;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sz=max(a.size(),b.size());
    int asz=a.size();
    int bsz=b.size();
    int mem=0;
    for (int i = 0; i < sz; i++)
    {
        int ai=0,bi=0;
        if(i<asz) ai=a[i]-'0';
        if(i<bsz) bi=b[i]-'0';
        int tol=ai+bi+mem;
        if(tol<10) {
            ans.push_back(tol+'0');
            mem=0;
        }
        else{
            ans.push_back(tol%10+'0');
            mem=1;
        }
    }
    if(mem==1) ans.push_back('1');
    reverse(ans.begin(),ans.end());
    return ans;
    
}

string tru(string a,string b){
    string ans;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sz=max(a.size(),b.size());
    int asz=a.size();
    int bsz=b.size();
    int mem=0;
    for (int i = 0; i < sz; i++)
    {
        int ai=0,bi=0;
        if(i<asz) ai=a[i]-'0';
        if(i<bsz) bi=b[i]-'0';
        int neg=ai-(bi+mem);
        if(neg<0) mem=1;
        ans.push_back(abs(neg)+'0');
    } 
    reverse(ans.begin(),ans.end());
    return ans;
}

string div(string a, int b)
{
    string ans;
    int sz=a.size();
    int mem=0;
    if(a[0]-'0'<b) mem=(a[0]-'0')%10;
    else ans.push_back((a[0]-'0')/b+'0');
    for (int i = 1; i < sz; i++)
    {
        mem=mem*10+a[i]-'0';
        int res=mem/b;
        mem=mem%b;
        ans.push_back(res+'0');
    }
    return ans;
}

int main()
{
    string t,h;
    cin>>t>>h;
    string more,less;
    if(t.size()>h.size()){
        more=t;
        less=h;
    }
    if(t.size()==h.size()){
        more=max(t,h);
        less=min(t,h);
    }
    else{
        more=h;
        less=t;
    }
    cout<<div(tong(t,h),2)<<'\n'<<div(tru(more,less),2);
}