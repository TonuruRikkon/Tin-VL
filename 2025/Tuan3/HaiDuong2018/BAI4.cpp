#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int inp[n];
    long long tol[n+1];
    int mod[n+1];
    int pos[k];
    tol[0]=0;
    mod[0]=0;
    memset(pos,0,sizeof(pos));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inp[i]);
        tol[i+1]=tol[i]+inp[i];
        mod[i+1]=tol[i+1]%k;
        if(pos[mod[i+1]]==0){
            pos[mod[i+1]]=i+1;
        }
    }
    pos[0]=0;
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        ans=max(i-pos[mod[i]],ans);
    }
    printf("%d",ans);

}