#include <bits/stdc++.h>
using namespace std;

void sangnt(vector<int> &nto, vector<bool> &nt, vector<int> &cntnto, vector<int> &tolnto)
{
    nt[0]=nt[1]=false;
    for (int i = 2; i*i <= int(1e6); i++)
    {
        if(nt[i]==true){
            nto.push_back(i);
            cntnto[i]=cntnto[i-1]+1;
            tolnto[i]=tolnto[i-1]+i;
            for (int j = i*i; j <= int(1e6); j+=i)
            {
                nt[j]=false;
            }
            
        }
        else{
            cntnto[i]=cntnto[i-1];
            tolnto[i]=tolnto[i-1];
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> nto;
    vector<bool> nt(int(1e6)+1,true);
    vector<int> cntnto(int(1e6)+1,0);
    vector<int> tolnto(int(1e6)+1,0);
    sangnt(nto,nt,cntnto,tolnto);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        double cnt=cntnto[y]-cntnto[x-1];
        double avr=(tolnto[y]-tolnto[x-1])/cnt;
        cout<<int(cnt)<<' ';
        cout<<fixed<<setprecision(2)<<avr;
        if(i!=n-1) cout<<'\n';
    }
    
}