#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long N, k = 1; cin >> N;

    long long SumChan = (N/2) * (N/2 + 1);
    for(long long i = 1, r = N; i <= r; ){
        long long mid = (i + r) / 2;
        long long SumLe = ((mid + 1) / 2) * ((mid + 1) / 2);
        long long SumChanMid = (mid / 2) * (mid / 2 + 1);
        if(SumLe > SumChan - SumChanMid){
            k = mid;
            r = mid - 1;
        }
        else i = mid + 1;
    }
    cout << k;
}