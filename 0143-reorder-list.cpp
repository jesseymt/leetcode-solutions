/*
 * LeetCode #0143 - Reorder List
 * https://leetcode.com/problems/reorder-list/
 *
 * Difficulty: Medium
 * Topic: Linked List, Two Pointer
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use slow and fast pointers to locate the middle of the linked list.
 * Slow advances one node while fast advances two nodes per iteration.
 *
 * Split the list into two halves by setting slow->next to nullptr.
 * Reverse the second half using prev, curr, and next pointers.
 *
 * Merge the two halves by alternating nodes from the first half
 * and the reversed second half.
 *
 * Save each node's original next pointer before reconnecting nodes
 * to avoid losing access to the remaining elements.
 *
 * Continue merging until the reversed second half is exhausted.
 * The original linked list is reordered in place without new nodes.
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){return;}

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};