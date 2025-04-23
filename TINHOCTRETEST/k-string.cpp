#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	for (int i = 0; i < T; i++)
	{
		unordered_set<char> st;
		int k;
		cin>>k;
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			st.insert(s[j]);
		}
		if(st.size() != k){
			cout<<"No"<<"\n";
		}
		else{
			cout<<"Yes"<<"\n";
		}
	}
	return 0;
}