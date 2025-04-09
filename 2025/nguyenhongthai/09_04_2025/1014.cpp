#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int max1=max(a1,max(b1,c1));
    int max2=max(a2,max(b2,c2));
    cout<<(a1+b1+c1-max1)+(a2+b2+c2-max2)+(abs(max1-max2));
}