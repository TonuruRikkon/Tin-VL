#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        vector<int> chuot,nha;
        chuot.clear();
        nha.clear();
        for(int i=0;i<n;i++){
            int vitric;
            cin>>vitric;
            chuot.push_back(vitric);
        }
        for (int i = 0; i < n; i++)
        {
            int vitrin;
            cin>>vitrin;
            nha.push_back(vitrin);
        }
        sort(chuot.begin(),chuot.end());
        sort(nha.begin(),nha.end());
        int farest=0;
        for(int i=0;i<n;i++){
            if(abs(nha[i]-chuot[i])>farest){
                farest=abs(nha[i]-chuot[i]);
            }
        }
        cout<<farest<<"\n";
    }
    
    
}