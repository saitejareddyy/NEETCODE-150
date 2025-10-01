// Leetcode 167 
// Two Sum II - Input Array Is Sorted
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums, int target){
    int n = nums.size();
    // Two Pointer algorithm
    // because they mentioned array is sorted 
    int i = 0, j = n - 1;
    while(i < j){
        int sum = nums[i] + nums[j];
        if(sum == target){
            return {i+1, j+1}; // 1 based indexing
        }
        else if(sum > target){
            j--;
        } else {
            i++;
        }
    }
    return {}; // empty array
    // T.C = O(N)
    // S.C = O(1)
}

int main(){
    int n, target;
    cout<<"Enter N and target value";
    cin>>n>>target;
    vector<int> nums(n);
    cout<<"Enter the nums sequence in sorted format";
    for(int i=0; i<n; i++) cin>>nums[i];
    vector<int> ans = solve(nums, target);
    cout<<"Output: ";
    for(int x: ans) cout<<x<<" ";
    return 0;
}