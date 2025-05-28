#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long L,R, st=0,ed=0;
    cin >> L >> R;
    st=ceil(sqrt(L));
    ed=sqrt(R);
    cout<<ed-st+1;
}