#include <bits/stdc++.h>
using namespace std;

void quaylui(vector<int> gia,vector<int> yeu, int T, int &ans, int n,int vitri,int tong_gia,int yeu_ans)
{
    if(ans<yeu_ans){
        ans=yeu_ans;
    }
    else
    {
        for (int i = vitri; i < n; i++)
        {
            if(tong_gia+gia[i]<=T){
                tong_gia+=gia[i];
                yeu_ans+=yeu[i];
                vitri=i;
                quaylui(gia,yeu,T,ans,n,vitri,tong_gia,yeu_ans);
                tong_gia-=gia[i];
                yeu_ans-=yeu[i];
                }
        }
    }
    
}

int main()
{
    int n;
    int T,vitri;//bien gia tri
    int ans=0,ans_yeu=0,tong_gia=0; //bien tong
    vector<int>gia,yeu;
    cin>>n>>T;
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
    quaylui(gia,yeu,T,ans,n,vitri,tong_gia,ans_yeu);
    cout<<ans;
}