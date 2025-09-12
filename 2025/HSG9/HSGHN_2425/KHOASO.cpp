#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int num[4]; //Mảng lưu các giá trị của khóa
    int pass[4]={2,0,2,5}; //Mảng lưu mật khẩu 
    //Nhập giá trị hiện tại của khóa
    for (int i = 0; i < 4; i++)
    {
        cin>>num[i];
    }

    for (int i = 0; i < 4; i++)
    {
        //Chọn cách xoay ít nhất: xoay theo chiều thuận 0->9, xoay theo chiều ngược x->0->9->n
        ans+=min(abs(num[i]-pass[i]),abs(9-num[i]+1+pass[i]));
    }
    cout<<ans;
}