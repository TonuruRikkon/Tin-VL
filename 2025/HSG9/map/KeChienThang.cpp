#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> inp;
	int n,bestsc=-int(1e6);
	string best="";
	cin>>n;
	for(int i=0;i<n;i++){
		string str; int x;
		cin>>str>>x;
		inp[str]+=x;
	}
    for (auto x:inp)
    {
        if(bestsc<x.second){
            bestsc=x.second;
            best=x.first;
        }
    }
    cout<<best;       
}
