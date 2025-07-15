#include <bits/stdc++.h>
using namespace std;

vector<int> ngto;
vector<unsigned long long> tamto;
vector<bool> isNgto(int(1e7),true);

void sangnt()
{
	isNgto[0]=isNgto[1]=false;
	for(int i=2;i<=sqrt(int(1e6));i++){
		if(isNgto[i]==true)
		{
			for(int j=i*i;j<int(1e6);j+=i){
				isNgto[j]=false;
			}
			ngto.push_back(i);
		}
	}
}
void sangtt()
{
	for(int i=0; i<ngto.size();i++)
	{
		tamto.push_back(ngto[i]*ngto[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("SDB.INP", "r", stdin);
	//freopen("SDB.OUT", "w", stdout);
	int n;
	cin>>n;
	sangnt();
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		unsigned long long it=*lower_bound(ngto.begin(),ngto.end(),ceil(sqrt(x)));
		cout<<it*it<<' ';
	}
	return 0;
}
