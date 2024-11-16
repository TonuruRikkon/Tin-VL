#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,maxx=0,minn=0,d=0;
    cin>>n;
    vector<int> inp;
    vector<int> max_h,min_h;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(x>maxx){
            maxx=x;
        }
        else{
            minn=x;
        }
        inp.push_back(x);
        max_h.push_back(maxx);
        min_h.push_back(minn);
    }
    int ref_rise=0,ref_des=0;
    for (int i = 0; i < n; i++)
    {
        if(ref_rise!=max_h[i]){
            ref_rise=max_h[i];
            d++;
        }
        
    }
    cout<<d;
    
}