// Leetcode 238 
// Product of Array Except Self 

#include <bits/stdc++.h>
using namespace std;

vector<int> method1(vector<int> arr){
    //using division operator
    int n = arr.size();
    vector<int> ans(n, 0);
    int zeros = 0;
    int product = 1;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            zeros++;
        }
        else {
            product *= arr[i];
        }
    }

    if(zeros > 1){
        return ans;
    }
    for(int i=0; i<n; i++){
        if(zeros == 1 && arr[i] == 0){
            ans[i] = product;
        } else {
            if(zeros == 0){
                ans[i] = product / arr[i];
            }
        }
    }

    return ans;
    // T.C = O(N) + O(N) ~ O(N)
    // S.C = O(1) return type itself array
}

vector<int> method2(vector<int> arr){
    // using brute force
    int n = arr.size();
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int product = 1;
        for(int j=0; j<n; j++){
            if(i != j){
                product *= arr[j];
            }
        }
        ans[i] = product;
    }

    return ans;
}

vector<int> method3(vector<int> arr){
    // using prfix and post product algo
    int n = arr.size();
    vector<int> prefix(n), post(n), ans(n);
    for(int i=0; i<n; i++){
        if(i == 0){
            prefix[i] = 1;
        } else {
            prefix[i] = prefix[i-1] * arr[i-1];
        }
    } 
    for(int i=n-1; i>=0; i--){
        if(i == n-1){
            post[i] = 1;
        } else{
            post[i] = post[i+1] * arr[i+1];
        }
    }

    for(int i=0; i<n; i++){
        ans[i] = prefix[i] * post[i];
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
    // vector<int> result = method1(arr);
    // vector<int> result = method2(arr);
    vector<int> result = method3(arr);
    cout<<"Output: "<<endl;
    for(int x: result) cout<<x<<" ";
    return 0;
}