//Leetcode 217
// Contains Duplicate
// return type is boolean {output}
#include <bits/stdc++.h>
using namespace std;


bool method1(vector<int> arr){
    // brute-force approach
    //using nested loops
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; i++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
    //T.C = O(N^2)
    //S.C = O(1)
}

bool method2(vector<int> arr){
    //using sorting
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            return true;
        }
    }
    return false;
    //T.C = O(NlogN)
    //S.C = O(N)
    // you can use hash-map also
}

bool method3(vector<int> arr){
    // using hash-set
    int n = arr.size();
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        if(s.find(arr[i]) != s.end()){
            return true;
        }
        s.insert(arr[i]);
    }

    // T.C = O(N)
    // S.C = O(N)
}

int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];
    // cout<<"brute force sol: "<<method1(arr);
    // cout<<"using sorting sol: "<<method2(arr);
    cout<<"using hash-set sol: "<<method3(arr);
    return 0;
}