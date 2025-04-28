#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,anger=0,comp=0;
    cin>>n>>k>>x;
    vector<int> goods;
    for (int i = 0; i < n; i++)
    {
        long long inp;
        cin>>inp;
        goods.push_back(inp);
    }
    int s=1;
    while(true)
    {
        s+=x;
        int d=k;
        for(int i=0;i<goods.size();i++)
        {
            if(d==0){
                if(goods[i]<=s) {
                    anger++;
                    cout<<goods[i]<<' '<<s<<'\n';
                }
            }
            else{
                if(goods[i]<=s){
                    d--;
                    comp++;
                    goods[i]==LONG_LONG_MAX;
                }
                else if(goods[i]==*min_element(goods.begin(),goods.end())){
                    d--;
                    comp++;
                    goods[i]==LONG_LONG_MAX;
                }
            }
        }
        if(comp==n){
            cout<<anger;
            break;
        }
    }
}