/*
 * Leetcode - 703
 * Kth Largest Element in a Stream
 * 
 * You are part of a university admissions office and need to keep track of the kth highest test score from 
 * applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically 
 * as new applicants submit their scores.

 * You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and 
 * continuously returns the kth highest test score after a new score has been submitted. More specifically, 
 * we are looking for the kth highest score in the sorted list of all scores.

 * KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
 * 
 * int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest
 * element in the pool of test scores so far.

 * Example 1
 * input  : ["KthLargest", "add", "add", "add", "add", "add"]
 * output : [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * 
 * Example 2
 * input  : ["KthLargest", "add", "add", "add", "add"]
 * output : [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
 * 
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

class KthLargest {
  priority_queue<int, vector<int>, greater<int>> min_heap;
  int k_count;
public:
  void push(int val, int k) {
    min_heap.push(val);
    if (min_heap.size() > k)
      min_heap.pop();
  }

  KthLargest(int k, vector<int> &nums) {
    k_count = k;
    for (auto &n : nums) {
      push(n, k);
    }
  }
  
  int add(int val) {
    push(val, k_count);
    return min_heap.top();
  }
};


int main() {
  int k = 3;
  vector<int> nums = {4, 5, 8, 2};

  KthLargest *obj = new KthLargest(k, nums);
  cout << obj->add(3) << endl;
  cout << obj->add(5) << endl;
  cout << obj->add(10) << endl;
  cout << obj->add(9) << endl;
  cout << obj->add(4) << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-Kth-largest-element-in-a-stream.cpp -o output && ./output