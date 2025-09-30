// Leetcode 347
// Top k freq elements
#include <bits/stdc++.h>
using namespace std;

vector<int> method1(vector<int> arr, int k){
    // using Heap{Priority Queue} 
    int n = arr.size();
 
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    for(auto it: mp){
        pq.push({it.second, it.first});
        if(pq.size() > k){
            pq.pop();
        }
    }

    vector<int> ans;
    while(!pq.empty()){
        int top = pq.top().second;
        ans.push_back(top);
        pq.pop();
    }

    return ans;

    // T.C = O(n + mlogk + klogk) ~ O(nlogk)
    // S.C = O(m + k + k) ~ O(m + k)
}

int main(){
    int n, k; // 6, 2
    cout<<"Enter the size of an array and K value";
    cin>>n>>k;
    vector<int> arr(n); // 1 1 1 2 2 3
    cout<<"Enter the sequence";
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> result = method1(arr, k);
    cout<<"output: ";
    for(auto x: result) cout<<x<<" ";
    return 0;
}