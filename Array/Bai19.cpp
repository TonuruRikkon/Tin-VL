#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=1,s[1000],y=0;
    cin>>n;
    double a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double x=a[0];
    for(int i=1;i<n;i++){
        if(x<0){
            if(a[i]>0) {
                d++;
                x=a[i];
            }
            else if(a[i]<0){
                s[y]=d;
                x=a[i];
                y++;
            }
        }
        if(x>0){
            if(a[i]<0) {
                d++;
                x=a[i];
            }
            else if(a[i]>0){
                s[y]=d;
                x=a[i];
                d=1;
                y++;
            }
        }
    }
    cout<<*max_element(s,s+y)<<endl<<*s;
}