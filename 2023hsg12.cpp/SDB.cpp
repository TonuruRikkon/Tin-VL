#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j>0; j++){
            if(int(sqrt(j))*int(sqrt(j))==j){
                cout<<j<<" ";
                break;
            }
        }

    }

}
