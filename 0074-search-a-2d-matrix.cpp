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
        for(int i=0; i < m; i++){
            int left = 0;
            int right = n - 1;
            while(left <= right){
                int middle = left + (right - left)/2;
                int num = matrix[i][middle];
                if(num == target){
                    return true;
                }else if(num < target){
                    left = middle + 1;
                }else{
                    right = middle - 1;
                }
            }
        }
        return false;
    }
};