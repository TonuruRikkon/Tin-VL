#include <bits/stdc++.h>
using namespace std;

vector<bool> ngto(int(1e7)+2,true);
vector<int> nto;

void sangnt()
{
    ngto[0]=ngto[1]=false;
    for (int i = 0; i*i < int(1e7)+2; i++)
    {
        if(ngto[i]==true){
            nto.emplace_back(i);
            for (int j = i*i; j < int(1e7)+2; j+=i)
            {
                ngto[j]=false;
            }            
        }
    }
    
}
set<int> tr,fls;
bool kt_nt(int n){
    if(tr.find(n)!=tr.end()) return true;
    if(fls.find(n)!=fls.end()) return false; 
    if(n<2) return false;
    for (int i = 2; i*i < n; i++)
    {
        if(n%i==0) {
            fls.insert(n);
            return false;
        }
    }
    tr.insert(n);
    return true;
}


int main()
{
    sangnt();
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin>>n;
        if(n>int(1e6)){
            int i=n;
            while (!kt_nt(i))
            {
                i++;
            }
            cout<<i;
        }
        else cout<<*lower_bound(nto.begin(),nto.end(),n)<<'\n';
    }
    
}