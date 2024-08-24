#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string x;
        getline(cin,x);
        a.push_back(x);
    }
    for(auto x:a){
        int d=0;
        for (int i = 0; i < x.size(); i++)
        {
            if(x[i]=='A'&&x[i-1]=='B'&&x[i+1]=='B'){
                d++;
            }
            else if(x[i]=='B'&&(x[i-1]!='A'||x[i+1]!='A')){
                d++;
            }
        }
        if(d==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}