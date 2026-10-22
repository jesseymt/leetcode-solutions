/*
 * LeetCode #0004 - Median of Two Sorted Arrays
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Difficulty: Hard
 * Topic: Array, Binary Search
 * Time: O(log(ming(M+N))) - binary search the smaller array | Space: O(1) - constant number of variables
 *
 * Approach:
 * - Binary search the smaller array to find the correct partition.
 * - Divide both arrays into left and right halves.
 * - Validate the partition using the boundary elements.
 * - Adjust the binary search bounds until a valid partition is found.
 * - Calculate the median from the partition boundaries.
 *
 */

#include <vector>
#include <algorithm> // min, max, 
#include <climits> // INT_MIN, INT_MAX
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(); 
        int n = nums2.size();
        int totalLeft = (m + n + 1) /2;

        int low = 0;
        int high = m; // smaller vector

        double median;
        while (low<=high){
            int partition1 = low + (high-low)/2;
            int partition2 = totalLeft - partition1;

            int left1 = (partition1==0)? INT_MIN: nums1[partition1-1]; //left bound
            int right1 = (partition1==m)? INT_MAX: nums1[partition1]; //right bound
            int left2 = (partition2==0)? INT_MIN: nums2[partition2-1];
            int right2 = (partition2==n)? INT_MAX: nums2[partition2];

            if(left1 <= right2 && left2 <= right1){
                if((m+n) % 2 == 0){
                    return median = ((double)max(left1, left2) + min(right1, right2))/2.0;
                }else{
                    return max(left1, left2);
                }
            }else if(left1 > right2){
                high = partition1 -1;
            }else if(left2 > right1){
                low = partition1 + 1; 
            }
        }
        return 0.0;
    }
};