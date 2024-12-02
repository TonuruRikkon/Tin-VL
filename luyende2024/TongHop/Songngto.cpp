#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7)+1,true);
vector<int> uoc(int(1e7)+1,1);

void sangnt()
{
    ngto.resize(int(1e7)+1,true);
    uoc.resize(int(1e7)+1,1);
    ngto[0]=ngto[1]=false;
    int p=2;
    while(p*p<=int(1e7))
    {
        uoc[p]=p+1;
        for (int i = 2; i <= int(1e7)/p; i++)
        {
            ngto[i*p]=false;
            int u=i*p;
            while (u>1)
            {
                uoc[i*p]+=u;
                u/=p;
            }
        }
        for(p++;p*p<=int(1e7)&&ngto[p]==false;p++);
    }
    
}

bool ngt(int s)
{
    for (int i = 2; i*i <= s; i++)
    {
        if(s%i==0) return false;
    }
    return true;
}

int main()
{
    sangnt();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b,ans=0;
        cin>>a>>b;
        for(int j=a;j<=b;j++){
            long long ref=uoc[j];
            if(ref<=int(1e7)){
                if(ngto[ref]==true){
                    cout<<j<<":"<<ref<<" ";
                    ans++;
                }
            }
            else{
                if(ngt(ref)==true){
                    ans++;
                }
            }
        }
        cout<<"\n";
        cout<<ans<<"\n";
    }
}