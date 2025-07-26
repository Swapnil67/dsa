/*
* Painter's Partition Problem 
* Given an array/list of length ‘n’, where the array/list represents the boards and each element of the
* given array/list represents the length of each board. 
* Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a 
* board takes 1 unit of time to paint.

* You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards 
* under a constraint that any painter will only paint the continuous sections of boards.

* Example 1:
* Input: arr = [2, 1, 5, 6, 2, 3], k = 2
* Output: 11

* Example 2:
* Input: arr = [10, 20, 30, 40], k = 2
* Output: 60

* https://leetcode.com/problems/split-array-largest-sum/
* https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int findPaintersUsed(std::vector<int> boards, int &painters, int &maxTime) {
  int paintersRequired = 1, curTime = 0;
  for (int i = 0; i < boards.size(); i++) {
    if (curTime + boards[i] > maxTime) {
      // * allocate board to next painter
      paintersRequired++;
      curTime = boards[i];
    } else {
      // * allocate board to current painter
      curTime += boards[i];
    }
  }
  return paintersRequired <= painters;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(total) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> boards, int painters) {
  int maxEle = *std::max_element(boards.begin(), boards.end());
  int total = accumulate(boards.begin(), boards.end(), 0); 
  int ans = total;
  for (int i = maxEle; i <= total; i++) {
    int time = i;
    int check = findPaintersUsed(boards, painters, time);
    // std::cout << "Time "<< time << " painters used " << check << std::endl;
    if(check) {
      ans = time;
      break;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(total - max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findMinTimeToPaintBoards(std::vector<int> boards, int painters) {
  int l = *std::max_element(boards.begin(), boards.end());
  int r = accumulate(boards.begin(), boards.end(), 0); 

  // * O(log(total - max)) 
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if (findPaintersUsed(boards, painters, mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  // * testcase 1
  // int painters = 2;
  // std::vector<int> boards = {2, 1, 5, 6, 2, 3};

  // * testcase 2
  int painters = 2;
  std::vector<int> boards = {48, 90}; 

  printArr(boards);
  // int minTime = bruteForce(boards, painters);
  int minTime = findMinTimeToPaintBoards(boards, painters);
  std::cout << "Minimum time required to paint above boards is " << minTime << " units." << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 03-painter-partition.cpp -o output && ./output