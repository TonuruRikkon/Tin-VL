#include <bits/stdc++.h>
using namespace std;

bool ngto[int(1e6)];
vector<int> ngt;

void sangnt(){
    memset(ngto, true, sizeof(ngto));
    ngto[1]=0;
    ngto[0]=0;
    for (int i = 2; i < sqrt(int(1e6)); i++)
    {
        if(ngto[i]==true){
            for (int j = i*i; j < int(1e6); j+=i)
            {
                ngto[j]=false;
            }
        }
    }
}

int main()
{
    int n,d_c=0,s_c=0;
    vector<int> d,s;
    vector<pair<int,int>> inp;
    cin>>n;
    sangnt();
    for (int i = 0; i < int(1e6); i++)
    {
        if(ngto[i]==true){
            d_c+=1;
            s_c+=i;
            d.push_back(d_c);
            s.push_back(s_c);
        }
        else{
            d.push_back(d_c);
            s.push_back(s_c);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int L,R;
        cin>>L>>R;
        cout<<fixed<<setprecision(2)<<d[R]-d[L-1]<<" "<<float(s[R]-s[L-1])/float(d[R]-d[L-1])<<endl;
    }
    
}