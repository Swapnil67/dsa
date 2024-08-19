/**
 * * Number of Students Unable to Eat Lunch

 * * Example 1
 * * Input  : nums1 = [1,2,2,1], nums2 = [2,2]
 * * Output : [2]
 * 
 * * Example 2
 * * Input  : nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * * Output : [9,4]
 * * Explanation: [4,9] is also accepted.

 * * https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * HashMap
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int countStudents(std::vector<int> students, std::vector<int> sandwiches) {
  int n1 = students.size(), n2 = sandwiches.size();
  int ans = n1;

  // * count student will to eat 1 or 0 sandwiches
  std::map<int, int> studentMap;
  for (int i = 0; i < n1; ++i) {
    studentMap[students[i]]++;
  }

  // * remove student one by one
  for (int i = 0; i < n2; ++i) {
    int val = sandwiches[i];
    if(studentMap[val] > 0) {
      ans--;
      studentMap[val]--;
    }
    else {
      break;
    }
  }

  return ans;
}

int main() {
  std::vector<int> students = {1, 1, 1, 0, 0, 1};
  std::vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
  std::cout << "students = \t";
  printArr(students);
  std::cout << "sandwiches = \t";
  printArr(sandwiches);
  int ans = bruteForce(students, sandwiches);
  std::cout << "Number of Students Unable to Eat Lunch " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 26-unable-to-eat-lunch.cpp -o output && ./output