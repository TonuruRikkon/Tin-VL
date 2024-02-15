#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tich_n=1;
    cin>>n;
    while(n!=0)
        {
            tich_n = tich_n * n;
            n--;
        }
    cout<<tich_n<<endl;
    return 0;
}