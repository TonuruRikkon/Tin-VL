#include <bits/stdc++.h>
using namespace std;

int main()
{
    int outt=0,num=0;
    map<string,int> a;
    while(true){
        int x;
        string name;
        string ans;
        cin>>x;
        if(x==-1) break;
        cin>>name>>ans;
        if(ans=="wrong"){
            a[name]+=20;
        }
        else if(ans=="right"){
            a[name]+=x;
            num++;
            outt+=a[name];
        }

    }
    cout<<num<<" "<<outt;
}