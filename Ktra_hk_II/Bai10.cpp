#include <bits/stdc++.h>
using namespace std;

/**int main()
{
    int n,x,lenght;
    string str,abc="", abc_2, ans="",t;
    getline(cin, str);
    cin>>n;
    lenght = str.size();
    for(int i='a'; i<='z'; i++){
        abc+= i;
    }
    abc_2 = abc + abc;
    for(int i=0; i<=lenght-1;i++){
        t = "";
        t += str[i];
        x = abc_2.find(t);
        ans += abc_2[x - n%26];
    }
    cout<<ans;
}**/

int main()
{
    int n,x,lenght;
    string str,abc="", abc_2,ans="",t;
    getline(cin, str);
    cin>>n;
    lenght = str.size();
    for(int i='a'; i<='z'; i++){
        abc+= i;
    }
    abc_2 = abc + abc;
    for(int i=0; i<=lenght-1;i++){
        t = "";
        t += str[i];
        x = abc_2.find(t);
        ans += abc_2[x + n%26];
    }
    cout<<ans;
}