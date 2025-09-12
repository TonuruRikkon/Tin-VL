#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        vector<int> inp,outp;
        map<int,int> out_pos,inp_pos;
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            inp.push_back(x);
            inp_pos[x]=i;
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            outp.push_back(x);
            out_pos[x]=i;
        }
        
        
        vector<stack<int>> stacks;

        for(int x:outp){
            int pos=out_pos[x];
            bool ok=false;

            for(auto &y: stacks){
                // if(y.empty()==true){
                //     y.emplace(x);
                //     ok=true;
                //     break;
                // }
                // else{
                    int top_pos=out_pos[y.top()];
                    if(top_pos<pos){
                        y.emplace(x);
                        ok=true;
                        break;
                    }   
                // }
            }

            if(ok==false){
                stack<int> _new;
                _new.emplace(x);
                stacks.emplace_back(_new);
            }
        }
        cout<<stacks.size();
    }
    
}