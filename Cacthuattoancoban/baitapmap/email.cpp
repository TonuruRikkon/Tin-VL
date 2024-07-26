#include <bits/stdc++.h>
using namespace std;

int main()
{
    int long long n;
    cin>>n;
    vector<string> acc;
    vector<string> acc_ref;
    int long long pos[n+1];
    memset(pos,0,sizeof(pos));
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        acc.push_back(x);
        acc_ref.push_back(x);
    }  
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            if(acc[i]==acc[j]){
                string x = acc[j];
                if(x[x.length()-1]>='0'&&x[x.length()-1]<='8'){
                    x[x.length()-1]+=1;
                }
                else if(x[x.length()-1]=='9'){
                    x[x.length()-1]='0';
                    x+="0";
                }
                else{
                    x+="1";
                }
                acc.erase(acc.begin()+j);
                acc.insert(acc.begin()+j,x);
                pos[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(pos[i]==0) cout<<"OK"<<endl;
        else{
            cout<<acc[i]<<endl;
        }
    }
    
}