#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    string str;
    cin>>x>>y;
    cin.ignore();
    getline(cin,str);
    for (int i = 0; i < str.size(); i++)
    {
        cout<<int(str[i])-48<<endl;
    }
    

    
}