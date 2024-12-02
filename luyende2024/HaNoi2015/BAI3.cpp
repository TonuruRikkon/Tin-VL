#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<int, unordered_map<int,vector<int>>> tunhien;
    unordered_map<int, unordered_map<int,vector<int>>> xahoi;
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        tunhien[z][y].push_back(x);
        xahoi[z][x].push_back(y);
    }
    
}