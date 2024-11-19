#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ucln=1;
    double tol=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        tol+=double(x)/double(y);
        ucln*=y;
    }
    if(tol<1){
        if(int(tol)%(ucln%int(tol*ucln))==0) cout<<(tol*ucln)/(ucln%int(tol*ucln))<<" "<<ucln/(ucln%int(tol*ucln));
        else cout<<tol*ucln<<" "<<ucln;
    }
    else if(tol==int(tol)){
        cout<<tol;
    }
    else{
        cout<<int(tol)<<" "<<int(tol*ucln)%ucln<<" "<<ucln;
    }
}