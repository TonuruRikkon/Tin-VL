#include <bits/stdc++.h>
using namespace std;

int ans=0;
bool a[int(1e6)+1];

void sangnguyento()
{
    memset(a,true,sizeof(a));
    a[1]=0;
    for (int i = 2; i <= sqrt(int(1e6)); i++)
    {
        if(a[i]==true){
            for (int j = i*i; j <= int(1e6); j+=i)
            {
                a[j]=false;
            }
        }
    }
}
bool sodep(int n)
{
   while (n>1 )
   {
    if(n%10==3||n%10==5||n%10==7){
        return false;
    }
    n/=10;
   }
   return true;
}
int main()
{
    sangnguyento();
    int n;
    cin>>n;
    for (int i = 2; i < n; i++)
    {
        if(a[i]==1&&sodep(i)) ans++; 
    }
    cout<<ans;

}