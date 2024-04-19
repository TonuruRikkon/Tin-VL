#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num,n=0,times[10000];
    char chr[1000];
    string str,temp="";
    getline(cin,str);
    for(int i=0;i<=str.size()-1;i++){
        if(str[i]>='1'&&str[i]<='9'){
            temp+=str[i];
        }
        else{
            if(temp!=""){
                num = atoll(temp.c_str());
                n++;
                times[n]=num;
                chr[n]=str[i];
                temp="";
            }
        }
    }
    
    

    for(int i=1; i<=n;i++){
        for(int d=1; d <= times[i]; d++){
            cout<<chr[i];
        }
    }
}