#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a[1000],sum=0, sum_pos=0, sum_neg=0,d=0,d_pos=0,d_neg=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d++;
        sum+=a[i];
        if(a[i]>0){
            sum_pos+=a[i];
            d_pos++;
        }
        else if(a[i]<0){
            sum_neg+=a[i];
            d_neg++;
        }
    }
    cout<<"TB:"<<sum/d<<endl;
    cout<<"TB_duong:"<<sum_pos/d_pos<<endl;
    cout<<"TB_am:"<<sum_neg/d_neg<<endl;
}