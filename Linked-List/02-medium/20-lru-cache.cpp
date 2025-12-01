/*
 * Leetcode - 146
 * LRU Cache
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

 * Implement the LRUCache class:
 * - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * - int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * - void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
 *   add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
 *   evict the least recently used key.
 * 
 * The functions get and put must each run in O(1) average time complexity.

 * https://leetcode.com/problems/lru-cache/description/
 * https://www.geeksforgeeks.org/problems/lru-cache/1
 * https://www.naukri.com/code360/problems/lru-cache-implementation_670276
*/

// ! Microsoft, Amazon

#include <vector>
#include <iostream>
#include <unordered_map>

class ListNode {
public:
  int data;
  int key;
  ListNode *next;
  ListNode *prev;

  ListNode(int k, int v) {
    this->key = k;
    this->data = v;
    this->next = NULL;
    this->prev = NULL;
  }
};

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use pair of vector
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
class LRUCacheBrute {
public:
  int n;
  std::vector<std::pair<int, int>> cache;
  LRUCacheBrute(int capacity) {
    n = capacity;
  }
    
  int get(int key) {
    for (int i = 0; i < cache.size(); ++i) {
      if (key == cache[i].first) {
        std::pair<int, int> temp = cache[i];
        cache.erase(cache.begin() + i);

        cache.push_back(temp);
        
        return temp.second;
      }
    }
    return -1;
  }
  
  void put(int key, int value) {
    // * Check if key already exists
    for (int i = 0; i < cache.size(); ++i) {
      if (cache[i].first == key) {
        cache.erase(cache.begin() + i);
        cache.push_back({key, value});
        return;
      }
    }
    
    // * not present in cache
    if (cache.size() == n) {
      // * cache is full
      cache.erase(cache.begin());
      cache.push_back({key, value});
    } else {
      // * new entry to cache
      cache.push_back({key, value});
    }
  }
};

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Use DLL
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
class LRUCache {
public:
    int n;
    ListNode *head = new ListNode(-1, -1);
    ListNode *tail = new ListNode(-1, -1);
    std::unordered_map<int, ListNode*> cache;

    LRUCache(int capacity) {
      n = capacity;
      cache.clear();

      head->next = tail;
      tail->prev = head;
    }

    void deleteNode(ListNode* node) {
      ListNode* front = node->next;
      ListNode* back = node->prev;
      back->next = front;
      front->prev = back;
    }

    void insertAtHead(ListNode* node) {
      ListNode* head_next = head->next;
      node->next = head_next;
      head_next->prev = node;

      // * point head next to new node
      head->next = node;
      // * point new node prev to head
      node->prev = head;
    }

    int get(int key) {
      // std::cout << "--- get ---" << std::endl;
      // std::cout << "cache size " << cache.size() << std::endl;
      // * cache does not exits
      if (!cache.count(key))
        return -1;

      ListNode* node = cache[key];
      deleteNode(node);
      insertAtHead(node);

      // std::cout << node->data << std::endl;
      return node->data;
    }

    void put(int key, int value) {
        // std::cout << "put" << std::endl;
        if (cache.count(key) > 0) {
          // * Update the existing node
          ListNode* node = cache[key];
          node->data = value;
          cache[key] = node;
          
          // * Update the LRU DLL
          deleteNode(node);
          insertAtHead(node);
        } else {
          // std::cout << "cache size: " << cache.size() << std::endl;
          if (n == cache.size()) { // * Cache is full remove LRU node
                ListNode* node = tail->prev;
                // std::cout << "Erase node: " << node->data << std::endl;
                cache.erase(node->key);
                deleteNode(node);
            }
            ListNode* newNode = new ListNode(key, value);
            insertAtHead(newNode);
            cache[key] = newNode;
        }
    }
};

int main() {
  int capacity = 5;
  // LRUCacheBrute* obj = new LRUCacheBrute(capacity);
  LRUCache* obj = new LRUCache(capacity);
  int ans = obj->get(1);
  std::cout << ans << std::endl;
 
  obj->put(1, 1);
  obj->put(2, 2);

  ans = obj->get(1);
  std::cout << ans << std::endl;

  ans = obj->get(2);
  std::cout << ans << std::endl;

  obj->put(3, 3);
  obj->put(4, 4);
  obj->put(5, 5);
  obj->put(6, 6);
  
  ans = obj->get(1);
  std::cout << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 20-lru-cache.cpp -o output && ./output

