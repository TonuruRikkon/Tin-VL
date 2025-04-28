#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    string s, s1, s2; cin >> s;
    s1 = s.substr(0, s.size()/2);
    s2 = s.substr(s.size()/2, s.size());

    map<char, int> mp1;
    map<char, int> mp2;

    for(char& x : s1) mp1[x]++;
    for(char& x : s2) mp2[x]++;

    cout << s1 << " " << s2 << endl << endl;
    for(auto& x : mp1){
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    for(auto& x : mp2){
        cout << x.first << " " << x.second << endl;
    }
    
    for(auto& x : mp1){
        if(mp1[x.first] > mp2[x.first] && mp1[x.first] - mp2[x.first] != 1){
            s1 = s.substr(0, s.size()/2);
            s2 = s.substr(s.size()/2, s.size());
            mp1[x.first]--;
            mp2[x.first]++;
            break;
        }
        else if(mp2[x.first] > mp1[x.first] && mp2[x.first] - mp1[x.first] != 1){
            s1 = s.substr(0, s.size()/2 + 1);
            s2 = s.substr(s.size()/2 + 1, s.size());
            mp1[x.first]++;
            mp2[x.first]--;
            break;
        }
    }
    
    // cout << s1 << " " << s2 << endl << endl;
    // for(auto& x : mp1){
    //     cout << x.first << " " << x.second << endl;
    // }
    // cout << endl;
    // for(auto& x : mp2){
    //     cout << x.first << " " << x.second << endl;
    // }
    for(auto& x : mp1){
        if(mp1[x.first] > mp2[x.first])
        {
            cout << x.first << endl;
            if(n == 1){
                reverse(s2.begin(), s2.end());
                cout << s2;
            }
            else cout << s2;
            break;
        }
        else if(mp1[x.first] < mp2[x.first])
        {
            cout << x.first << endl;
            if(n == 1){
                reverse(s1.begin(), s1.end());
                cout << s1;
            }
            else cout << s1;
            break;
        }
    }


        // else if(mp1 == mp2){
        //     if(s1.size() > s2.size()){
        //         cout << s1[0] << endl;
        //         cout << s1;
        //         break;
        //     }    
        //     else{
        //         cout << s2[0] << endl;
        //         cout << s2;
        //         break;
        //     }
        // }
    // cout << endl;
    // cout << s1 << " " << s2 << endl;
}