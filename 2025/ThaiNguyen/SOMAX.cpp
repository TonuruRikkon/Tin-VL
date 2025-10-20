#include<bits/stdc++.h>
using namespace std;

int maxNext(int x, vector<int> &inp, int &n, vector<int> &ans, int &last){
    if(x==n-1) {
        last=x;
        ans[x]=-1;
        return -1;
    }
    else if(inp[x+1]>inp[x]) {
        last=x+1;
        return inp[x+1];
    }
    else if(inp[x+1]<=inp[x]) {
        int res=maxNext(x+1, inp, n, ans, last);
        ans[x+1]=res;
        return res;
    }
    else return -1;
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
    int last=0;
    vector<int> ans(n,0);
    for (int i = 0; i < n; i++)
    {
        i=last;
        ans[i]=maxNext(i,inp,n,ans,last);
        cout<<i<<' '<<ans[i]<<'\n';
    }
    for(int x:ans) cout<<x<<' ';
}