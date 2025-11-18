#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inp[i]);
    }
    vector<int> tail;
    for(int val:inp){
        auto it=lower_bound(tail.begin(),tail.end(),val);
        if(it==tail.end()){
            tail.push_back(val);
        }
        else{
            *it=val;
        }
    }
    printf("%d", tail.size());
}
