#include <bits/stdc++.h>
using namespace std;

// vector<bool> IsNto(int(1e6)+1,true);
// vector<int> Nto;

// void sangnt(){
//     IsNto[0]=IsNto[1]=false;
//     for (int i = 2; i*i <= int(1e6); i++)
//     {
//         if(IsNto[i]){
//             Nto.push_back(i);
//             for (int j = i*i; j <= int(1e6); j+=i)
//             {
//                 IsNto[j]=false;
//             }
            
//         }
//     }
    
// }

int main()
{
    long long n;
    cin>>n;
    map<long long,long long> cnt;
    for (long long i = 2; i*i <= n; i++)
    {
        while (n%i==0)
        {
            n/=i;
            cnt[i]++;
        }
        
    }
    bool check=false;
    for (auto &&x : cnt)
    {
        for (long long i = 0; i < x.second; i++)
        {
            if(check==true){
                cout<<'x';
            }
            else check=true;
            cout<<x.first;
        }
        
    }
    

}