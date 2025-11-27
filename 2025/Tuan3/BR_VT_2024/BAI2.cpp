#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1;
    cin>>str1;
    bitset<64> bit1s(str1);
    unsigned long long ll01=bit1s.to_ullong();
    string str2;
    cin>>str2;
    bitset<64> bit2s(str2);
    unsigned long long ll02=bit2s.to_ullong();
    cout<<(long long)sqrt(ll02)-(long long)sqrt(ll01);
}