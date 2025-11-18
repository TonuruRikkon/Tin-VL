#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
};

double cross_pro(Point A, Point B, Point P){
    double AB_x = B.x-A.x;
    double AB_y = B.y-A.y;
    double AP_x = P.x-A.x;
    double AP_y = P.y-A.y;
    return AB_x*AP_y - AB_y*AP_x;
}

bool check(Point A, Point B, Point C, Point P){
    double ref1=cross_pro(A,B,P);
    double ref2=cross_pro(B,C,P);
    double ref3=cross_pro(C,A,P);

    return ref1<=0&&ref2<=0&&ref3<=0 or ref1>=0&&ref2>=0&&ref3>=0;
}

int main()
{
    
    Point inp[3];
    for (int i = 0; i < 3; i++)
    {
        double x,y;
        cin>>x>>y;
        inp[i]={x,y};
    }
    int n;
    cin>>n;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        double x,y;
        cin>>x>>y;
        if(check(inp[0],inp[1],inp[2],Point{x,y})) ans++;
    }
    cout<<ans;
}