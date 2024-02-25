#include <bits/stdc++.h>
using namespace std;

int kiemso(int n)
{
    int s=0;
    while(n!=0){
        if(n%10!=6&&n%10!=8){
            s=1;
            break;
        }
        n=n/10;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    /*cout<<n%10<<" "<<kiemso(n)<<endl;*/
    if(kiemso(n)==0) cout<<"YES";
    else cout<<"NO";
}