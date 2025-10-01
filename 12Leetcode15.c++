// Leetcode 15 
// 3Sum

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> nums){
    // Sorting approach 
    int n = nums.size();
    if(n == 0) return {};
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int k=0; k<n; k++){
        int i = k + 1, j = n - 1;
        if(k>0 && nums[k] == nums[k-1]) continue;
        while(i<j){
            int sum = nums[k] + nums[i] + nums[j];
            if(sum == 0){
                ans.push_back({nums[i], nums[j], nums[k]}); // return in any order
                i++, j--;
                while(i<j && nums[i] == nums[i-1]) i++;
                while(i<j && nums[j] == nums[j+1]) j--;
            }
            else if(sum > 0){
                j--;
            } else {
                i++;
            }
        }
    } 
    return ans;
    // T.C = O(NlogN) + O(N^2) ~ O(N^2) 
    // S.C = O(N) for sorting 
}

int main(){
    int n;
    cout<<"Enter the size of an array";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the nums sequence";
    for(int i=0; i<n; i++) cin>>nums[i];
    vector<vector<int>> ans = solve(nums);
    cout<<"Output: ";
    for(vector<int> &arr: ans){
        for(int num: arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}