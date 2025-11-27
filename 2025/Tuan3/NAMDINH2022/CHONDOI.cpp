#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double ans=0;
    map<char,bool> check;
    check['H']=check['S']=check['G']=check['P']=check['T']=true;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        if(str[0]!=str[1]&&(check[str[0]]==true)) ans++;
    }
    cout<<ceil(ans/3);
}