#include <bits/stdc++.h>
using namespace std;

int t,L,R;
bool a[int(1e6)+1];
long long d[1000001];
void sangnguyento()
{
    memset(a,true,sizeof(a));
    a[1]=0;
    for (int i = 2; i <= sqrt(int(1e6)); i++)
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
    int n=100;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}