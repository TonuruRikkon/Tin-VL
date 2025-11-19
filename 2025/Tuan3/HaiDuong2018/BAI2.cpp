#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int maxx=0;
    int most;
    map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        int sach;
        scanf("%d", &sach);
        int ref=++cnt[sach];
        if(ref>maxx){
            maxx=ref;
            most=sach;
        }
    }
    printf("%d %d", most, maxx);
}