#include <bits/stdc++.h>
using namespace std;

bool IsNto[int(1e6)+1];
vector<int> Nto;
vector<int> DemU(int(1e6)+1,1);
vector<int> Mu(1e6+1);
vector<int> tol(int(1e6)+1);

void sangnt() {
    DemU[0]=0;
    DemU[1] = 1;      
    Mu[1] = 1;    
    
    for (int n = 2; n <= int(1e6); ++n) {
        if (Mu[n] == 0) {
            Nto.push_back(n);
            DemU[n] = 2;      
            Mu[n] = 2;    
        }
        
        for (int p : Nto) {
            if ((long long)n * p > int(1e6)) break;
            
            int m = n * p;
            
            if (n % p == 0) {
                Mu[m] = Mu[n] + 1; 
                DemU[m] = DemU[n] / Mu[n] * Mu[m];
                break; 
            } else {
                Mu[m] = 2;
                DemU[m] = 2 * DemU[n]; 
            }
        }
    }
    tol[0]=0;
    for (int i = 1; i <= int(1e6); i++)
    {
        if(i%3==0&&DemU[i]==9){
            tol[i]=tol[i-1]+1;
        }
        else tol[i]=tol[i-1];
    }
    
}

int main()
{
    int n;
    cin>>n;
    sangnt();
    for (int i = 0; i < n; i++)
    {
        if(i!=0) cout<<'\n';
        int x,y;
        cin>>x>>y;
        cout<<tol[y]-tol[x-1];
    }
    
}