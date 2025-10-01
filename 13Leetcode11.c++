// Leetcode 11
// Container With Most Water

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr){
    int n = arr.size();
    int i = 0 , j = n - 1;
    int ans = 0;
    while(i < j){
        int value = (j - i) * min(arr[i], arr[j]);
        ans = max(ans, value);
        if(arr[i] > arr[j]) j--;
        else i++;
    }
    return ans;
    // T.C = O(N)
    // S.C = O(1)
}

int main(){
    int n;
    cout<<"Enter the size of an array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array sequence";
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = solve(arr);
    cout<<"Output: "<<ans<<endl;
    return 0;
}