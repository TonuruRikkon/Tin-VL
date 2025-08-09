#include <bits/stdc++.h>
using namespace std;

int main()
{

    int anhxa[8]={128,64,32,16,8,4,2,1};
    string str,temp="";
    getline(cin,str);
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==' '){
            int tol=0;
            for (int j = 0; j < temp.size(); j++)
            {
                if(temp[j]=='1'){
                    tol+=anhxa[j];
                }  
            }
            cout<<char(tol);
            temp="";
        }
        else temp+=str[i];
    }
    int tol=0;
    for (int j = 0; j < temp.size(); j++)
    {
        if(temp[j]=='1'){
            tol+=anhxa[j];
        }  
    }
    cout<<char(tol);
    temp="";
    
}