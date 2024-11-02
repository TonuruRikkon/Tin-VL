#include<bits/stdc++.h>
using namespace std;
string s;
string thugon(string s)
{
    long d=1;string u="",z="";
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]==s[i+1]) d++;
        else{
            if(d==1) u+=s[i];
            else {
                z=to_string(d);
                u+=z;
                u+=s[i];
                d=1;
            }
        }
    }
    return u;
}
int main()
{
    while(cin>>s){
        cin.ignore();
        cout<<thugon(s)<<"\n";
    }
};
