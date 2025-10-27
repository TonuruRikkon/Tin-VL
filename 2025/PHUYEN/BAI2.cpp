#include <bits/stdc++.h>
using namespace std;


int checknp(int a,int b)
{
    int n=a^b,d=0;
    while (n>0)
    {
        n&=(n-1);
        d++;
    }
    return d;
}

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int temp=checknp(inp[i],inp[j]);
            if(ans>temp)ans=temp;
        }
        
    }
    
    cout<<ans;
    
    

}