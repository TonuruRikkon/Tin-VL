#include <bits/stdc++.h>
using namespace std;

int main()
{
    int long long n;
    cin>>n;
    vector<string> acc;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        acc.push_back(x);
    }
        sort(acc.begin(),acc.end());    
    for(int i=1;i<n;i++){
        auto it = lower_bound(acc.begin(),acc.end(),acc[i]);
        if(distance(acc.begin(),it)!=i){
            string x = acc[i-1];
            if(x[x.length()-1]>='0'&&x[x.length()-1]<='8'){
                x[x.length()-1]+=1;
            }
            else if(x[x.length()-1]=='9'){
                x[x.length()-1]='0';
                x+="0";
            }
            else{
                x+="1";
            }
            acc.erase(acc.begin()+i);
            acc.insert(acc.begin()+i,x);
        }
    }
    for(string i:acc)cout<<i<<endl;
}