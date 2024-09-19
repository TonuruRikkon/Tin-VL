#include<bits/stdc++.h>
using namespace std;



void lietke(int n, vector<int>&a,vector<bool> used) {
    if(a.size()==n){
        int d=0;
        for(int x:a){
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
                lietke(n,a,used);
                a.pop_back();
                used[i]=false;
            }
        }
        
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> a;
    vector<bool> used(n, false);
    lietke(n, a,used);
}