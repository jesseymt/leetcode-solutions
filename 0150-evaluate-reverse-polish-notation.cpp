/*
 * LeetCode #0150 - Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *
 * Difficulty: Medium
 * Topic: Array, Math, Stack
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * Use a vector as a stack to evaluate the postfix expression.
 * Iterate through each token. If it is a number, convert it
 * using stoi() and push it onto the stack.
 * If it is an operator, pop the right operand first, then the
 * left operand, and perform the corresponding operation.
 * Push the result back onto the stack.
 * After processing all tokens, return the remaining value.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(const string& token: tokens){
            if(token == "+" || token == "-" ||token == "*" ||token == "/"){
                int right = stack.back();
                stack.pop_back();

                int left = stack.back();
                stack.pop_back();

                int result;
                
                switch(token[0]){
                    case '+': result = left + right; break;
                    case '-': result = left - right; break;
                    case '*': result = left * right; break;
                    case '/': result = left / right; break;
                }
                stack.push_back(result);
            } else {
                stack.push_back(stoi(token));
            }
        } 
        return stack.back();
    }
};