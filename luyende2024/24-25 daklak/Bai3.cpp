#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n,d=0;
    cin>>n;
    vector<string> count;
    string F0="0",F1="1";
    for (int i = 2; i <= n; i++)
    {
        string F=F0+F1;
        
        if(F.find(str)!=-1){
            d++;
        }

    }
    cout<<d;
}