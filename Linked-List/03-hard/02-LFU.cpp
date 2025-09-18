#include <map>
#include <list>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

// ! TLE
class LFUCacheBrute {
  struct Node {
    int value, freq, timestamp;
    Node(int v, int f, int t) : value(v), freq(f), timestamp(t) {}
  };

  int capacity, timestamp;
  std::unordered_map<int, Node *> cache;

public:

  LFUCacheBrute(int capacity) : capacity(capacity), timestamp(0) {}

  int get(int key) {
    // * check if key already exists
    if (cache.find(key) == cache.end())
      return -1;

    // * Increase the freq
    cache[key]->freq++;

    // * Add the new timestamp
    cache[key]->timestamp = ++timestamp;

    // * return the value
    return cache[key]->value;
  }
  
  void put(int key, int value) {
    if (capacity <= 0)
      return;

    timestamp++;

    // * Update the existing `key`
    if (cache.find(key) != cache.end()) {
      cache[key]->value = value;
      cache[key]->freq++;
      cache[key]->timestamp = timestamp;
      return;
    }

    if (cache.size() >= capacity) {
      int minFreq = INT_MAX, minTimestamp = INT_MAX, lfuKey = -1;
      for(const auto &[k, node]: cache) {
        if (node->freq < minFreq ||
            (node->freq == minFreq && node->timestamp < minTimestamp))
        {
          minFreq = node->freq;
          minTimestamp = node->timestamp;
          lfuKey = k;
        }
      }

      delete cache[lfuKey];
      cache.erase(lfuKey);
    }

    cache[key] = new Node(value, 1, timestamp);
  }

};

class LFUCache {
  struct DLLNode {
    int val;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int val) : val(val), prev(nullptr), next(nullptr) {};
    DLLNode(int val, DLLNode *prev, DLLNode *next) : val(val), prev(prev), next(next) {};
  };

  struct DLLinkedList {
    DLLNode *left;
    DLLNode *right;
    std::unordered_map<int, DLLNode*> mp;

    // * constructor
    DLLinkedList() {
      // * create dummy head & tail pointers
      left = new DLLNode(0); 
      right = new DLLNode(0); 

      // * link head to tail & vice versa
      left->next = right;
      right->prev = left;
    } 

    // * destructor
    ~DLLinkedList() {
      // * delete nodes b/w left & right
      while (left->next != right) {
        DLLNode *temp = left->next;
        left->next = temp->next;
        delete temp;
      }

      // * Delete left & right node
      delete left;
      delete right;
    } 

    // * Add the node to right of DLL
    void pushToRight(int val) {
      DLLNode* node = new DLLNode(val, right->prev, right);
      mp[val] = node;
      right->prev->next = node;
      right->prev = node;
    }

    // * Remove the node from DLL & map
    void pop(int val) {
      // * if exists in map the delete node
      if (mp.find(val) == mp.end()) {
        return;
      }

      DLLNode *node = mp[val];
      DLLNode *back = node->prev;
      DLLNode *front = node->next;
      back->next = front;
      front->prev = back;

      mp.erase(val);
      delete node;
    }

    // * From the front of DLL
    int popLeft () {
      int res = left->next->val;
      pop(res);
      return res;
    }

    int length() {
      return mp.size();
    }
  };

  int capacity;
  int lfu_count;
  std::unordered_map<int, int> val_map;               // * Map key -> value
  std::unordered_map<int, int> count_map;             // * Map key -> count
  std::unordered_map<int, DLLinkedList*> list_map;    // * Map count -> linked list

  void counter(int key) {
    // * Incr the key count
    int count = count_map[key];
    int new_count = count + 1;
    count_map[key] = new_count; // * Incr the count freq

    // * Remove the key from DLL
    list_map[count]->pop(key);

    // * check if DLL exists on new_count 
    if (!list_map.count(new_count)) {
      list_map[new_count] = new DLLinkedList();   // * create new DLL
    }
    list_map[new_count]->pushToRight(key);

    // * Incr the lfu_count becoz all the nodes in previous count has been removed/deleted
    if (count == lfu_count && list_map[count]->length() == 0) {
      lfu_count++;
    }
  }

public:
  LFUCache(int capacity) : capacity(capacity), lfu_count(0) {
    list_map[0] = new DLLinkedList();
  }

  ~LFUCache() {
    for (auto &pair : list_map) {
      delete pair.second;
    }
  }

  int get(int key) {
    // * key is not in map
    if (val_map.find(key) == val_map.end())
      return -1;

    counter(key); // * This key was accessed
    return val_map[key];
  }
  
  void put(int key, int value) {
    if (capacity == 0)
      return;

    // * Key does not exists & cache Capacity reached
    if (val_map.find(key) == val_map.end() && val_map.size() == capacity) {
      // * Remove the least frequently used key
      int toRemove = list_map[lfu_count]->popLeft();
      // * Erase the key from respective maps
      val_map.erase(toRemove);
      count_map.erase(toRemove);
    }

    val_map[key] = value;
    // * Update the frequecy of that key
    if (count_map.find(key) == count_map.end()) {
      count_map[key] = 0;
      list_map[0]->pushToRight(key);
      lfu_count = 0;
    }

    counter(key);
  }
};

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-LFU.cpp -o output && ./output