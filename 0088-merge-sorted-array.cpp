/*
 * LeetCode #0088 - Merge Sorted Array
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * Difficulty: Easy
 * Topic: Array, Two Pointers, Sorting
 * Time: O(m+n) | Space: O(1)
 *
 * Approach:
 * Key Idea: Merge two sorted arrays in-place using reverse two-pointer technique to avoid overwriting unprocessed elements.
 * 
 * Use two pointers, starting from the furthest element of both arrays
 * use one pointer for the end of the first array
 * compare elements from each array and place the larger element at the end of nums1
 * iterate backwards
 * copy remaining nums2 elements in nums1
 */

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //start at the furthest element and move back
        int i = m-1;
        int j = n-1; 
        int end = nums1.size() -1;
        while(i >=0 && j>= 0){
            if (nums1[i] >= nums2[j]){
                nums1[end] = nums1[i];
                i--;
                end--;
            }else{
                nums1[end] = nums2[j];
                j--;
                end--;
            }
        }
        //if nums2 has leftover, fill into nums1
        while(j>=0){
            nums1[end] = nums2[j];
            j--;
            end--;
        }
    }
};