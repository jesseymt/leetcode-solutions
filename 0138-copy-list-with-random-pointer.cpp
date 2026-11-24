/*
 * LeetCode #0138 - Copy List with Random Pointer
 * https://leetcode.com/problems/copy-list-with-random-pointer/
 *
 * Difficulty: Medium
 * Topic: Hash Table, Linked List
 * Time: O(n) | Space: O(n)
 *
 * Approach:
 * Use a hashmap to associate each original node with its copied node.
 *
 * Traverse the linked list and dynamically allocate a copy of each
 * node, storing the original and copied pointers in the hashmap.
 *
 * Traverse the original list again and assign the next and random
 * pointers of each copied node using the hashmap.
 *
 * Return the copied head of the linked list.
 */

// Definition for a Node.
#include <unordered_map>
#include <cstddef>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;

        Node* curr = head;

        while(curr != nullptr){
            copies[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr != nullptr){
            copies[curr]->next = copies[curr->next];
            copies[curr]->random = copies[curr->random];
            curr = curr->next;
        }

        return copies[head];
    }
};