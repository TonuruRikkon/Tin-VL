#include <bits/stdc++.h>
using namespace std;

bool sum(int n){
    long long ans=0;
    if(n%2==0) ans+=2;
    while (n%2==0)
    {
        n/=2;
    }
    for (int i = 3; i <= n; i+=2)
    {
        if(n%i==0){
            ans+=i;
            while(n%i==0){
                n/=i;
            }    
        }
    }
    if(n>1)ans+=n;
    if(ans%5==0) return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    bool check=false;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(sum(x)) {
            if(i==0) printf("%d", x);
            printf(" %d", x);
            check=true;
        }
    }
    if(check==false) printf("%d",-1);
}