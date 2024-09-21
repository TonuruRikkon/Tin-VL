#include <bits/stdc++.h>
using namespace std;


void quaylui(vector<bool>&a,vector<int>gia,vector<int>yeu,int n,int T,int &tol,vector<bool>&ans,int yeu_tol, int &yeu_max){
    if(a.size()==n){
        tol=0;
        yeu_tol=0;
        for(int i;i<a.size();i++){
            if(a[i]==1){
                tol+=gia[i];
                yeu_tol+=yeu[i];
            }
        }
        if(tol<T&&yeu_max<=yeu_tol){
            yeu_max=yeu_tol;
            ans=a;
        }
    }

    else{
        for (int i = 0; i <= 1; i++)
        {
                a.push_back(i);
                quaylui(a,gia,yeu,n,T,tol,ans,0,yeu_max);
                a.pop_back();
        }

    }
}


int main(){
    int n,T,tol,yeu_max=0;
    cin>>n>>T;
    vector<bool> a,ans(n, false);
    vector<int>gia,yeu;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        gia.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        yeu.push_back(x);
    }
    quaylui(a,gia,yeu,n,T,tol,ans,0,yeu_max);
    cout<<yeu_max<<'[';
    for (int i = 0; i < n-1; i++)
    {
        cout<<ans[i]<<',';
    }
    cout<<ans[n-1];
    cout<<']';
}

