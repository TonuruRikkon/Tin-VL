#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    string str;
    cin>>str;
    map<int,int> cnt;
    int temp=0,ans=0;
    cnt[0]=1;
    for(char x:str){
        temp+=x-'0';
        ans+=cnt[temp-k];
        cnt[temp]++;
    }
    cout<<ans;
}