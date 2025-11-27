#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long end_0=1;
    long long end_1=1;
    long long end_11=0;
    for (int i = 2; i <= n; i++)
    {
        long long mem_end_0=end_0;
        long long mem_end_1=end_1;
        long long mem_end_11=end_11;
        end_0=mem_end_0+mem_end_1+mem_end_11;
        end_1=mem_end_0;
        end_11=mem_end_1;
    }
    cout<<end_0+end_1+end_11;
}