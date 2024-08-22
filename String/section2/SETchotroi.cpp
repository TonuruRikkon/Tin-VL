#include<bits/stdc++.h>
using namespace std;

struct SETchotroi
{
    string amo,clo,way,sap;
}a[82];


bool kiemtra(string x,string y, string z)
{
    if(x==y&&y==z||x!=y&&y!=z&&x!=z) return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>a[i].amo>>a[i].clo>>a[i].way>>a[i].sap;
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    
}