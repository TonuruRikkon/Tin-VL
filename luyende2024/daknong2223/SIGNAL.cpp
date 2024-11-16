#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    if(k<n){
        string temp=str.substr(n-k,k);
        str.erase(n-k,k);
        temp+=str;
        cout<<temp;
    }
    else if(k>=n){
        if(k%n==0){
            cout<<str;
        }
        else{
            int q=k%n;
            string temp=str.substr(n-q,q);
            str.erase(n-q,q);
            temp+=str;
            cout<<temp;
        }
    }
}