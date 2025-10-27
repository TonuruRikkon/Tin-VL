#include <bits/stdc++.h>
using namespace std;


void sangnt(vector<bool> &ngto,vector<int> &nt)
{
    ngto[0]=ngto[1]=false;
    for (int i = 1; i*i <= int(1e6); i++)
    {
        if(ngto[i]==true){
            nt.push_back(i);
            for (int j = i*i; j <= int(1e6); j+=i)
            {
                ngto[j]=false;
            }            
        }
    }
}

int main()
{

    int n,d=0;
    cin>>n;
    vector<bool> ngto(int(1e7),true);
    vector<int> nt;
    sangnt(ngto,nt);

    for (int i = 1; i <= n; i++)
    {
        if(ngto[i+2]==true){
            int pos1= upper_bound(nt.begin(),nt.end(),i+2*n)-nt.begin();
            int pos2= lower_bound(nt.begin(),nt.end(),i+2)-nt.begin();
            d+=pos1-pos2;
        }
    }
    cout<<d;
    
}