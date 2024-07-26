#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> d;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            while (n%i==0)
            {
                d.push_back(i);
                n/=i;
            }
            
        }
        
    }
    
    sort(d.begin(),d.end());
    for (int i = 0; i < d.size()-1; i++)
    {
        cout<<d[i]<<" x ";
    }
    cout<<d[d.size()-1];
}