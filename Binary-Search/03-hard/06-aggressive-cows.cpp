/*
* Aggressive Cows
* You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
* You are also given an integer 'k' which denotes the number of aggressive cows.
* You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of 
* them is the maximum possible.
* Return the maximum possible minimum distance.

* Example 1:
* Input: 'cows' = 2 and 'arr' = {1, 2, 3}
* Output: 2

* Example 2:
* Input: 'cows' = 4 and 'arr' = {0, 3, 4, 7, 10, 9};
* Output: 3

* https://www.spoj.com/problems/AGGRCOW/
* https://leetcode.com/problems/magnetic-force-between-two-balls/description/
* https://www.naukri.com/code360/problems/aggressive-cows_1082559
*/

// ! Binary Search on Min/Max

#include<iostream>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

bool findIsPossibleDistance(std::vector<int> stalls, int cows, int distance) {
  int cowsPlaced = 1, lastPlace = stalls[0];
  for (int i = 1; i < stalls.size(); i++) {
    // std::cout << "stalls[i] - lastPlace " << stalls[i] - lastPlace << std::endl;
    // std::cout << "cowsPlaced " << cowsPlaced << std::endl;
    if(stalls[i] - lastPlace >= distance) {
      cowsPlaced++;
      lastPlace = stalls[i];
    }
  }
  return cowsPlaced >= cows;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N(logN)) + O(max - min) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> stalls, int cows) {
  int n = stalls.size();
  // * O(N(logN))
  std::sort(stalls.begin(), stalls.end());
  int ans = stalls[n - 1] - stalls[0];

  // * O(max - min)
  for (int i = 1; i <= stalls[n - 1] - stalls[0]; i++) {
    int distance = i;
    // * O(N) 
    bool isPossibleDistance = findIsPossibleDistance(stalls, cows, distance);
    // std::cout << "distance " << distance << ", isPossibleDistance " << isPossibleDistance << std::endl;
    if(isPossibleDistance) {
      continue;
    }
    else {
      return distance - 1;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N(logN)) + O(log(max - min)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findMinMaxDistance(std::vector<int> stalls, int cows) {
  int n = stalls.size();
  // * O(N(logN))
  std::sort(stalls.begin(), stalls.end());
  int l = 1, r = stalls[n-1] - stalls[0];
  while(l <= r) {
    int mid = l + (r - l) / 2;
    bool isPossibleDistance = findIsPossibleDistance(stalls, cows, mid);
    if(isPossibleDistance) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return r;
}

int main() {
  // * testcase 1
  std::vector<int> stalls = {1, 2, 3};
  int cows = 2;

  // * testcase 2
  // std::vector<int> stalls = {4, 2, 1, 3, 6};
  // int cows = 2;

  // * testcase 3
  // std::vector<int> stalls = {0, 3, 4, 7, 10, 9};
  // int cows = 4;

  std::cout << "Stalls we have" << std::endl;
  printArr(stalls);
  std::cout << "Cows we have " << cows << std::endl;
  // int minMaxDistance = bruteForce(stalls, cows);
  int minMaxDistance = findMinMaxDistance(stalls, cows);
  std::cout << "Min Max Distance b/w cows is " << minMaxDistance << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-aggressive-cows.cpp -o 06-aggressive-cows && ./06-aggressive-cows