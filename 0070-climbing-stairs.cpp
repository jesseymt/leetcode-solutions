/*
 * LeetCode #0070 - Climbing Stairs
 * https://leetcode.com/problems/climbing-stairs/
 *
 * Difficulty: Easy
 * Topic: Math, Dynamic Programming, Memoization
 * Time: O(N) | Space: O(1)
 *
 * Approach:
 * Use bottom-up dynamic programming based on the Fibonacci pattern.
 * The number of ways to reach step n is the sum of the ways
 * to reach steps n-1 and n-2.
 *
 * Handle the base cases where n <= 2 by returning n.
 * Initialize prev2 = 1 and prev1 = 2.
 *
 * Iterate from step 3 to n, calculating the current number
 * of ways by adding the previous two values.
 * Update prev2 and prev1 for the next iteration.
 *
 * Return prev1, which holds the total number of ways.
 */

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 1 -> 1
        // 2 -> 2
        // 3 -> 3
        // 4 -> 5
        // 5 -> 8
        if(n<=2){
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        for(int i = 3; i <= n; i++){
            int tmp = prev2 + prev1;
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};