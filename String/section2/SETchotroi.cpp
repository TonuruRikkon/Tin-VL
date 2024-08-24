#include<bits/stdc++.h>
using namespace std;

bool kiemtra(string x,string y, string z)
{
    if(x==y&&y==z||x!=y&&y!=z&&x!=z) return true;
    return false;
}

int main()
{
    struct SETchotroi{string amo,clo,way,sap;}a[82];
    int n; int ans=0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i].amo>>a[i].clo>>a[i].way>>a[i].sap;
        if(a[i].amo=="one") a[i].sap+='s';
    }
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            for (int h = j+1; h <= n; h++){
                if(kiemtra(a[i].amo,a[j].amo,a[h].amo)==true&&
                kiemtra(a[i].clo,a[j].clo,a[h].clo)==true&&
                kiemtra(a[i].way,a[j].way,a[h].way)==true&&
                kiemtra(a[i].sap,a[j].sap,a[h].sap)==true) 
                ans++;
            }
        }
    }
    cout<<ans;
}