#include <bits/stdc++.h>
using namespace std;

void quaylui(vector<char>&a,map<char,bool>used,string str){
    if(a.size()==str.size()){
        for (char x:a)
        {
            cout<<x;
        }
        cout<<endl;
            }
    else{
        for (char i:str){
            if(used[i]==false){
                a.push_back(i);
                used[i]=true;
                quaylui(a,used,str);
                a.pop_back();
                used[i]=false;
            }
        }

    }
}

int main()
{
    string str;
    cin>>str;
    map<char,bool> used;
    for(char x:str){
        used[x]=false;
    }
    vector<char> a;
    quaylui(a,used,str);
}