#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    int k;
    cin>>k;
    vector<int> tol;
    tol.push_back(0);
    for(int x:inp){
        bool check=true;
        for(int y:tol){
            if(y+x<=k){
                y+=x;
                check=false;
                break;
            }
        }
        if(check==true) tol.push_back(0);
    }
    cout<<tol.size();
}