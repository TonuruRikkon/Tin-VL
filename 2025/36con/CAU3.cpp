#include <bits/stdc++.h>
using namespace std;

bool check(map<char,int> ori, map<char,int> count, int tol)
{
    int left=0;
    for(auto x:ori){
        if(x.second-count[x.first]>0) left+=x.second-count[x.first];
    }
    if(count['*']==left) return true;
    else return false;
}

int main()
{
    int n,m,tol=0, ans=0;
    cin>>n>>m;
    string t,s;
    cin>>t>>s;
    map<char,int> ori,count;
    for (int i = 0; i < n ; i++)
    {
        ori[t[i]]++;
        count[s[i]]++;
        tol++;
    }
    if(check(ori,count,tol)) ans++;
    for(int i=n;i<m;i++){
        count[s[i-n]]--;
        count[s[i]]++;
        if(check(ori,count,tol)) ans++;
    }

    cout<<ans;
    

}