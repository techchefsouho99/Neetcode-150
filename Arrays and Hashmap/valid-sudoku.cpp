#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // my solution takign more time but Time complexity O(9*9)
        // unordered_map<int, unordered_set<int>> row;
        // unordered_map<int, unordered_set<int>> col;
        // unordered_map<string, unordered_set<int>> grid;
        // for(int i=0; i<9; i++){
        //     for(int j=0; j<9; j++){
        //         if(board[i][j]=='.')
        //             continue;
        //         int ele = board[i][j] - '0';
        //         string s = to_string(i/3) + "" + to_string(j/3); 
        //         if(row[i].find(ele)!=row[i].end() ||
        //             col[j].find(ele)!=col[j].end() ||
        //             grid[s].find(ele)!=grid[s].end())
        //             return false;
        //         row[i].insert(ele);
        //         col[j].insert(ele);
        //         grid[s].insert(ele);
        //     }
        // }
        // return true;
        
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        // 9 grid are there so first 9 elements then 9 digits to accumulate so 9 x 9
        bool grid[9][9] = {false};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.')
                    continue;
                int ele = board[i][j] - '0' - 1;
                int gridIndex = (i/3) * 3 + (j/3);
                if(rows[i][ele] || cols[j][ele] || grid[gridIndex][ele])
                    return false;
                rows[i][ele] = true;
                cols[j][ele] = true;
                grid[gridIndex][ele] = true;
            }
        }
        return true;
    }
};

int main(){

}