#include <bits/stdc++.h>
using namespace std;

vector<int> x;
vector<bool> used(int(1e9),false);
int n;
void permutation(int i){
    for (int v = 0; v < n; v++)
    {
        if(used[v]==false){
            x.push_back(v);
            used[v]=true;
            if(x.size()==n){
                for(int a:x) cout<<a<<' ';
                cout<<'\n';
            }
            else {
                permutation(i+1);
            }
            x.pop_back();
            used[v]=false;
        }
    }
}

int main()
{
    cin>>n;
    permutation(0);
}