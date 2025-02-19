#include <bits/stdc++.h>
using namespace std;

vector<bool> tamgiac(int(1e7)+1,false);

void demtamgiac()
{
    fill(tamgiac.begin(),tamgiac.end(),false);
    long long temp=0;
    for(int i=1;i<=int(1e6);i++){
        temp+=i;
        if(temp>int(1e7)+1) break;
        tamgiac[temp]=true;
    }
}

int main()
{
    demtamgiac();
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        if(tamgiac[n]==true) cout<<"1"<<"\n";
        else cout<<"0"<<"\n";
    }
}