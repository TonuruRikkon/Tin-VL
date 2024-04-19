#include <bits/stdc++.h>
using namespace std;

int main()
{
    int lenght;
    string ten;
    getline(cin, ten);
    lenght = ten.size();
    if(ten[0]>='a'&&ten[0]<='z')    ten[0] -= 32;
    for(int i=0; i<=lenght; i++){
        if(ten[i-1] == ' ') ten[i] -= 32; 
    }
    cout<<ten;
}