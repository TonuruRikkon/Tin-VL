#include <bits/stdc++.h>
using namespace std;

bool ngto(int s){
    for (int i = 2; i <= sqrt(s); i++)
    {
        if(s%i==0) return false;
    }
    return true;
}

int main()
{
    int a,b;
    cin>>a>>b;
    for (int i = a+b+1; i <= 3*int(1e7); i++)
    {
        if(ngto(i)==true) {
            cout<<i-(a+b);
            break;
        }
    }
    
}