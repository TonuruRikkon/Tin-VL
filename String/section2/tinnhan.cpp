#include <bits/stdc++.h>
using namespace std;

int main()
{
    int se=0,d=0,num=2;
    string s=" ",x; cin>>x; s+=x;
    map<int,vector<pair<int,char>>> a;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if(i<='o'){
            d++;
            a[num].push_back(make_pair(d,i));
            if(d==3){
                d=0;
                num++;
            }
        }
        else if(i>='p'&&i<='s'){
            d++;
            a[num].push_back(make_pair(d,i));
            if(d==4){
                d=0;
                num++;
            }
        }
        else if(i>='t'&&i<='v'){
            d++;
            a[num].push_back(make_pair(d,i));
            if(d==3){
                d=0;
                num++;
            }
        }
        else if(i>='w'&&i<='z'){
            d++;
            a[num].push_back(make_pair(d,i));
            if(d==4){
                d=0;
                num++;
            }
        }
    }
    cout<<"-------------------------------------------\n";
    for(auto i:a){
        cout<<i.first<<".";
        for(auto j:i.second){
            cout<<j.first<<','<<j.second<<';';
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------\n";
    for(int x=0;x <= s.size();x++){
        for(auto i:a){
            for(auto j:i.second){
                if(s[x]==j.second){
                    for(auto k:i.second){
                        if(s[x-1]==k.second){
                            if(s[x]==k.second){
                                se+= 2+k.first;
                                cout<<se<<"."<<endl;
                                break;
                            }
                        }
                        else{
                            if(s[x]==k.second){
                            se+= k.first;
                            cout<<se<<"!"<<endl;
                            break;                                
                            }
                        }
                    }
                }
            }
        }
    }cout<<se;
}