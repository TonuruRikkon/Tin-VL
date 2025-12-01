#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int g,c,l;
    cin>>g>>c>>l;
    int minn=min({g,c,l}),maxx=max({g,c,l}),tol=g+c+l;
    if(maxx-minn>=10) cout<<"check again";
    else cout<<"final"<<' '<<tol-maxx-minn;
}