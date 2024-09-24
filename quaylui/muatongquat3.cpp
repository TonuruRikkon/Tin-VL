#include <bits/stdc++.h> 
using namespace std;

void quaylui()
{
    if(tol>T) return;
    else if(yeu_tol>max){
        max=yeu_tol;
        ans=a;
    }
    else{
        for (int i = 0; i < n; i++)
        {
            val=i+1;
            a.push_back(gia[i]);
            tol+=gia[i];
            yeu_tol+=yeu[i];
            quaylui();
            a.pop_back();
            tol-=gia[i];
            yeu_tol-=yeu[i];
        }
        
    }
}