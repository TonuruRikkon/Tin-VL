#include <bits/stdc++.h>
using namespace std;

int n,k;
const int MAXINP=305;
vector<int> inp(MAXINP);
long long ref[MAXINP][MAXINP][MAXINP>>1];

long long FUNC(int l,int r,int k)
{
    long long &ans=ref[l][r][k];
    if(ans!=-1){
        return ans;
    }
    if(l<r){
        FUNC()
    }
}

int main()
{

    cin>>n>>k;
    for (int  i = 0; i < n; i++)
    {
        cin>>inp[i];   
    }
    
}