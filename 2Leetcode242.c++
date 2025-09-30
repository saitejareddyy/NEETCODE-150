//Leetcode 242
//Valid Anagram

#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t){
    vector<char> arr(26, 0);
    if(s.length() != t.length()){
        return false;
    }
    int n = s.length();

    for(int i=0; i<n; i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }

    for(int x: arr){
        if(x != 0) return false;
    }
    return true;

    //T.C = O(N);
    //S.C = O(constant) || O(26) || O(1);
    // you can solve using hasn-map, but space complexity increases
}

int main(){
    string s;
    cout<<"enter s string"<<endl;
    getline(cin, s);
    string t;
    cout<<"enter t string"<<endl;
    getline(cin, t); 
    cout<<"output: "<<solve(s, t);
    return 0;
}