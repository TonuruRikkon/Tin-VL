#include <bits/stdc++.h>
using namespace std;

int t;
bool a[int(1e6)+1];
long long d[1000001];
void sangnguyento()
{
    memset(a,true,sizeof(a));
    a[1]=0;
    for (int i = 2; i < sqrt(int(1e6)); i++)
    {
        if(a[i]==true){
            for (int j = i*i; j <= int(1e6)+1; j+=i)
            {
                a[j] = false;
            }  
        }
    }
}

int main()
{
    sangnguyento();
    memset(d,0,sizeof(d));
    for (int i = 1; i <= int(1e6)+1; i++)
    {
        if(a[i]==true) d[i]=d[i-1]+1;
        else d[i]=d[i-1];
    }
    cin>>t;
    int R[t+1],L[t+1];
    for (int i = 1; i <= t; i++)
    {
        int x,y;
        cin>>x>>y;
        L[i]=x;
        R[i]=y;
    }
    for (int i = 1; i <= t; i++)
    {
        cout<<d[R[i]]-d[L[i]-1]<<endl;
    }
    
}