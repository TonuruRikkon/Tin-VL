#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,n1,n2,n3,n4;
    cin>>n;
    n1 = n/1000;
    n2 = n/100 - n1*10;
    n3 = n/10 - (n1*100+n2*10);
    n4 = n - (n1*1000+n2*100+n3*10);
    if(n1+n2 == n3+n4) cout<< "yes";
        else cout<<"no";
    return 0;
}
