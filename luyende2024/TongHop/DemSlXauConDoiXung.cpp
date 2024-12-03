#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    string str;
    cin>>str;
    for (int i = 1; i < str.size()-1; i++)
    {
        if(str[i]==str[i+1]){
            int j=0;
            while (str[i-j]==str[i+j+1]&&j+j<str.size()&&i-j>=0)
            {
                j++;
                ans++;
            }
        }
        if(str[i]==str[i+2])
        {
            int j=0;
            while (str[i-j]==str[i+2+j]&&i+j<str.size()&&i-j>=0)
            {
                j++;
                ans++;
            }
        }
    }
    cout<<ans;
}