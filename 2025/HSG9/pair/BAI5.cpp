#include <bits/stdc++.h>
using namespace std;

vector<int> tolU(int(1e6)+1,0),tol2(int(1e6)+1,0);

void tolUoc(){
    for (int i = 1; i <= int(1e6); i++)
    {
        for (int j = i; j <= sqrt(int(1e6)); j+=i)
        {
            tolU[j]+=i;
            if(int(1e6)/j!=j) tolU[int(1e6)/j]+=i;
        }
        
    }
    for (int i = 1; i <= int(1e6); i++)
    {
        if(tolU[i]%2==0) tol2[i]++;
        tol2[i]+=tol2[i-1];
    }
}

int main()
{
    tolUoc();
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<tol2[r]-tol2[l-1]<<'\n';
    }
    
}