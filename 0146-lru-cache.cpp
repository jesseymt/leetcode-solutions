/*
 * LeetCode #0146 - LRU Cache
 * https://leetcode.com/problems/lru-cache/
 *
 * Difficulty: Medium
 * Topic: Hash Table, Linked List, Doubly Linked List
 * Time: O(1) | Space: O(capacity)
 *
 * Approach:
 * Use a doubly linked list to maintain key-value pairs in order of
 * recent usage and an unordered map to store keys and their
 * corresponding list iterators.
 *
 * Maintain the most recently used element at the front of the list
 * and the least recently used element at the back.
 *
 * For get(), return -1 if the key does not exist. Otherwise, use
 * splice() to move the corresponding node to the front and return
 * its value.
 *
 * For put(), update the value and move the node to the front if
 * the key already exists. Otherwise, insert a new pair at the
 * front and store its iterator in the unordered map.
 *
 * If the cache exceeds its capacity, erase the least recently
 * used key from the unordered map and remove the corresponding
 * node from the back of the list.
 */

#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
    int capacity = 0;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        } else {
            lru.splice(lru.begin(), lru, cache[key]);
            return cache[key]->second;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
            return;
        }
        
        lru.push_front({key, value});
        cache[key] = lru.begin();
        
        if(lru.size() > capacity){
            cache.erase(lru.back().first);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
