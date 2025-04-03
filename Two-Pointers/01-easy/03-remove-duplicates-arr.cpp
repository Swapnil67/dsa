/**
 * * Remove Duplicates from Sorted Array
 * * You are given a sorted integer array 'arr' of size 'n'.
 * * You need to remove the duplicates from the array such that each element appears only once.

 * * Example 1
 * * Input  : ‘n’ = 5, ‘a’ = [1 2 2 2 3].
 * * Output : [1 2 3]
 * 
 * * Example 2
 * * Input  : ‘n’ = 10, ‘a’ = [1 2 2 3 3 3 4 4 5 5]
 * * Output : [1 2 3 4 5]

 * * https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307
 * * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

#include <set>
#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Set Data Structure
// * TIME COMPLEXITY O(NLogN) + O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int> arr) {
  std::set<int> st;
  int n = arr.size();
  // * O(N)
  for (int i = 0; i < n; i++) {
    // * logN
    st.insert(arr[i]);
  }

  int idx = 0;
  // * O(N)
  for (int x: st) {
    arr[idx++] = x;
  }

  return idx;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> arr) {
  int n = arr.size(), i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[j] != arr[i]) {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  return i + 1;
}

int main() {
  std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  std::cout<<"Input Vector "<<std::endl;
  printArr(arr);
  // int uniqueElements = bruteForce(arr);
  int uniqueElements = optimalApproach(arr);
  std::cout << "Unique Elements " << uniqueElements << std::endl;
}


// * Run the code
// * g++ --std=c++17 04-remove-duplicates-arr.cpp -o output && ./output
