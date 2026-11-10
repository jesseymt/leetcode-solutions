/*
 * LeetCode #0206 - Reverse Linked List
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * Difficulty: Easy
 * Topic: Linked List 
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use three pointers to reverse the linked list in place.
 * prev tracks the previous node, curr tracks the current
 * node, and next temporarily stores the following node.
 *
 * For each node, save curr->next before modifying it
 * to avoid losing access to the remaining list.
 *
 * Reverse curr->next to point to prev, then advance
 * prev and curr to continue reversing the list.
 *
 * Once curr reaches nullptr, return prev as the
 * new head of the reversed linked list.
 */

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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};