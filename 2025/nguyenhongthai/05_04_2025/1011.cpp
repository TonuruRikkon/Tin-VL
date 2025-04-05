#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,m;
    cin>>h>>m;
    if(h==0){
        if(m<45){
            cout<<23<<" "<<60-(45-m);
        }
        else{
            cout<<0<<" "<<m-45;
        }
    }
    else{
        if(m<45){
            cout<<h-1<<" "<<60-(45-m);
        }
        else{
            cout<<h<<" "<<m-45;
        }        
    }

}