#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        reverse(str.begin()+x-1,str.end()-x+1);
    }
    cout<<str;
}