#include <bits/stdc++.h>
using namespace std;
ifstream input("inp.txt");
ofstream output("out.txt");
int main()
{
    int n;
    input>>n;
    map<string,int> e;
    for (int i = 0; i < n; i++)
    {
        string x;
        input>>x;
        e[x]++;
        if(e[x]==1) output<<"OK"<<endl;
        else output<<x<<e[x]-1<<endl;
    }
    
}