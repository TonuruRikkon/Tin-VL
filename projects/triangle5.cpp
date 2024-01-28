#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a*a+b*b==c*c)cout<<"vuong ";
    else if (a==b&&a==c) cout<<"deu";
    else if (a==b||a==c||b==c) cout<<"can ";
    else if (abs(a-b)<c&&a+b>c)cout<<"thuong";
    else cout<<"khong";
    return 0;
}
