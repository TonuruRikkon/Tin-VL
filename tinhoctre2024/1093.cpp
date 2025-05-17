#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> inp;
    int r;
    cin>>r;
    for (int i = 0; i < r; i++)
    {
        char x;
        cin>> x;
        inp.push_back(x);
    }
    int n;
    cin>>n;
    vector<vector<char>> opp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            char x;
            cin>>x;
            opp[i].push_back(x);
        }
    }
    int d=0,ans=0;
    for (int i = 0; i < r; i++)
    {
        vector<int> c(3,0);
        for (int j = 0; j < n; j++)
        {    
            if(opp[j][i]==inp[i]) {
                d++;
                if(inp[i]=='R') c[0]++;
                else if(inp[i]=='P') c[1]++;
                else if(inp[i]=='S') c[2]++;
            }
            else{
                if(opp[j][i]=='S'){
                    if(inp[i]=='S') d++;
                    else if(inp[i]=='R') d+=2;
                    c[2]++;
                }
                else if(opp[j][i]=='P'){
                    if(inp[i]=='P') d++;
                    else if(inp[i]=='S') d+=2;
                    c[1]++;
                }
                else if(opp[j][i]=='R'){
                    if(inp[i]=='R') d++;
                    else if(inp[i]=='P') d+=2;
                    c[0]++;
                }
            }
        }
        auto checking=max_element(c.begin(),c.end());
        if(checking-c.begin()+1!=3)
        ans+=*checking*2+c[checking-c.begin()+1];
        else ans+=*checking*2+c[0];
    }
    cout<<d<<'\n'<<ans;
}