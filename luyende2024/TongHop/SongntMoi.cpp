#include <bits/stdc++.h>
using namespace std;

vector<int> tongu(int(1e6)+1,0);
vector<int> sluoc(int(1e6)+1,0);

void tonguoc()
{
    fill(tongu.begin(),tongu.end(),0);
    for (int i = 1; i*i <= int(1e6); i++)
    {
        for (int j = i; j <= int(1e6); j+=i)
        {
            tongu[j]++;
        }
        
    }
    
}

void dem()
{
    for(int i=1;i<=tongu.size();i++){
        if(tongu[tongu[i]]==2){
            sluoc[i]=sluoc[i-1]+1;
        }
        else{
            sluoc[i]=sluoc[i-1];
        }
    }
}

int main()
{
    tonguoc();
    dem();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<sluoc[b]-sluoc[a-1]<<"\n";
    }
    
}