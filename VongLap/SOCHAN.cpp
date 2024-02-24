#include <bits/stdc++.h>
using namespace std;

int main()
{
    int_fast64_t n,i=1,i_2=1,d=0;
    cin>>n;
    while(i<n){
        if(i%2==0&&i%3==0) d++;
        i++;
    }
    cout<<d<<endl;
    while (i_2<n)
    {
        if(i_2%2==0&&i_2%3==0) cout<<i_2<<" ";
        i_2++;
    }
    return 0;
}