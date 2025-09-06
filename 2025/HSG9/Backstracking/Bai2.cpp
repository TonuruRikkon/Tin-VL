#include <bits/stdc++.h>
using namespace std;

int tol=0;

void dequy(vector<bool>&used,vector<char>&RC,string inp)
{
    for (char i:inp)
    {
        if(used[i]==false){
            RC.push_back(i);
            used[i]=true;
            if(RC.size()==inp.size()){
                for(char out:RC) cout<<out;
                cout<<'\n';
                tol++;
            }
            else{
                dequy(used,RC,inp);
            }
            RC.pop_back();
            used[i]=false;
        }
    }
    
}

int main()
{
    string inp;
    cin>>inp;
    vector<bool> used(1000,false);
    vector<char>RC;
    dequy(used,RC,inp);
}