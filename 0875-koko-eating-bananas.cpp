/*
 * LeetCode #0875 - Koko Eating Bananas
 * https://leetcode.com/problems/koko-eating-bananas/
 *
 * Difficulty: Medium
 * Topic: Array, Binary Search
 * Time: O(N log M) | Space: O(1)
 *
 * Approach:
 * * Use binary search on the possible eating speeds (k).
 * Set left = 1 and right = the largest pile.
 *
 * For each midpoint k, calculate the total hours needed
 * using ceiling division for each pile.
 *
 * If totalHrs <= h, save k as a valid answer and search
 * for a smaller eating speed. Otherwise, increase k
 * by searching the right half.
 *
 * Return the minimum valid eating speed.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0; 
        while (left <= right){
            int k = left + (right - left)/2;
            long long totalHrs = 0;
            for(int bananas: piles){
                totalHrs += bananas /k + (bananas % k != 0);
            }
            if(totalHrs <= h){
                ans = k;
                right = k-1;
            }else{
                left = k+1;
            }
        }
        return ans;
    }
};