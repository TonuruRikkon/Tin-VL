#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A,B;
    long x[10],check=0;
    long chek[10],chekB[10];
    memset(chek, 0, sizeof(chek));
    memset(chekB, 0, sizeof(chekB));
    cin>>A>>B;
    for (int i = 0; i < A.size(); i++)
    {
        chek[A[i]-'0']++;
    }
    for (int i = 0; i < B.size(); i++)
    {
        chekB[B[i]-'0']++;
    }
    for (int i = 9; i >= 0; i--)
    {
        if(chek[i]>0&&chekB[i]>0); else check++;
        x[i]=min(chek[i],chekB[i]);
        if(check==9&&i==0&&chek[i]>0)cout<<0;
        else
            while(x[i]>0)
            {
                cout<<i;
                x[i]--;
            }
    }
    if(check==10) cout<<-1;
}