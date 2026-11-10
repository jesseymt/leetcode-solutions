/*
 * LeetCode #0141 - Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Difficulty: Easy
 * Topic: Linked List, Two Pointer, Floyd's Cycle Finding Algorithm
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use Floyd's Cycle Detection Algorithm (tortoise and hare)
 * with two pointers initialized at the head of the list.
 *
 * Move the tortoise one node forward and the hare two nodes
 * forward on each iteration.
 *
 * If both pointers meet at the same node, a cycle exists.
 * Compare node addresses rather than their values.
 *
 * If the hare reaches nullptr or its next node is nullptr,
 * the list has no cycle, so return false.
 */

#include <cstddef>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare != nullptr && hare->next != nullptr){
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(tortoise == hare){
                return true;
            }
        }
        return false;
    }
};