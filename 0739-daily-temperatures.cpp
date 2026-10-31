/*
 * LeetCode #0739 - Daily Temperatures
 * https://leetcode.com/problems/daily-temperatures/
 *
 * Difficulty: Medium
 * Topic: Array, Stack, Monotonic Stack
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * Use a monotonic decreasing stack to store indices of days
 * that have not yet found a warmer temperature.
 *
 * Iterate through the temperatures from left to right.
 * While the current temperature is warmer than the temperature
 * at the index on top of the stack, calculate the number of
 * days waited using the difference between their indices.
 * Pop the resolved index and continue checking the stack.
 *
 * Push the current index onto the stack.
 * Days without a warmer temperature retain the default value 0.
 */

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        for(int i =0 ; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};