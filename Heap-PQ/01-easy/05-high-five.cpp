/*
 * Leetcode - ?
 * High Five
 * 
 * Given a list of the scores of different students, items, where items[i] = [ID_i, score_i] represents one score from a 
 * student with ID_i, calculate each student's top five average.
 * 
 * Return the answer as an array of pairs result, where result[j] = [ID_j, topFiveAverage_j] represents the student
 * with ID_j and their top five average. Sort result by ID_j in increasing order.

 * A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 
 * using integer division.

 * Example 1
 * input  : items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
 * output : [[1,87],[2,88]]
 * 
 * Example 2
 * input  : items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
 * output : [[1,100],[7,100]]
 * 
 * https://neetcode.io/problems/high-five/
 * https://leetcode.com/problems/high-five/description/
*/

// ! Amazon, Goldman Sachs

#include <map>
#include <queue>
#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}



// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Using max-heap
// * N = no. of elements in items vector.
// * K = Max size of priority_queue
// * M = No. of unique students
// * TIME COMPLEXITY O(NlogK + MlogK)
// * SPACE COMPLEXITY O(M*K)
std::vector<std::vector<int>> bruteForce(std::vector<std::vector<int>> &items) {
  std::map<int, std::priority_queue<int>> score_mp;
  for (auto &result : items) {
    int id = result[0], score = result[1];
    score_mp[id].push(score);
  }

  std::vector<std::vector<int>> ans;
  for (auto &[stu_id, heap] : score_mp) {
    int n = 5, sum = 0;
    while (n--) {
      sum += heap.top();
      heap.pop();
    }
    ans.push_back({stu_id, sum / 5});
  }
  return ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Using max-heap
// * N = no. of elements in items vector.
// * K = Max size of priority_queue
// * M = No. of unique students
// * TIME COMPLEXITY O(NlogK + MlogK)
// * SPACE COMPLEXITY O(MlogK)
std::vector<std::vector<int>> highFive(std::vector<std::vector<int>> &items) {
  std::map<int, std::priority_queue<int, std::vector<int>, std::greater<>>> score_mp;
  for (auto &result : items) {
    int id = result[0], score = result[1];
    score_mp[id].push(score);
    if (score_mp[id].size() > 5)
      score_mp[id].pop();
  }

  std::vector<std::vector<int>> ans;
  for (auto &[stu_id, heap] : score_mp) {
    int n = 5, sum = 0;
    while (n--) {
      sum += heap.top();
      heap.pop();
    }
    ans.push_back({stu_id, sum / 5});
  }
  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> items = {{1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}};
  
  // * testcase 2
  // std::vector<std::vector<int>> items = {{1, 100}, {7, 100}, {1, 100}, {7, 100}, {1, 100}, {7, 100}, {1, 100}, {7, 100}, {1, 100}, {7, 100}};

  // std::vector<std::vector<int>> ans = bruteForce(items);
  std::vector<std::vector<int>> ans = highFive(items);

  std::cout << "High Five" << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-high-five.cpp -o output && ./output