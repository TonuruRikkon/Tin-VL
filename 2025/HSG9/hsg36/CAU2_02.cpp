#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    
    vector<stack<int>> piles;
    for (int i = 0; i < n; i++)
    {
        if(piles.empty()==true){
            stack<int> temp;
            temp.push(inp[i]);
            piles.push_back(temp);
        }
        else{
            bool check=false;
            for(auto &x:piles){
                if(inp[i]<x.top()){
                    x.push(inp[i]);
                    check=true;cout<<'a';
                    break;

                }
            }
            if(check==false){
                stack<int> temp;
                temp.push(inp[i]);
                piles.push_back(temp);
            }
        }
    }

    cout<<piles.size();


}