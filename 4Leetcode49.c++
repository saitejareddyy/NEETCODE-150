// Leetcode 49
// Group Anagrams
#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> method1(vector<string> strs){
    // using sorting 
    unordered_map<string, vector<string>> mp;
    for(string s: strs){
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> ans;

    for(auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
    // T.C = O(N*MlogM)
    // T.C = O(N)
}

vector<vector<string>> method2(vector<string> strs){
    // using freq count;
    unordered_map<string, vector<string>> mp;

    for(string s: strs){
        vector<int> freq(26, 0);
        for(char c: s){
            freq[c-'a']++;
        }

        string key = "";
        for(int i: freq){
            key += "#" + to_string(i);
        }

        mp[key].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
    // T.C = O(N*M)
    // T.C = O(N)
}

int main(){
    int n;
    cout<<"Enter the no_of strings";
    cin>>n;
    vector<string> strs(n); // {eat, tea, tan, ate, nat, bat} n = 6
    cout<<"enter the strings";
    for(int i=0; i<n; i++) cin>>strs[i];
    // vector<vector<string>> result = method1(strs);
    vector<vector<string>> result = method2(strs);
    for(auto arr: result){
        for(auto s: arr){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}