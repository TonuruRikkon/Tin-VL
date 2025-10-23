#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin>>str;
    str.push_back('.');
    vector<int> temp;
    long long ans=0;
    for(char x:str){
        if(x>='0'&&x<='9'){
            temp.push_back(x-'0');
        }
        else{
            long long num=0;
            for(long long x:temp){
                num=num*10+x;
            }
            temp.erase(temp.begin(),temp.end());
            ans+=num;
        }
    }
    cout<<ans;
}