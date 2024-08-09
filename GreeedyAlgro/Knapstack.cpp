#include <bits/stdc++.h>
using namespace std;

struct Knapstack
{
    int giatri,trongluong;
    double luongtri;
} a[int(1e6)];
bool cmp(Knapstack a, Knapstack b)
{
    return a.luongtri>b.luongtri;
}
int main()
{
    int n;
    cout<<"Nhap so mat hang: ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap mat hang thu "<<i+1<<" : ";
        cin>>a[i].giatri>>a[i].trongluong;
        a[i].luongtri=double(a[i].giatri)/double(a[i].trongluong);
    }
    int maxx,weight=0,ans=0,d=0;
    cout<<"Nhap so can cho phep: ";
    cin>>maxx;
    sort(a,a+n,cmp);
    cout<<"---------------------------"<<endl;
/**    for (int i = 0; i < n; i++)
    {
        cout<<i<<" "<<a[i].giatri<<" "<<a[i].trongluong<<endl;
    }
    cout<<"---------------------------"<<endl;**/
    for (int i = a[0].trongluong; i <= maxx; i+=a[d].trongluong)
    {
        ans+=a[d].giatri;
        d++;
    }
    cout<<ans;
    
}
