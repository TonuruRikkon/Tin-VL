#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, check="", temp="";
    getline(cin, str);
    for(char ch : str){
        if(isdigit(ch)) check += ch;
    }
    while(check.size() > 5){
        for(int i = 0; i < check.length()-1; i++){
            if(check[i] > check[i+1]) {
                check.erase(i+1, 1);
                break;
            }
            else if(check[i] < check[i+1]) {
                check.erase(i, 1);
                break;
            }
            else if (check[i] == check[i+1]){
                temp += check[i];
                check.erase(i, 1);
            }
        }
        check.append(temp);
        temp = "";
    }
    cout << check;
    return 0;
}
