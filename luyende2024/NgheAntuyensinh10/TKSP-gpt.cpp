#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithAtLeastTwoEqualElements(const vector<int>& arr,int k) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> freq;
        for (int j = i; j < n; ++j) {
            freq[arr[j]]++;
            if (freq[arr[j]] >= k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr ;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int result = countSubarraysWithAtLeastTwoEqualElements(arr,k);
    cout << "Number of subarrays with at least two equal elements: " << result << endl;
    return 0;
}
