#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,b;
    cin>>n>>a>>b;
    long long lopkeo=n/(a+b);
    long long keocam=a*lopkeo,keodau=b*lopkeo;
    long long thua=n-lopkeo*(a+b);
    if(thua<=a){
        keocam+=thua;
    }
    else{
        keodau+=thua-a;
        keocam+=a;
    }
    cout<<keocam<<" "<<keodau;
}