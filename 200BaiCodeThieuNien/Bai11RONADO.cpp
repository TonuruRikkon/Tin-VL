#include <bits/stdc++.h>
using namespace std;

int main()
{
    int TC;
    cin>>TC;
    for (int i = 0; i < TC; i++)
    {
        int t,q,l;
        int dt=0,dq=0;
        cin>>t>>q>>l;
        while (l>1)
        {
            if(t%l==0) {
                t--;
                dt++;
            }
            else if(q%l==0) {
                q--;
                dq++;
            }
            else l--;
        }
        cout<<dt<<" "<<dq<<"\n";
    }
    
}