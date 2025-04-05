#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t1,v1,t2,v2;
    cin>>t1>>v1>>t2>>v2;
    int x;
    cin>>x;
    double tol1=0,tol2=0,ref1=0,ref2=0;

    
    while(true){
        int s=v1*t1;
        if(tol1+s<x){
            tol1+=s;
            ref1+=t1*2;
        }
        else if(tol1+s>=x)
        {
            ref1+=double(x-tol1)/v1;
            break;
        }
    }
    while(true){
        int s=v2*t2;
        if(tol2+s<x){
            tol2+=s;
            ref2+=t2*2;
        }
        else if(tol2+s>=x)
        {
            ref2+=double(x-tol2)/v2;
            break;
        }
    }

    if(ref1<ref2){
        cout<<"First";
    }
    else if(ref1>ref2){
        cout<<"Second";
    }
    else if(ref1==ref2){
        cout<<"Draw";
    }
}