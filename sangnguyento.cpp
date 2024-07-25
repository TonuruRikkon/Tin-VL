#include <bits/stdc++.h>
using namespace std;

int t,L,R;
bool a[int(1e6)+1];
long long d[1000001];
void sangnguyento()
{
    memset(a,true,sizeof(a));
    a[1]=0;
    for (int i = 2; i < sqrt(int(1e6)); i++)
    {
        if(a[i]==true){
            for (int j = i*i; j <= int(1e6)+1; j+=1)
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
    for (int i = 1; i <= t; i++)
    {
        cin>>L>>R;
        cout<<d[R]-d[L-1]<<endl;
    }
    
}