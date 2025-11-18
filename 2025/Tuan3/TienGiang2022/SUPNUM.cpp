#include <bits/stdc++.h>
using namespace std;                                                                                                                                                                                                            

bool IsNto[int(1e6)+1];
vector<int> Nto;

void sangnt(){
    memset(IsNto,true,sizeof(IsNto));
    IsNto[0]=IsNto[1]=false;
    for (int i = 2; i*i <= int(1e6); i++)
    {
        if(IsNto[i]){
            Nto.push_back(i);
            for (int j = i*i; j <= int(1e6); j+=i)
            {
                IsNto[j]=false;
            }
            
        }

    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    sangnt();
    bool check=false;
    for (int i = 0; i < n; i++)
    {
        int in;
        scanf("%d",&in);
        int inp=in;
        long long ans=0;
        for(int ref:Nto){
            if(inp%ref==0) {
                ans+=ref;
                while (inp%ref==0)
                {
                    inp/=ref;
                }
                
            }
        }
        if(inp>1) ans+=inp;
        if(ans%5==0){
            printf("%d",in);
            printf("%c", ' ');
            check=true;
        }
    }
    if(check==false) printf("%d",-1);
}