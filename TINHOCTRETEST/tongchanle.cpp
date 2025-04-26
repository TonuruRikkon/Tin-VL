#include <bits/stdc++.h>
using namespace std;

int tongle(int k,int n)
{
    if(k%2==0){
        return ((1+k-1)*(((k-1)-1)/2+1))/2;
    }
    else{
        return ((1+k)*((k-1)/2+1))/2;
    }
}

int tongchan(int k,int n)
{
    if(k%2==0){
        return ((n+(k+2))*((n-(k+2))/2+1))/2;
    }

    else{
        return ((n+(k+1))*((n-(k+1))/2+1))/2;
    }
}

int main()
{
    int n;
    cin>>n;
    int mid=n/2;
    bool checkfw=false,checkbw=false;
    while(true){
        if(tongle(mid,n)>tongchan(mid,n)){
            if(checkfw==true){
                break;
            }
            mid--;
            checkbw=true;
        }
        else if(tongle(mid,n)<tongchan(mid,n)){
            if(checkbw==true){
                break;
            }
            mid++;
            checkfw=true;
        }
        else{
            mid++;
            break;
        }
    }
    cout<<mid;
}