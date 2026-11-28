/*
 * LeetCode #0025 - Reverse Nodes in k-Group
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Difficulty: Hard
 * Topic: Linked List
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use a dummy head and a left pointer to track the node
 * immediately preceding the next group to reverse.
 *
 * Traverse k nodes ahead using a kth pointer to verify
 * that a complete group exists. If fewer than k nodes
 * remain, return the list without modifying them.
 *
 * Initialize curr to the first node of the group and
 * prev to the first node following the group.
 *
 * Reverse the group using the standard three-pointer
 * technique until curr reaches the next group.
 * Initializing prev to groupNext automatically connects
 * the reversed group's tail to the remaining list.
 *
 * Reconnect the preceding node to the new head of the
 * reversed group and move left to the original first
 * node, which is now the tail of the reversed group.
 *
 * Repeat until no complete groups remain.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyHead;
        dummyHead.next = head;
        
        ListNode* left = &dummyHead;
        
        while(true){
            ListNode* kth = left;
            
            for(int i = 0; i < k; i++){
                kth = kth->next;
                if(kth == nullptr){
                    return dummyHead.next;
                }
            }
            
            ListNode* groupNext = kth->next;
            ListNode* curr = left->next;
            ListNode* prev = groupNext;
            ListNode* next = nullptr;
            
            while(curr != groupNext){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            ListNode* oldFirst = left->next;
            left->next = kth;
            left = oldFirst;
        }
    }
};