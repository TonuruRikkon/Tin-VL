#include <bits/stdc++.h>
using namespace std;

long long calc(int l,int r,int k)
{
	if(k ==0){
		return 0;
	}
	if(l>r){
		return -1e15;
	}
	long long &res = f[l][r][k];
	if(res != -1){
		return res;
	}
	if(l <= r-1){
		res= max(res,
	}
}

int main()
{
	int n,k,inp[301];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>inp[i];
	}

	
}
