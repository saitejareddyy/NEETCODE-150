//Leetcode 1
//Two Sum
#include <bits/stdc++.h>
using namespace std;

vector<int> method1(vector<int> arr, int target){
    //brute-force solution 
    //using nested loops
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return {i, j};
            }
        }
    }
    return {};
    // T.C = O(N^2)
    // S.C = O(1)
}


vector<int> method2(vector<int> arr, int target){
    //using:  Sorting + BinarySearch
    sort(arr.begin(), arr.end());
    //Binary Search algo
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int left = i, right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int value = target - arr[i];
            if(arr[mid] == value){
                return {i, mid};
            }
            else if(arr[mid] > value){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return {};
    // T.C = O(NlogN)
    // S.C = O(N) for sorting
}

vector<int> method3(vector<int> arr, int target){
    // using HashMap
    // HashMap consumes O(1) time for insertion and find 
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int comp = target - arr[i];
        if(mp.find(comp) != mp.end()){
            return {i, mp[comp]};
        }
        mp[arr[i]] = i;
    }
    return {};
    //T.C = O(N)
    //S.C = O(N) 
}

int main(){
    int n, target;
    cout<<"Enter array size && target value: "<<endl;
    cin>>n>>target;
    vector<int> arr(n);
    cout<<"Enter array sequence: "<<endl;
    for(int i=0; i<n; i++)cin>>arr[i];
    // vector<int> ans = method1(arr, target);
    // vector<int> ans = method2(arr, target);
    vector<int> ans = method3(arr, target);
    cout<<"index of nums: "<<endl; 
    for(int x: ans) cout<<x<<" ";   
    return 0;
}