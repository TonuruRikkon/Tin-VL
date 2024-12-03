#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool posible=false;
    int n,m,y;
    cin>>n>>m>>y;
    int po=n%(m-1);
    int ref=y%m;
    for (int i = 0; i < m; i++)
    {
        int pnt=i%m;
        int num=powl(pnt,po);
        if(num%m==ref) {
            cout<<i<<" ";
            posible=true;
        }
    }
    if(posible==false) cout<<-1;
}