#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
struct st{
    string sbd, ten;
    float toan, van, anh, toanchyn, tong;
}a[10000];
int main(){
    int n; cin>>n;
    FOR(i,1,n){
        cin.ignore();
        getline(cin,a[i].sbd);
        getline(cin,a[i].ten);
        cin>>a[i].toan>>a[i].van>>a[i].anh>>a[i].toanchyn;
        a[i].tong+=a[i].toan+a[i].van+a[i].anh+a[i].toanchyn;
     }
    FOR(i,1,n) cout<<a[i].tong<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"|STT|   SBD   |       Ho Ten       | Toan | Van  | Anh  | Toan chuyen | Tong |"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    FOR(i,1,n){
        printf("%c%3d%c",'|',i,'|');
        printf("%9s%c",a[i].sbd.c_str(),'|');
        printf("%20s%c",a[i].ten.c_str(),'|');
        printf("%6f%c",a[i].toan,'|');
        printf("%6f%c",a[i].van,'|');
        printf("%6f%c",a[i].anh,'|');
        printf("%13f%c",a[i].toanchyn,'|');
        printf("%6f%c\n",a[i].tong,'|');
        cout<<"------------------------------------------------------------------------------"<<endl;
     }
}