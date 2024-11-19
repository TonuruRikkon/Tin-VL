#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e7)];
vector<int> ngt;

void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<int(1e7))
    {
        ngt.push_back(p);
        for (int i = 2; i*i < int(1e7); i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<int(1e7)&&ngto[p]==false;p++);
    }
}

int main()
{
    sangnt();
    int t;
    cin>>t;
    vector<long long> ans;
    for (int i = 0; i < t; i++)
    {
        long long outp=1;
        int x;
        cin>>x;
        ans.erase(ans.begin(),ans.end());
        for(int v:ngt){
            long long u=v;
            if(v>x) break;
            else{
                int d=0;
                long long num=1,tol=1;
                while(u<=x){
                    d+=x/u;
                    u*=u;
                }
                for (int i = 1; i <= d; i++)
                {
                    num*=v;
                    tol+=num;
                }
                ans.push_back(tol);
            }
        }
        for(long long x:ans){
            outp*=x;
        }
        cout<<outp<<endl;
    }

    
}