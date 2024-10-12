#include <bits/stdc++.h>
using namespace std;

bool quaylui(vector<int>& a, int m, int index, vector<int>& m_time, int max_t)
{
    if(index==a.size()){
        return true;
    }
    for (int i = 0; i < m; i++)
    {
        if(m_time[i]+a[index]<=max_t){
            m_time[i]+=a[index];
            if(quaylui(a,m,index+1,m_time,max_t)){
                m_time[i] -= a[index];
            }
        }
        if(m_time[i]==0){
            break;
        }
    }
    return false;
}

int main()
{
    int k,m,n;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin>>m>>k;
    vector<int> m_time(m,0);
    sort(a.rbegin(),a.rend());
    int left=*max_element(m_time.begin(),m_time.end());
    int right=accumulate(m_time.begin(),m_time.end(),0);
    int ans=right;
    

    cout<<endl;
}