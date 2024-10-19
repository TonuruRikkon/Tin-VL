#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,m;
    cin>>n>>m;
    vector<int> hoa;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        hoa.push_back(x);
    }
    int i=1;
    while(i<n)
    {
        while(hoa[i]==hoa[i-1]||hoa[i]==hoa[i+1]){
            hoa.erase(hoa.begin()+i);
        }
        i++;
    }
    for(auto x:hoa){
        cout<<x<<" ";
    }
    
}