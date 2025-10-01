// Leetcode 39
// Valid Sudoko

#include <bits/stdc++.h>
using namespace std;


bool isValidSudoku(vector<vector<char>> board){
    int n = 9;
    vector<unordered_set<char>> row(n), col(n), boxes(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c = board[i][j];

            if(c == '.') continue;

            int boxIndex = (i / 3) * 3 + (j / 3);

            if(row[i].count(c) || col[j].count(c) || boxes[boxIndex].count(c)){
                return false;
            }

            row[i].insert(c);
            col[j].insert(c);
            boxes[boxIndex].insert(c);
        }
    }
    return true;
}


int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku board (9 lines, 9 characters each, use '.' for empty):\n";
    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;  // read one row (like "53..7....")
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j];
        }
    }

    bool valid = isValidSudoku(board);

    if (valid) cout << "Valid Sudoku\n";
    else cout << "Invalid Sudoku\n";

    return 0;
}


// example input:
// 553.7....
// 6..195...
// .98....6.
// 8...6...3
// 4..8.3..1
// 7...2...6
// .6....28.
// ...419..5
// ....8..79

