#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        if(i%2!=0){
            for (int i = 0; i < n; i++){
                if(i%2==0){
                    printf("B");
                }
                else{
                    printf("W");
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(i%2!=0){
                    printf("B");
                }
                else{
                    printf("W");
                }
            }
        }
    cout<<endl;
    }
    return 0;
}