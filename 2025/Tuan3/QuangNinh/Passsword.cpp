#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int sz=str.size();
    vector<int> dpa(sz+1,0),dpA(sz+1,0),dp0(sz+1,0);
    
    for (int i = 0; i < sz ; i++)
    {
        dpa[i+1]=dpa[i];dpA[i+1]=dpA[i];dp0[i+1]=dp0[i];
        if(islower(str[i])){
            dpa[i+1]++;
        }
        else if(isupper(str[i])){
            dpA[i+1]++;
        }
        else if(isdigit(str[i])){
            dp0[i+1]++;
        }
        
    }
    
    int last=max({upper_bound(dpA.begin(),dpA.end(),0)-dpA.begin(),upper_bound(dpa.begin(),dpa.end(),0)-dpa.begin(),upper_bound(dp0.begin(),dp0.end(),0)-dp0.begin()});
    int ans=0;
    if(last>sz){
        cout<<0;
        return 0;
    }
    last--;
    for (int l = 0; l < sz-5; ++l)
    {
        int r=l+5;
        if(r<last) r=last;
        if(dpa[r+1]-dpa[l]==0||dpA[r+1]-dpA[l]==0||dp0[r+1]-dp0[l]==0) continue;
        if(r>=sz) {
            break;
        }
        ans+=sz-r;
    }
    cout<<ans;
    

}