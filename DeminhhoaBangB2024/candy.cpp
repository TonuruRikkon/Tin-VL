#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,cam=0,dau=0,chuki,du;
    cin>>n>>a>>b;
    chuki=n/(a+b);
    du=n%(a+b);
    cam=chuki*a;
    if(du<=a){
        cam+=du;
    }
    else{
        cam+=a;
    }
    dau=n-cam;
    cout<<cam<<" "<<dau;
}