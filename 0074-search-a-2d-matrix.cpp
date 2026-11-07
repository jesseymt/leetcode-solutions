/*
 * LeetCode #0074 - Search a 2D Matrix
 * https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Difficulty: Medium
 * Topic: Array, Binary Search, Matrix
 * Time: O(M log N) | Space: O(1)
 *
 * Approach:
 * working on optimal approach
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i =0;
        int up = 0;
        int down = m - 1;
        while (up <= down){
            int middle1 = up + (down - up)/2;
            int first = matrix[middle1][0];
            int last = matrix[middle1][n-1];
            if(target >= first && target <= last){
                int left = 0;
                int right = n-1;
                while(left <= right){
                    int middle2 = left + (right - left)/2;
                    if(target == matrix[middle1][middle2]){
                        return true;
                    }else if(target < matrix[middle1][middle2]){
                        right = middle2 - 1;
                    }else{
                        left = middle2 + 1;
                    }
                }
                return false;
            }else if(target < first){
                down = middle1 -1;
            }else if(target > last){
                up = middle1 +1;
            }
        }
        return false;
    }
};