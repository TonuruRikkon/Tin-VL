#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A,B;
    map<int,int> chek;
    vector<char> ans;
    ans.push_back(NULL);
    cin>>A>>B;
    for (int i = 0; i < A.size(); i++)
    {
        chek[A[i]]++;
    }
    for (int i = 0; i < B.size(); i++)
    {
        if(chek[B[i]]>0){
            ans.push_back(B[i]);
            chek[B[i]]--;
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    if(ans[0]==NULL) cout<<-1;
    else if(ans[0]=='0') cout<<0;
    else for(char i:ans){
        cout<<i;
    }

}