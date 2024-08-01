#include<bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    int ch=0;
    if(n==1||n==4) ch=1;
    for(int i=2; i<sqrt(n);i++){
        if(n%i==0){
            ch=1;
            break;
        }
    }
    if(ch==0) return 1;
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    vector<int> L;
    vector<int> R;
    vector<int> ans;
    for (int i = 0; i < t; i++)
    {
        int x,y;
        cin>>x>>y;
        L.push_back(x);
        R.push_back(y);
    }
    for (int i = 0; i < t; i++)
    {
        int x=0;
        for(int j = L[i]; i<=R[i]; i++){
            if(isPrime(j)==1) x++;
        }
        ans.push_back(x);
    }
    for (int i = 0; i < t; i++)
    {
        cout<<ans[i]<<endl;
    }
    
    
}