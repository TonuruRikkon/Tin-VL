#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long c=a+b;
    double delta=9*9-4*(-1)*((-2)*c);
    double x1=((-9)+sqrt(delta))/(-2),x2=((-9)-sqrt(delta))/(-2);
    if(c/x1*x1==c){
        if(c/x1>x1) cout<<c/x1<<" "<<x1;
        else cout<<x1<<" "<<c/x1;
    }
    else{
        if(c/x2>x2) cout<<c/x2<<" "<<x2;
        else cout<<x2<<" "<<c/x2;
    }

}