/**
 * * Number of Students Unable to Eat Lunch

 * * Example 1
 * * Input  : students = [1,1,0,0], sandwiches = [0,1,0,1]
 * * Output : 0
 * 
 * * Example 2
 * * Input  : students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
 * * Output : 3
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
// * Count students o
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
  std::vector<int> students = {1, 1, 0, 0, 0, 0, 0, 0};
  std::vector<int> sandwiches = {1, 1, 1, 1, 0, 0, 0, 0};
  std::cout << "students = \t";
  printArr(students);
  std::cout << "sandwiches = \t";
  printArr(sandwiches);
  int ans = countStudents(students, sandwiches);
  std::cout << "Number of Students Unable to Eat Lunch " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 26-unable-to-eat-lunch.cpp -o output && ./output