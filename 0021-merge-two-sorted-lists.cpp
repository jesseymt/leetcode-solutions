/*
 * LeetCode #0021 - Merge Two Sorted Lists
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Difficulty: Easy
 * Topic: Linked Lists
 * Time: O(M+N) | Space: O(1)
 *
 * Approach:
 * - create dummyHead for merged list
 * - initialize curr to point to dummyHead
 * - compare nodes from both lists and append smaller value
 * - advance curr and selected list pointers
 * - once one list is exhausted, append the remaining nodes of the other list
 * - return dummyHead.next as head of merged list 
 */

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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead;
        ListNode* curr = &dummyHead;
        
        while(list1 != nullptr  && list2 != nullptr){
            if(list1->val <= list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }else{
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        curr->next = (list1 != nullptr)? list1: list2;
        return dummyHead.next;
    }
};