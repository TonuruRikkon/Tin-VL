#include <bits/stdc++.h>
using namespace std;


void quaylui(vector<int>&a,int n){
    if(a.size()==n){
        for (int x:a)
        {
            cout<<x<<" ";
        }
        cout<<endl;
            }
    else{
        cout<<"tao vong for:"<<endl;
        for (int i = 0; i <= 1; i++)
        {
                a.push_back(i);
                cout<<"pushback:";
                for (int x:a)
                {
                    cout<<x<<" ";
                }
                cout<<endl;

                quaylui(a,n);
                a.pop_back();
                cout<<"popback:";
                for (int x:a)
                {
                    cout<<x<<" ";
                }
                cout<<endl;
            
        }

    }
}


int main(){
    int n;
    cin>>n;
    vector<bool> used(n,false);
    vector<int> a;
    quaylui(a,n);
}

