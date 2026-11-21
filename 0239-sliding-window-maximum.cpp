/*
 * LeetCode #0239 - Sliding Window Maximum
 * https://leetcode.com/problems/sliding-window-maximum/
 *
 * Difficulty: Hard
 * Topic: Array, Queue, Sliding Window, Monotonic Queue
 * Time: O(n) | Space: O(k)
 *
 * Approach:
 * Use a sliding window with a monotonic decreasing deque to track
 * indices of potential maximum elements within each window of size k.
 *
 * Iterate through nums using the right pointer. Remove indices from
 * the front of the deque if they fall outside the current window.
 *
 * Remove indices from the back while their corresponding values are
 * less than or equal to the incoming value. These elements cannot
 * become future maximums because the incoming value is both newer
 * and greater than or equal to them.
 *
 * Push the current index onto the back of the deque, maintaining
 * decreasing values from front to back.
 *
 * Once the window reaches size k, append nums[dq.front()] to the
 * result, since the front always holds the maximum element's index.
 *
 * Continue sliding until all elements have been processed.
 */

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int right = 0; right < nums.size(); right++){
            while(!dq.empty() && dq.front() <= right - k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right >= k -1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};