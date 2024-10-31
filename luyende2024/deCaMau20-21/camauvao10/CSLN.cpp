#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ans='0';
    string n;
    cin>>n;
    for(char x:n){
        if(x>ans) ans=x;
    }
    cout<<ans;
}