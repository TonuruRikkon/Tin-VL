#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int m;
    cin>>str>>m;
    while (str.size()>1)
    {
        string temp=str.substr(0,10);
        str.erase(0,10);  
        long i = stol(temp);
        str=to_string(i%m)+str;
    }
    

    
}