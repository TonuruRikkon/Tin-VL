#include <bits/stdc++.h>
using namespace std;

struct danhsachhs
{
    string ten,hodem;
    int nsinh;
}ds[110];

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, ds[i].hodem);
        getline(cin, ds[i].ten);
        cin>>ds[i].nsinh;
    }
    for(int  i=n-1;i>=1;i--){
        for (int j = 0; j < i; j++)
        {
            if(ds[i].ten<ds[i-1].ten||ds[i].ten==ds[i-1].ten&&ds[i].hodem>ds[i-1].hodem) swap(ds[i],ds[i-1]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ds[i].hodem<<" "<<ds[i].ten<<endl;
    }
    
}