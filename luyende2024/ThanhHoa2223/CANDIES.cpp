#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0,tol=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(x%3==0&&x!=0){
            d++;
            tol+=(x-3)/3;
        }
    }
    cout<<d<<endl<<tol;
}