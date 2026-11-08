/*
 * LeetCode #0981 - Time Based Key-Value Store
 * https://leetcode.com/problems/time-based-key-value-store/
 *
 * Difficulty: Medium
 * Topic: Hash Table, String, Binary Search
 * Time: O(log n) | Space: O(n)
 *
 * Approach:
 * Use an unordered_map to associate each string key with a
 * vector of timestamp-value pairs.
 *
 * Since timestamps are strictly increasing, append each new
 * pair to the vector to maintain sorted order.
 *
 * For get(), use binary search to find the largest timestamp
 * less than or equal to the requested timestamp.
 *
 * If an exact match is found, return its value immediately.
 * Otherwise, save the most recent valid value and continue
 * searching right for a potentially newer timestamp.
 *
 * If the timestamp is too large, search the left half.
 * Return an empty string if no valid timestamp exists.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hash;

    TimeMap() {    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = static_cast<int>(hash[key].size()) -1;
        string ans = "";
        while (left <= right){
            int middle = left + (right - left)/2;
            if(hash[key][middle].first == timestamp){
                return hash[key][middle].second;
            }else if(hash[key][middle].first < timestamp){
                ans = hash[key][middle].second;
                left = middle + 1;
            }else{
                right = middle -1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */