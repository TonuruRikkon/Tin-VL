#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    if (x<= 100) cout<< x*2000;
    else if (x<=200) cout<< 100*2000 + (x-100)*3000;
    else if (x<=300) cout<< 100*2000 + 100*3000 + (x-200)*5000;
    else if (x>300) cout<< 100*2000 + 100*3000+ 100*5000 +(x-300)*10000;
    return 0;
}
