/*
 * Leetcode - 981
 * Time Based Key-Value Store
 * 
 
 * https://leetcode.com/problems/time-based-key-value-store/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
  // * Map -> { key: { value, timestamp } }
  std::unordered_map<string, vector<pair<string, int>>> tmMap;
  TimeMap() { tmMap = {}; }

  void set(string key, string value, int timestamp) {
    tmMap[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    int n = tmMap[key].size();
    if (n == 0)
      return "";

    int l = 0, r = n - 1;
    int idx = -1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      auto [value, timestamp_prev] = tmMap[key][m];

      if (timestamp_prev == timestamp) {
        return value;
      }
      else if (timestamp_prev < timestamp) {
        idx = m;
        l = m + 1;
      }
      else if (timestamp_prev > timestamp) {
        r = m - 1;
      }
    }

    return (idx == -1) ? "" : tmMap[key][idx].first;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */