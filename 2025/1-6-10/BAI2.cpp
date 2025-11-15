#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    cin.ignore();
    getline(cin,str);
    int k;
    cin>>k;
    int sz=str.size();
    int temp=0;
    bool neg=false;
    map<int,int> num;
    for (int i = 0; i < sz; i++)
    {
        if(str[i]>='0'&&str[i]<='9'){
            temp=temp*10+(str[i]-'0');
        }
        else if(str[i]=='-'){
            num[temp]++;
            temp=0;
            neg=true;
        }
        else{
            if(temp!=0){
                if(neg==true) temp=-temp;
                neg=false;
                num[temp]++;
                temp=0;
            }
        }
    }
    if(temp!=0){
        if(neg==true) temp=0-temp;
        neg=false;
        num[temp]++;
        temp=0;
    }
    int ans=0;
    for(auto x:num){
        if(k-x.first==x.first){
            ans+=(x.second*(x.second-1)/2);
        }
        else{
            ans+=x.second*num[k-x.first];
        }
        num[x.first]=0;
    }
    cout<<ans;
}