#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    bool is_ten=false;
    long long tol=0;
    string n;
    cin>>n;
    for(char x:n){
        tol+=x-'0';
        if(x=='0') is_ten=true;
    }
    if(tol%3==0&&is_ten==true){
        sort(n.begin(),n.end(),cmp);
        cout<<n;
    }
    else cout<<-1;
}