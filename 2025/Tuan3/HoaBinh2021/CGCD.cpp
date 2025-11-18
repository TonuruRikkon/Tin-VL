    #include <bits/stdc++.h>
    using namespace std;

    bool IsNto[int(1e5)+1];
    vector<int> Nto;
    long long MOD=int(1e9)+7;

    void sangnt()
    {
        memset(IsNto, true, sizeof(IsNto));
        IsNto[0]=IsNto[1]=false;
        for (int i = 2; i*i <= int(1e5); i++)
        {
            if(IsNto[i]){
                Nto.push_back(i);
                for (int j = i*i; j < int(1e5); j+=i)
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
        int a[int(1e5)+1];
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++)
        {
            int inp;
            scanf("%d", &inp);
            for(int ref:Nto){
                if(ref>inp) break;
                while (inp%ref==0){
                    a[ref]++;
                    inp/=ref;
                }
            }
        }
        int m;
        scanf("%d",&m);
        int b[int(1e5)+1];
        memset(b,0,sizeof(b));
        for (int i = 0; i < m; i++)
        {
            int inp;
            scanf("%d", &inp);
            for(int ref:Nto){
                if(ref>inp) break;
                while(inp%ref==0){
                    b[ref]++;
                    inp/=ref;
                }
            }
        }
        long long ans=1;
        for (int i = 0; i <= int(1e5); i++)
        {
            if(a[i]>0&&b[i]>0){
                long long temp=1;
                if(a[i]>b[i]){
                    for (int j = 0; j < b[i]; j++)
                    {
                        temp*=i;
                    }
                    ans*=temp%MOD;
                }
                else{
                    for (int j = 0; j < a[i]; j++)
                    {
                        temp*=i;
                    }
                    ans*=temp%MOD;
                }
            }
        }
        cout<<ans%MOD;
        
    }