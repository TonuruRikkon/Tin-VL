#include <bits/stdc++.h>
using namespace std;

string str;
int lenght;

char lowwer(char chr)
{
    if(chr >= 'A' && chr <= 'Z'){
        chr= chr + 32;
    }
    return chr;
}

int main()
{
    
    getline(cin,str);
    lenght = str.size() - 1;
    for(int i=0;i<= lenght; i++){
        str[i] = lowwer(char(str[i]));
    }
    cout<<str;
}

