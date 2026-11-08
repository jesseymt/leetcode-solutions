/*
 * LeetCode #0121 - Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Difficulty: Medium
 * Topic: Array, Sliding Window, Dynamic Programming
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use two pointers to track the buying and selling days.
 * The left pointer represents the lowest buying price
 * encountered so far, while the right pointer explores
 * potential selling days.
 *
 * If the current selling price is lower than the buying
 * price, update the left pointer to the current day.
 * Otherwise, calculate the potential profit and update
 * the maximum profit if it is greater.
 *
 * Move the right pointer forward on every iteration.
 * Return the maximum profit, or 0 if no profit is possible.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left =0;
        int right = 1;
        int n = prices.size();
        int profit =0;
        
        while(right < n ){
            if(prices[right] < prices[left]){
                left = right;
            }else{
                int tmp = prices[right] - prices[left];
                if(tmp > profit){profit = tmp;}
            }
            right++;
        }
        return profit;
    }
};