#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name[8]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
    string str;
    int n;
    cin>>n;
    cin>>str;
    for(int i=0;i<8;i++)
    {
        if(str.size()==name[i].size()){
            bool ifok=true;
            for(int k=0;k<str.size();k++){
                if(str[k]!='.'){
                    if(str[k]!=name[i][k]){
                        ifok=false;
                        break;
                    }
                }
            }
            if(ifok==true)
            {
                cout<<name[i];
                break;                
            }

        }
    }
}