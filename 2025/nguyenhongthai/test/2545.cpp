#include <bits/stdc++.h>
using namespace std;

bool isSQR(long long a, long long b){
    if(sqrt(a*b)==int(sqrt(a*b))){
        return true;
    }
    return false;
}

int main()
{
    vector<int>inp;
    int n,d=0;
    cin>>n;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        bool tf=false;
        for(int j:inp){
            if(isSQR(j,x)==true){
                tf=true;
                inp.emplace_back(x);
                break;
            }
        }
        if(tf==false){
            inp.erase(inp.begin(),inp.end());
            inp.push_back(x);
            d++;
        }  
    }
    cout<<d;
}