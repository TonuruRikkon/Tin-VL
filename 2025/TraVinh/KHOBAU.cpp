#include <bits/stdc++.h>
using namespace std;

void tonguoc(vector<int> &sumUoc, int r){
    sumUoc[0]=sumUoc[1]=0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = i+i; j <= r; j+=i)
        {
            sumUoc[j]+=i;
        }
        
    }
        
}

int main()
{
    int l,r, ans=0;
    cin>>l>>r;
    vector<int> sumUoc(r+1,0);
    tonguoc(sumUoc,r);
    for (int i = l; i <= r; i++)
    {
        if(i<sumUoc[i]) ans++;
    }
    cout<<ans;
}