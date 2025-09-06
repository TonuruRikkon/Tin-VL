#include <bits/stdc++.h>
using namespace std;

struct id
{
    string M,L;
    int Y;
};

int main()
{
    int n;
    cin>>n;
    vector<id> inp;
    
    for (int i = 0; i < n; i++)
    {
        string MID,LAS;
        int YRS;cin.ignore();
        getline(cin,MID);
        getline(cin,LAS);
        cin>>YRS;
        inp.push_back({MID,LAS,YRS});
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<inp[i].M<<' '<<inp[i].L<<' '<<inp[i].Y<<'\n';
    }
    
    
}