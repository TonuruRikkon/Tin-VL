#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,string> a={1,"0"};
    string str,str2,ans;
    getline(cin,str);
    getline(cin,str2);
    for (int i = 0; i < str.size(); i++)
    {
        for(int j =0;j<str2.size();j++)
        {
            if(str[i]==str2[j]&&str[i]!=' '){
                int k=0;
                int chu=0;
                string temp="";
                while (true)
                {
                    if(str[i+k]!=str2[j+k]&&(str[i+k]==' '||str[j+k]==' ')){
                        if(a.first<chu) a={chu,temp};
                        break;
                    }
                    else if(str[i+k]==str2[j+k]){
                        temp+=str[i+k];
                        k++;
                        if(str[i+k]!=' ') chu++;
                    }
                    else{
                        break;
                    }
                }
                
            }
        }
    }
    cout<<a.second;
}