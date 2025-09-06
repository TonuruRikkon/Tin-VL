#include<bits/stdc++.h>
using namespace std;

bool cmp(stats a, stats b){
    
}

struct stats{
    int c,p,a;
};

int main()
{
    int n;
    cin>>n;
    vector<stats> inp;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        inp.push_back({x,y,y/x});
    }
    
}