#include <bits/stdc++.h>
using namespace std;

int demdangdau(int n)
{
    int tol=0;
    for (int i = 1; i <= n; i++)
    {
        if(i<10) tol++;
        else if(i==1000) tol+=1000;
        else{
            string str=to_string(i);
            if(i<100){
                if(str[0]==str[1]) tol+=11;
                else tol+=10;
            }
            else if(i<1000){
                if(str[0]==str[2]){
                    if(str[0]==str[1]) tol+=111;
                    else tol+=101;
                }
                else{
                    if(str[0]==str[1]) tol+=110;
                    else if(str[1]==str[2]) tol+=100;
                    else tol+=102;
                }
            }
        }
        
    }
    return tol;
}

int main()
{
    int n;
    cin>>n;
    cout<<demdangdau(n);
}