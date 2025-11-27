#include <bits/stdc++.h>
using namespace std;

double vol(double r, double h)
{
    return M_PI*r*r*h;
}

int main()
{
    int n;
    cin>>n;
    double maxx=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        double temp;
        double r,h;
        cin>>r>>h;
        temp=vol(r,h);
        if(maxx<temp){
            ans+=temp;
            maxx=temp;
        }
    }
    cout<<setprecision(3)<<fixed<<ans;
}