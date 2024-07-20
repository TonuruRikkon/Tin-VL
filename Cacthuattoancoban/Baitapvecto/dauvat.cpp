#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d1=0,d2=0;
    cin>>n;
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
        if(x>0) d1+=x;
        if(x<0) d2+=x;
    }
    if(d1+d2>0) cout<<"first"<<endl;
    else if(d1+d2<0) cout<<"second"<<endl;
    else if(d1+d2==0){
        if(c[n-1]>0) cout<<"first";
        else cout<<"second";
    }
}