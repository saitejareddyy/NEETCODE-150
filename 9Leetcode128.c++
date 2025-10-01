// Leetcode 128
// Longest Consecutive Sequence 

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums){
    // unordered set approach 
    int n = nums.size();
    if(n == 0) return 0;

    unordered_set<int> s(nums.begin(), nums.end());

    int maxi = 0;
    int count = 1;
    for(int x: nums){
        if(s.find(x - 1) == s.end()){
            count = 1;
            int next = x + 1;
            while(s.find(next) != s.end()){
                count++;
                next++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;

    //  T.C = O(N)
    //  S.C = O(N)
}

int main(){
    int n;
    cout<<"Enter the size of an array";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the nums sequence";
    for(int i=0; i<n; i++) cin>>nums[i];
    int result = solve(nums);
    cout<<"Output: Longest Consecutive Sequence is "<<result<<endl;
    return 0;
}