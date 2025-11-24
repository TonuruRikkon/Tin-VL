#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,d,k;
    cin>>m>>n>>d>>k;
    vector<vector<char>> inp(n,vector<char>(m));
    vector<pair<int,int>> posP,posM;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>inp[i][j];
            if(inp[i][j]=='P'){
                posP.push_back({i,j});
            }
            else if(inp[i][j]=='M'){
                posM.push_back({i,j});
            }
        }
    }
    int ans=0;
    for(auto P:posP){
        int temp=0;
        int Px=P.second;
        int Py=P.first;
        for(auto M:posM){
            int Mx=M.second;
            int My=M.first;
            if(abs(Mx-Px)<=d&&abs(My-Py)<=d){
                temp++;
            }
        }
        if(temp>=k) ans++;
    }
    cout<<ans;
}