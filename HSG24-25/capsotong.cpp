#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,outt=0;
    cin>>n;
    cin.ignore();
    string str,temp="";
    map<int,int> ans;
    getline(cin,str);
    cin>>k;
    for (int i = 0; i <= str.size(); i++)
    {
        if(isdigit(str[i])||str[i]=='-'&&i!=str.size()){
            temp+=str[i];
        }
        else
        {
            if(!temp.empty())
            {
                ans[stoi(temp)]++;
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        ans[stoi(temp)]++;
    }
    for(auto x:ans){
        int ref=x.first;
        int y=k-ref;
        if(ans.find(y)!=ans.end()){
            if(ref+y==k){
                if(ref==y) outt+=(x.second*(x.second-1))/2; 
                else if(ref>y){
                outt+=x.second*ans[y];
                }
            } 
        }
    }
    cout<<outt;
}