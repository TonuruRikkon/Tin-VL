#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int e=0;e<n-i;e++){
            cout<<"*";
        }
    cout<<endl;
    }
    return 0;
}