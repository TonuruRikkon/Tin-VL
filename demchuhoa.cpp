#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a=0;
    string str;
    getline(cin,str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            a++;
        }
    }
    cout<<a;

}
