/*
* Painter's Partition Problem 
* Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list
* represents the length of each board. 
* Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

* You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards 
* under a constraint that any painter will only paint the continuous sections of boards.

* Example 1:
* Input: arr = [2, 1, 5, 6, 2, 3], k = 2
* Output: 11

* Example 2:
* Input: arr = [10, 20, 30, 40], k = 2
* Output: 60

* https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
*/

#include<iostream>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

std::vector<int> findTotalAndMax(std::vector<int> arr) {
  int maxEle = INT_MIN, total = 0;
  for(int i=0; i<arr.size(); i++) {
    maxEle = std::max(maxEle, arr[i]);
    total += arr[i];
  }
  return { maxEle, total };
}

int findPaintersUsed(std::vector<int> boards, int painters, int time) {
  int paintersRequired = 1, boardsPainted = 0;
  for(int i=0; i<boards.size(); i++) {
    if(boardsPainted + boards[i] <= time) {
      // * allocate board to current painter
      boardsPainted += boards[i];
    }
    else {
      // * allocate board to next painter
      paintersRequired++;
      boardsPainted = boards[i];
    }
  }
  return paintersRequired;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(total) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> boards, int painters) {
  std::vector<int> values = findTotalAndMax(boards);
  int maxEle = values[0], total = values[1];
  int ans = total;
  for(int i=maxEle; i<=total; i++) {
    int time = i;
    int paintersUsed = findPaintersUsed(boards, painters, time);
    // std::cout << "Time "<< time << " painters used " << paintersUsed << std::endl;
    if(paintersUsed == painters) {
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
  std::vector<int> values = findTotalAndMax(boards);
  int l = values[0], r = values[1]; 
  // * O(log(total - max)) 
  while(l <= r) {
    int mid = l + (r-l)/2;
    // * O(N) 
    int paintersUsed = findPaintersUsed(boards, painters, mid);
    // std::cout << "Time "<< mid << " painters used " << paintersUsed << std::endl;
    if(paintersUsed <= painters) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  // * testcase 1
  std::vector<int> boards = {2, 1, 5, 6, 2, 3};
  int painters = 2;

  // * testcase 2
  // std::vector<int> boards = {48, 90}; 
  // int painters = 2;

  printArr(boards);
  // int minTime = bruteForce(boards, painters);
  int minTime = findMinTimeToPaintBoards(boards, painters);
  std::cout << "Minimum time required to paint above boards is " << minTime << " units." << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 09-painter-partition.cpp -o 09-painter-partition && ./09-painter-partition