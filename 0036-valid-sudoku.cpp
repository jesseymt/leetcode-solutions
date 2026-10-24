/*
 * LeetCode #0036 - Valid Sudolu
 * https://leetcode.com/problems/valid-sudoku/
 *
 * Difficulty: Medium
 * Topic: Array, Hash Table, Matrix
 * Time: O(1) | Space: O(1)
 *
 * Approach:
 * Traverse the 9x9 board, skipping empty cells.
 * Maintain separate unordered sets for each row, column,
 * and 3x3 box to track previously encountered digits.
 * Calculate the box index using (i / 3) * 3 + (j / 3).
 * Return false if a digit already exists in any of its
 * corresponding sets; otherwise, insert it into all three.
 * Return true if no duplicates are found.
 *
 * Both complexities are O(1) because the board is fixed
 * at 9x9, with at most 81 cells and 9 possible digits.
 *
 * Optimization: Replace hash sets with bool[9][9] arrays
 * to eliminate hashing and dynamic allocation overhead.
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                char num = board[i][j];
                if(num == '.'){
                    continue;
                }
                
                int box = (i/3) * 3 + (j/3);
                if(rows[i].count(num) || cols[j].count(num) || boxes[box].count(num)){
                    return false;
                }
                
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};