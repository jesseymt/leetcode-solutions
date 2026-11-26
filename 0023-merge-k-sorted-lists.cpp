/*
 * LeetCode #0023 - Merge k Sorted Lists
 * https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Difficulty: Hard
 * Topic: Linked List, Divide and Conquer, Heap(Priority Queue), Merge Sort, Tournament Sort
 * Time: O(n log k) | Space: O(k)
 *
 * Approach:
 * Use a min-heap to store the head pointer of each non-empty linked list.
 * Define a custom comparator to prioritize nodes with smaller values.
 *
 * Create a dummy head and a tail pointer to construct the merged list.
 *
 * While the heap is not empty, retrieve and remove the smallest node,
 * append it to the merged list, and advance the tail pointer.
 * If the extracted node has a successor, insert it into the heap.
 *
 * Since each individual list is already sorted, the heap always
 * contains the smallest remaining node from each non-exhausted list.
 * Return the dummy head's next pointer.
 */

#include <queue>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for(auto list: lists){
            if(list != nullptr){
                pq.push(list);
            }
        }
        
        ListNode dummyHead;
        ListNode* tail = &dummyHead;
        
        while(!pq.empty()){
            ListNode* next = pq.top();
            pq.pop();
            tail->next = next;
            tail = next;
            if(next->next != nullptr){
                pq.push(next->next);
            }
        }
        
        return dummyHead.next;
    }
};