#include<bits/stdc++.h>
using namespace std;

int main()
{
    int_fast64_t n,ch=0;
    cin>>n;
    if(n==1||n==4) ch=1;
    for(int i=2; i<sqrt(n);i++){
        if(n%i==0){
            ch=1;
            break;
        }
    }
    if(ch==0) cout<<"YES";
    else cout<<"NO";
}