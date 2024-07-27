#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream input("inp.txt");
    input>>n;
    ofstream output("out.txt");
    map<string,int> acc;
    for (int i = 0; i < n; i++)
    {
        string x;
        input>>x;
        acc[x]++;
        if(acc[x]==1) output<<x<<endl;
        else output<<x<<acc[x]-1<<endl;
    }
    
}