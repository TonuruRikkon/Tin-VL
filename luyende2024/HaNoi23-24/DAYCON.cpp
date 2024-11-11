#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto;

void sangnt()
{
    ngto.resize(int(1e7),true);
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<int(1e7))
    {
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<int(1e7)&&ngto[p]==false;p++);
    }
    
}

int main()
{
    sangnt();
    int n,s=0,e=0;
    cin>>n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(ngto[x]==true){
            if(s==0) s=i;
            else if(s!=0){
                ans.push_back(i-s+1);
                s=i;
            }
        }
    }
    if(ans.empty()==false) cout<<*min_element(ans.begin(),ans.end());
    else cout<<-1;
}