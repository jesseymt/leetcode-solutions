/*
 * LeetCode #0004 - Median of Two Sorted Arrays
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Difficulty: Hard
 * Topic: Array, Binary Search
 * Time: O(M+N) | Space: O(M+N)
 *
 * Approach:
 * - Use two pointers to traverse both sorted arrays.
 * - Merge their elements into a new sorted vector.
 * - Calculate the median using the middle element(s).
 * - For odd lengths, return the middle element.
 * - For even lengths, return the average of the two middle elements.
 * 
 * Note: Does not satisfy the required O(log(M + N)) time complexity.

 */

#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
            vector<int> nums3;
            //compare index with index
            int i =0;
            int j =0;
            while(i < nums1.size() && j<nums2.size()){
                if(nums1[i] <= nums2[j]){
                    nums3.push_back(nums1[i]);
                    i++;
                }else{
                    nums3.push_back(nums2[j]);
                    j++;
                }
            }
            if(i==nums1.size()){
                while(j<nums2.size()){
                    nums3.push_back(nums2[j]);
                    j++;
                }
            }else{
                while(i<nums1.size()){
                    nums3.push_back(nums1[i]);
                    i++;
                }
            }
            int half = nums3.size() / 2;
            double median=0;
            if(totalLength%2 == 0){
                median = (nums3[half] + nums3[half-1]) /2.0;
            }else{
                median = nums3[half];
            }
            return median;
    }
};