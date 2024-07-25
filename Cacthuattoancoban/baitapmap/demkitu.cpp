#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,count=1,pos=0;
    string stri;
    cin>>n>>k;
    vector<char> str;
    vector<int> v;
    vector<char> c;
    cin>>stri;
    for (int i = 0; i < n; i++)
    {
        str.push_back(stri[i]);
    }
    
    sort(str.begin(),str.end());
    char ref=str[0];
    for (int i=0; i<n; i++)
    {
        if(ref==str[i]){
            count++;
        }
        else{
            c.push_back(ref);
            v.push_back(count);
            ref=str[i];
            count=1;
            pos++;
        }
    }
    c[pos]=ref;
    v[pos]=count;
    cout<<endl;
    for(int i=0; i<=pos;i++){
        if(v[i]>=k) cout<<c[i]; 
    }
    
}