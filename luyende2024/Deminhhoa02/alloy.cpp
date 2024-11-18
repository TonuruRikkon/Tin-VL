#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)+1];
int slngto[int(1e6)+1],tolngto[int(1e6)+1];


void sangnt()
{
    memset(ngto,true,sizeof(ngto));
    ngto[0]=ngto[1]=false;
    int p=2;
    while (p*p<=int(1e6))
    {

        for (int i = 2; i <= int(1e6)/p; i++)
        {
            ngto[i*p]=false;
        }
        for(p++;p*p<=int(1e6)&&ngto[p]==false;p++);        
    }
}

void tongnt(){
    slngto[0]=tolngto[0]=0;
    for (int i = 1; i <= int(1e6); i++)
    {
        if(ngto[i]==true){
            slngto[i]=slngto[i-1]+1;
            tolngto[i]=tolngto[i-1]+i;
        }
        else{
            slngto[i]=slngto[i-1];
            tolngto[i]=tolngto[i-1];
        }
    }
    
}

int main()
{
    int n,d=0,tol=0;
    cin>>n;
    sangnt();
    tongnt();
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        int sl=slngto[y]-slngto[x-1];
        float tb=float(tolngto[y]-tolngto[x-1])/sl;
        cout<<sl<<" "<<fixed<<setprecision(2)<<tb<<endl;
    }
    
    
}