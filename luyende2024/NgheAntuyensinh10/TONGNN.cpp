#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    if(n%m!=0){
        cout<<-1;
        return 0;
    }
    int p=n/m;
    vector<int> uoc,ans;
    for (int i = 1; i*i < p; i++)
    {
        if(p%i==0){
            if(i==p/i) uoc.push_back(i);
            else {
                uoc.push_back(i);
                uoc.push_back(p/i);
            }
        }
    }
    for(int x:uoc){
        ans.push_back((n/x)+(m*x));
    }
    cout<<*min_element(ans.begin(),ans.end());
}