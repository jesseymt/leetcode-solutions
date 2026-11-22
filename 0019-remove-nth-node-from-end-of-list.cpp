/*
 * LeetCode #0019 - Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Difficulty: Medium
 * Topic: Linked List, Two Pointer
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Create a dummy node pointing to head to handle removal of the first node.
 * Initialize slow and fast pointers at the dummy node.
 *
 * Advance fast by n + 1 nodes to establish a gap between the pointers.
 * Move both pointers forward until fast reaches nullptr, leaving slow
 * immediately before the node to remove.
 *
 * Save the target node, update slow->next to bypass it, and delete
 * the removed node to free its dynamically allocated memory.
 * Return dummyHead.next as the updated head of the list.
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(0, head);
        ListNode* slow = &dummyHead;
        ListNode* fast = &dummyHead;
        
        for(int i = 0; i < n + 1; i++){
            fast = fast->next;
        }
        
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return dummyHead.next;
    }
};
