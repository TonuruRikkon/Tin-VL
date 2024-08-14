#include <bits/stdc++.h>
using namespace std;

struct amogu
{
    float tol,toan,van,anh,toanch;
    string hoten,sbd;
}a[1000];

bool cmp(amogu a, amogu b)
{
    return a.tol>b.tol;
}


int main ()
{
    freopen("inputfile/tuyensinh.inp","r",stdin);
    freopen("outputfile/tuyensinh.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin,a[i].sbd);
        getline(cin,a[i].hoten);
        cin>>a[i].toan>>a[i].van>>a[i].anh>>a[i].toanch;
        a[i].tol=a[i].toan+a[i].van+a[i].anh+(a[i].toanch*2);
    }
    sort(a,a+n,cmp);
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"|STT|   SBD   |       Ho Ten        | Toan | Van  | Anh  | Toan chuyen | Tong |"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        printf("%c%3d%c",'|',i,'|');
        printf("%-9s%c",a[i].sbd.c_str(),'|');
        printf("%-21s%c",a[i].hoten.c_str(),'|');
        printf("%6.2f%c",a[i].toan,'|');
        printf("%6.2f%c",a[i].van,'|');
        printf("%6.2f%c",a[i].anh,'|');
        printf("%13.2f%c",a[i].toanch,'|');
        printf("%6.2f%c\n",a[i].tol,'|');
        cout<<"-------------------------------------------------------------------------------"<<endl;
    }
    
}