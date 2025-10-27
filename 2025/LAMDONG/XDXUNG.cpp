#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    string rstr=str;
    reverse(rstr.begin(),rstr.end());
    while (!str.empty())
    {
        str.pop_back();
    }
    
    
}