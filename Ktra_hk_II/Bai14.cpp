#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n[256],x,ans=0;
    memset (n,0,sizeof(n));
    char chr[1000];
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++){
            n[str[i]]++;
        }
    for(char i = 'a'; i<='z';i++){
        if(n[i]!= 0){
            ans++;
        }   
    }
    x = max_element(n,n+0+256)-n;
    cout<<ans<<" "<<char(x)<<":"<<n[x]<<endl;
}