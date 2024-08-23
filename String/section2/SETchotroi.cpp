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
    int n,ans=0;
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>a[i].amo>>a[i].clo>>a[i].way>>a[i].sap;
        if(a[i].amo=="one") a[i].sap+='s';
    }
    for (int i = 0; i < n; i+=3)
    {
        if(kiemtra(a[i].amo,a[i+1].amo,a[i+3].amo)==true||kiemtra(a[i].clo,a[i+1].clo,a[i+3].clo)==true||kiemtra(a[i].way,a[i+1].way,a[i+3].way)==true||kiemtra(a[i].sap,a[i+1].sap,a[i+3].sap)==true) ans++;
    }
    cout<<ans;
}