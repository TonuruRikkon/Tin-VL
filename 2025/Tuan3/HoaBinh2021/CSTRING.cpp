#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("CSTRING.INP","r",stdin);
    freopen("CSTRING.OUT","w",stdout);
    int q;
    if (scanf("%d", &q) != 1) return 0;
    for (int i = 0; i < q; i++)
    {
        int n;
        scanf("%d", &n);
        bool check = true;
        int cnt['z' + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < n; j++)
        {
            static char str[10005];
            scanf("%s", str);
            for (int k = 0; str[k]; k++)
                cnt[(unsigned char)str[k]]++;
        }
        for (int idx = 0; idx <= 'z'; idx++) {
            if (cnt[idx] % n != 0) {
                check = false;
                break;
            }
        }
        if (!check) printf("NO");
        else printf("YES");
        if (i != q - 1) printf("\n");
    }
    return 0;
}