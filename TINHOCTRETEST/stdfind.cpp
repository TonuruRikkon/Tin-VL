#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin>>n;
    int d=0,fp=1;
    for (int i = 1; i <= n.size()/2; i++)
    {
        string temp=n.substr(0,i);
        string temp2=n.substr(i);
        if(temp2.find(temp)!=-1){
            fp=temp2.find(temp)+i;
            d++;
        }
    }
    cout<<d<<" "<<fp+1;
    
}