// Leetcode 125
//  Valid Palindrome

#include <bits/stdc++.h>
using namespace std;

bool solve(string s){
    int n = s.length();

    int i = 0, j = n - 1;
    while(i < j){
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }
        i++, j--;
    }
    return true;
    // T.C = O(N)
    // S.C = O(1)
}

int main(){
    string s;
    cout<<"enter the string";
    getline(cin, s);
    bool ans = solve(s);
    string result = ans ? "True" : "False"; 
    cout<<"Output: "<< result;
    return 0;
}