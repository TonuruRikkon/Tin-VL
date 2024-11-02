#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n=500;
    for (int i = 2; i <= 180; i++)
    {
        cout<<"U"<<i<<" = ";
        n=(n*1.005+500);
        cout<<n<<endl;
    }
    
}