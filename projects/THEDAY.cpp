#include <iostream>
using namespace std;

int main()
{
    int d,t,n,check_t,var_check;
    cin>>d>>t>>n;
    if(t<8&&t%2!=0||t>7&&t%2==0) check_t == 0; //thang 31 ngay
    else check_t == 1; // thang 30 ngay
    if(check_t==0&&d==31&&t<12) cout<<"1 "<<t+1<<" "<<n<<endl;
    else if(d==31&&t==12) cout<<"1 1"<<n+1<<endl;
    else if(d==29&&t==2&&n%400==0) cout<<"1 "<<t+1<<" "<<n<<endl;
    else if(d==28&&t==2&&n%400!=0) cout<<"1 "<<t+1<<" "<<n<<endl;
    else if(check_t=0&&d==30) cout<<"1 "<<t+1<<" "<<n<<endl;
    else cout<<d+1<<" "<<t<<" "<<n<<endl;
    return 0;
}
    
