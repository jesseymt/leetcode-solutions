/*
 * LeetCode #0084 - Largest Rectangle in Histogram
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 *
 * Difficulty: Hard
 * Topic: Array, Monotonic Stack
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * Use a monotonic increasing stack to store indices of histogram bars.
 * Iterate through the heights, popping top indices whenever the current height
 * is smaller than the height at the stack's top.
 *
 * For each popped height bar, calculate its maximum possible rectangle:
 * - The current index is the right boundary.
 * - The new stack top determines the left boundary.
 * - If the stack is empty, the rectangle extends to index 0.
 *
 * Calculate the area and update the maximum.
 *
 * After the iteration, process all remaining indices using the array
 * length as the right boundary, since those bars can extend to the end.
 *
 * Return the largest rectangle area found.
 */

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int largest =0;
        int n = heights.size();
        for(int i =0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int width = st.empty()? i: i - st.top() - 1;
                int area = height * width;
                largest = max(largest, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();

            int width = st.empty()? n: n - st.top() -1;
            int area = height * width;
            largest = max(largest, area);
        }
        return largest;
    }
};