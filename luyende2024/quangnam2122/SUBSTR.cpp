#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> tol;
    tol.push_back(0);
    string str;
    int k;
    cin>>k;
    cin>>str;
    for (int i = 0; i <= str.size(); i++)
    {
        if(str[i]==0){
            tol.push_back(tol[i]+1);
        }
        else{
            tol.push_back(tol[i]);
        }
    }
    cout<<upper_bound(tol.begin(),tol.end(),k)-tol.begin()-k-1;
}