/*
 * LeetCode #0155 - Min Stack
 * https://leetcode.com/problems/min-stack/
 *
 * Difficulty: Medium
 * Topic: Stack
 * Time: O(N) | Space: O(1)
 *
 * Approach:
 * Use two vectors: one to store stack elements and another
 * to track the minimum value at each position.
 *
 * On push, add the value to the main stack and store the
 * smaller of the new value and previous minimum.
 *
 * On pop, remove the last element from both vectors.
 *
 * The minimum is always available at the back of the
 * minimum vector, allowing constant-time retrieval.
 */

#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> min;

    MinStack() {

    }

    void push(int value) {
        stack.push_back(value);
        if (min.empty()) {
            min.push_back(value);
        } else if (value < min.back()) {
            min.push_back(value);
        } else {
            min.push_back(min.back());
        }
    }

    void pop() {
        stack.pop_back();
        min.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */