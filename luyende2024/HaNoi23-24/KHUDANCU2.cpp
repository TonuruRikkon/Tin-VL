#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> posM,posP;
    int m,n,d,k,ans=0;
    cin>>m>>n>>d>>k;

    char x[m+1][n+1];
    int Ox[8]={0,1,1,1,0,-1,-1,-1},Oy[8]={1,1,0,-1,-1,-1,0,1};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>x[i][j];
            if(x[i][j]=='M') posM.push_back({j,i});
            else if(x[i][j]=='P') posP.push_back({j,i});
        }    
    }
    for (int i = 0; i < posP.size(); i++)
    {
        int count=0;
        for (int j = 0; j < posM.size(); j++)
        {
            int x1=posP[i].first,x2=posM[j].first,y1=posP[i].second,y2=posM[j].second;
            if(x1>=(x2-d)&&x1<=(x2+d)){
                if(y1>=(y2-d)&&y1<=(y2+d)){
                    count++;
                    if(count>=k){
                        ans++;
                        break;
                    }
                }
            }
        }
    }    
    cout<<ans;
}