#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i_t = 0; i_t < t; i_t++)
    {
        int n,tol=0,ans=0;
        cin>>n;
        vector<int> inp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            inp.push_back(x);
        }
        tol=*max_element(inp.begin(),inp.end());
        // if(n==1) {
        //     cout<<1;
        //     continue;
        // }
        while (true)
        {
            int minn=*min_element(inp.begin(),inp.end()), min_e=INT_MAX;
            bool check=true;
                   
            ans++;
            for(int &x:inp){
                x-=minn;
                if(x<min_e&&x!=0) min_e=x;
            }

            for(int x:inp) if(x!=0) check=false;
            if(check == true) {
                cout<<"error"<<'\n';
                break;
            }     

            for(int &x:inp){
                if(x==0) {
                    x=min_e;
                    ans++;
                }
            }
            
            for(int x:inp) if(x!=0) check=false;
            if(check == true) {
                cout<<"error"<<'\n';
                break;
            }     

        }
        cout<<ans;
        if(i_t!=t-1) cout<<'\n';
    }
    
}