// Leetcode 42
//  Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

int method1(vector<int> arr){
    int n = arr.size();
    int leftmax = 0, rightmax = 0;
    int ans = 0;
    int maxHeight = arr[0];
    int index = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxHeight){
            maxHeight = arr[i];
            index = i;
        }
    }

    for(int i=0; i<index; i++){
        int height = min(maxHeight, leftmax);
        leftmax = max(leftmax, arr[i]);
        ans += max(0, height - arr[i]);
    }

    for(int i = n-1; i>index; i--){
        int height = min(maxHeight, rightmax);
        rightmax = max(rightmax, arr[i]);
        ans += max(0, height - arr[i]);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array sequence"<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = method1(arr);
    cout<<"Output: "<<ans;
    return 0;
}