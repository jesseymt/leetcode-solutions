/*
 * LeetCode #0002 - Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/
 *
 * Difficulty: Med
 * Topic: Linked List / Simulation
 * Time: O(max(n,m)) | Space: O(max(n,m))
 *
 * Approach:
 * 
 * Initial approach:
 * Converted both linked lists into integers, added them,
 * and reconstructed the result list.
 *
 * This failed for large inputs due to integer overflow.
 *
 * Final approach:
 * Add digits directly while tracking carry.
 */

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum=carry;
            
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            
            int lastDig = sum %10;
            carry = sum/10;

            curr->next = new ListNode(lastDig);
            curr = curr->next;
        }
        return dummy.next;
        
    }
};