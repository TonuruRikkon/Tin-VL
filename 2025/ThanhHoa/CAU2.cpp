#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> inp;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.emplace_back(x);
    }
    int d=0;
    while(true){
        d++;
        int ref=0,size=inp.size();
        if(size<=1) break;
        for (int i = 0; i < size; i++)
        {
            if(inp[i]>ref){
                ref=inp[i];
                inp.erase(inp.begin()+i);
                i--;size--;
            }
        }
        
    }
    cout<<d;
}