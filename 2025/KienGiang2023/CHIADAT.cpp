#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<int> inp(n);
    map<pair<int,int>,int> diff1,diff2;
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    long long A=0,B=0,C=0,A2=0,B2=0,C2=0;
    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(j==0) {
                A+=inp[i];
            }
            
            else if(j==1) {
                B+=inp[i];
            }
            
            else if(j==2) {
                C+=inp[i];
            }
        }
        
    }
    

}