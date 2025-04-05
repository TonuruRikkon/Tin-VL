#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long c=a+b;
    for(int i=1; i<c;i++){
        if(c%i==0){
            if((((c/i)-1)+(i-1))*2<=a){
                if(i>=c/i){
                    cout<<i<<" "<<(a+b)/i;
                    break;
                }
                else{
                    cout<<(a+b)/i<<" "<<i;
                    break;
                }                
            }
        }
    }
}