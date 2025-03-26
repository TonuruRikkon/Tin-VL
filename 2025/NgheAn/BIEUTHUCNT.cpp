#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(4e6));

void sangnt()
{
    fill(ngto.begin(),ngto.end(),true);
    ngto[0]=ngto[1]=false;
    for (int i = 1; i*i < ngto.size(); i++)
    {
        if(ngto[i]==true){
            for (int j = i*i; j < ngto.size(); j+=i)
            {
                ngto[j]=false;
            }            
        }
    }
}

int main()
{
    sangnt();
    int n,d=1;
    cin>>n;
    for (int i = 1; i <= n; i+=2)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j) continue;
            else if(ngto[i+j*2]==true) d++;
        }
        
    }
    cout<<d;
    
}