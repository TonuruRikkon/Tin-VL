#include <bits/stdc++.h>
using namespace std;

vector<int>ngto;

void sangnt()
{
    vector<bool> isNgto(int(1e7),true);
    isNgto[0]=isNgto[1]=false;
    for (int i = 2; i < int(1e6); i++)
    {
        if(isNgto[i]==true){
            for (int j = i*i; j < int(1e6); j+=i)
            {
                isNgto[j]=false;
            }
            ngto.emplace_back(i);
        }
    }
    
}

int main()
{
    sangnt();
    long long n;
    cin>>n;

}