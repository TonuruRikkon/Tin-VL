#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d1=0,d2=0,d3=0,doi;
    cin>>n;
    vector<int> tin;
    vector<int> toan;
    vector<int> td;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        if(x==1) {
            tin.push_back(i);
            d1++;
        }
        else if(x==2) {
            toan.push_back(i);
            d2++;
        }
        else if(x==3) {
            td.push_back(i);
            d3++;
        }
    }
    doi=min(d1,min(d2,d3));
    cout<<doi<<endl;
    while (tin.size()>doi)
    {
        tin.erase(tin.begin()+0);
    }
        while (toan.size()>doi)
    {
        toan.erase(toan.begin()+0);
    }
        while (td.size()>doi)
    {
        td.erase(td.begin()+0);
    }
    
    for (int i = 0; i < doi; i++)
    {
        cout<<tin[i]<<" "<<toan[i]<<" "<<td[i]<<endl;
    }
    
    
    
}