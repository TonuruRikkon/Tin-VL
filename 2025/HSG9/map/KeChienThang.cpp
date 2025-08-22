#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	unordered_map<string,pair<long long,int>> inp,bst;
	long long n,bestsc=-int(1e6),pos=int(1e6);
	string best="";
	cin>>n;
	for(int i=0;i<n;i++){
		string str; long long x;
		cin>>str>>x;
		inp[str]={inp[str].first+x,i};
		if(bst[str]<inp[str]) bst[str]=inp[str];
	}
    for (auto x:inp)
    {
		cout<<x.first<<':'<<x.second.first<<','<<x.second.second<<'\n';
        if(bestsc<x.second.first){
			pos=bst[x.first].second;
			bestsc=x.second.first;
            best=x.first;
        }
		else if(bestsc==x.second.first){
			if(pos>bst[x.first].second){
				best=x.first;
				pos=x.second.second;
			}
		}
    }
    cout<<best;       
}
