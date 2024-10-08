#include <bits/stdc++.h>
using namespace std;
void sieve(int k, vector<int>& prime){
    vector<bool> is_prime(k+1,true);
    for (int i = 2; i*i <= k; i++)
        {
            if(is_prime[i]){
                for (int j = i*i; j < k; j+=i)
                {
                    is_prime[j] = false;
                }
            }
        }
    for (int i = 2; i <= k; i++)
    {
        if(is_prime[i]) prime.push_back(i);
    }
}


void sodb(int index, long long product, const vector<int>& prime, set<long long>& db){
    if(product> 2e9) return;
    db.insert(product);
    for (int i = index; i < prime.size(); i++)
    {
        if(product> 2e9/prime[i]) break;
        sodb(i, product*prime[i], prime, db);
    }
}

int main()
{
    int k,a,b;
    cin>>k>>a>>b;
    vector<int> prime;
    set<long long> db;
    sieve(k,prime);
    for(int x:prime)
    {
        sodb(0, x, prime, db);
    }
    cout<<distance(lower_bound(db.begin(),db.end(),a),upper_bound(db.begin(),db.end(),b));
    return 0;
    
}