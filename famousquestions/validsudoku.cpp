
#include <bits/stdc++.h>
using namespace std;

 bool isValidSudoku(vector<vector<char>>& board) {
        // check each row
        for(int row = 0 ; row < 9 ; row++){
            unordered_set<char>checkrow;
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col] != '.' && checkrow.find(board[row][col]) != checkrow.end()){
                    return false;
                }
                checkrow.insert(board[row][col]);
            }
        }
        // check each col
        for(int col = 0 ; col < 9 ; col++){
            unordered_set<char>checkcol;
            for(int row = 0 ; row< 9 ; row++){
                if(board[row][col] =='.')continue;
                if(checkcol.find(board[row][col]) != checkcol.end()){
                    return false;
                }
                checkcol.insert(board[row][col]);
            }
        }

        // check each 3*3 matrix;

     // we have 9 sub boxes  of (3*3)
     vector<unordered_set<char>>subbox(9);
     for(int row = 0 ; row<9 ; row++){
        for(int col = 0 ; col < 9 ; col++){
            // index of each 9 subboxes  we can mark it as outer inedex will always be betwween 0 and 2
            
            int location = ((row/3)*3)+(col/3);
            if(board[row][col]=='.')continue;
            if(subbox[location].find(board[row][col]) != subbox[location].end()){
                return false;
            }
            else {
                subbox[location].insert(board[row][col]);
            }
        }
     }


return true;

    }

int main (){
    vector<vector<char>>board;
    for(int i = 0 ; i < 9 ; i++){
        for(int j =0 ; j < 9 ; j++){
            char c ; cin >> c ;
            board[i][j] = c;
        }
    }
    bool ans = isValidSudoku(board);
    cout << ans << endl;

    return 0;
}