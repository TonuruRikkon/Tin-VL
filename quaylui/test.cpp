#include <bits/stdc++.h>
using namespace std;


void quaylui(vector<int>&a,vector<bool>used,int n){
    if(a.size()==n){
        for (int x:a)
        {
            cout<<x<<" ";
        }
        cout<<endl;
            }
    else{
        for (int i = 0; i < n; i++)
        {
            if(used[i]==false){
                a.push_back(i);
                used[i]=true;
                quaylui(a,used,n);
                a.pop_back();
                used[i]=false;
            }
        }

    }
}


int main(){
    int n;
    cin>>n;
    vector<bool> used(n,false);
    vector<int> a;
    quaylui(a,used,n);
}
