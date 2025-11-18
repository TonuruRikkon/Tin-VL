#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        vector<long long> temp(3);
        for (int j = 0; j < 3; j++)
        {
            cin>>temp[j];
        }        
        sort(temp.begin(),temp.end());
        if(temp[1]-temp[0]>=1) temp[0]++;
        if(temp[2]-temp[1]>=1) temp[2]--;
        cout<<temp[1]-temp[0]+temp[2]-temp[1]+temp[2]-temp[0];
        if(i!=q-1) cout<<'\n';
    }
    
}