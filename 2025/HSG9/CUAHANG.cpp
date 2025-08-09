#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,best=0,top=0;
	long long tol=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		tol+=x;
		if(best<x){
			best=x;
			top=i;
		}
	}
	cout<<tol<<"\n"<<top;
}
