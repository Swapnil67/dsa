/*
 * Leetcode - 1508
 * Find Median from Data Stream
 * 
 * The median is the middle value in an ordered integer list. If the size of the list is even, 
 * there is no middle value, and the median is the mean of the two middle values.
 * 
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

 * Implement the MedianFinder class:
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data structure.
 * double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

 * Example 1
 * input  : ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 *          [[], [1], [2], [], [3], []]
 * output : [null, null, null, 1.5, null, 2.0]
 * 
 * https://leetcode.com/problems/find-median-from-data-stream/description/
*/

// ! Google, Meta

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// ! TLE
// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * Using sorting
// * m = no of function calls
// * TIME COMPLEXITY O(m * nlogn)
// * SPACE COMPLEXITY O(n)
class MedianFinderBrute {
public:
  std::vector<int> nums;
  MedianFinderBrute() {
    nums.clear();
  }
  
  void addNum(int num) {
    nums.push_back(num);    
    std::sort(nums.begin(), nums.end());
  }
  
  double findMedian() {
    int n = nums.size();
    int mid = (n / 2);

    if (n % 2 != 0) 
      return (double)nums[mid];

    // std::cout << nums[mid] << " " << nums[mid - 1] << std::endl;
    return (double)(nums[mid] + nums[mid - 1]) / 2;
  }
};

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using min_heap & max_heap
// * m = no of function calls
// * TIME COMPLEXITY O(mlogn)
// * SPACE COMPLEXITY O(n)
class MedianFinder {
public:
  int n;
  std::priority_queue<int, std::vector<int>> small_heap;                 // * max_heap
  std::priority_queue<int, std::vector<int>, std::greater<>> large_heap; // * min_heap
  MedianFinder() {
  }
  
  void addNum(int num) {
    small_heap.push(num);
    
    // * small_heap should always contain values less than large_heap
    if (!large_heap.empty() && small_heap.top() > large_heap.top()) {
      large_heap.push(small_heap.top());
      small_heap.pop();
    }
    
    // * check if diff b/w both the heap are less than 1
    if (small_heap.size() > large_heap.size() + 1) {
      large_heap.push(small_heap.top());
      small_heap.pop();
    }

    // * check if diff b/w both the heap are less than 1
    if (large_heap.size() > small_heap.size() + 1) {
      small_heap.push(large_heap.top());
      large_heap.pop();
    }

    // std::cout << small_heap.size() << " " << large_heap.size() << std::endl;
  }

  double findMedian() {
    // * Even no. of elements
    if (small_heap.size() == large_heap.size()) {
      return (double)(small_heap.top() + large_heap.top()) / 2.0;
    }
    else if (small_heap.size() > large_heap.size()) {
      return (double)small_heap.top();
    }
    return (double)large_heap.top();
  }
};


int main(void) {
  // MedianFinderBrute *medianFinder = new MedianFinderBrute();
  MedianFinder *medianFinder = new MedianFinder();

  medianFinder->addNum(1);    // arr = [1]
  medianFinder->addNum(2);    // arr = [1, 2]
  double ans = medianFinder->findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
  std::cout << "median: " << ans << std::endl;
  medianFinder->addNum(3);    // arr[1, 2, 3]
  ans = medianFinder->findMedian(); // return 2.0
  std::cout << "median: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-find-median-from-data-stream.cpp -o output && ./output