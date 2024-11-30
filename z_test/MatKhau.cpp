#include <bits/stdc++.h>
using namespace std;

struct mk
{
    int thuong,hoa,so;
};

int dem(vector<mk> inp,int k){
    int ans=0;
    for(int i=0;i<inp.size();i++){
        int x=0,L=i,R=inp.size()-1,pos=0;
        while (R>=L)
        {
            int mid=L+(R-L)/2;
            if((inp[mid].hoa-inp[i].hoa>0)&&(inp[mid].thuong-inp[i].thuong>0)&&(inp[mid].so-inp[i].so>0)){
                R=mid-1;
                pos=mid;
            }
            else{
                L=mid+1;
            }
        }
        if(pos>0){
            if(pos-i>=k) ans+=inp.size()-pos;
        }
    }
    return ans;    
}

int main()
{
    string str;
    cin>>str;
    if(str.size()<6){
        cout<<0;
        return 0;
    }
    else if(str.size()==6){
        int so=0,chu=0,hoa=0;
        for(char x:str){
            if(x>='0'&&x<='9') so++;
            else if(x>='a'&&x<='z') chu++;
            else if(x>='A'&&x<='Z') hoa++;
        }
        if(so==0||chu==0||hoa==0) cout<<0;
        else cout<<1;
    }
    else{
        vector<mk> chiso;
        chiso.push_back({0,0,0});
        int so=0,chu=0,hoa=0;
        for(char x:str){
            if(x>='0'&&x<='9') so++;
            else if(x>='a'&&x<='z') chu++;
            else if(x>='A'&&x<='Z') hoa++;
            chiso.push_back({chu,hoa,so});
        }
        if(so==0||chu==0||hoa==0) cout<<0;
        else{
            cout<<dem(chiso,6);
        }
    }
}