/*
 * Leetcode - 2751
 * Robot Collisions
 * 
 * If two robots collide, the robot with lower health is removed from the line, 
 * and the health of the other robot decreases by one. 
 * The surviving robot continues in the same direction it was going. 
 * If both robots have the same health, they are both removed from the line.
 * 
 * 
 * Note: The positions may be unsorted.

 * Example 1
 * * Input       : positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
 * * Output      : [2,17,9,15,10]
 * 
 * 
 * Example 2
 * * Input       : positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
 * * Output      : [14]
 * 
 * Example 3
 * * Input       : positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
 * * Output      : []
 * 
 * Example 4
 * * Input       : positions = [4, 37, 23], healths = [50, 15, 49], directions = "RLR"
 * * Output      : [50, 48]
 * 
 * https://leetcode.com/problems/maximum-frequency-stack/description/
*/

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric> // Required for std::iota

using namespace std;

void printArr(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(N) + O(nlogn)
// * SPACE COMPLEXITY O(N)
vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
  int n = positions.size();

  vector<int> actual_idx_vec(n);
  iota(begin(actual_idx_vec), end(actual_idx_vec), 0);

  
  // * Sort the index according to position vector
  auto lamda = [&](int &i, int &j) {
    return positions[i] < positions[j];
  };
  sort(begin(actual_idx_vec), end(actual_idx_vec), lamda); // * O(nlogn)
  // printArr(actual_idx_vec);
  
  vector<int> ans;
  stack<int> st;
  for(int &cur_idx : actual_idx_vec) { // * Any idx is visited atmost twice
    if(directions[cur_idx] == 'R')  {
      st.push(cur_idx);
    }
    else {
      while(!st.empty() && healths[cur_idx] > 0) {
        int top_idx = st.top();
        st.pop();

        if(healths[top_idx] > healths[cur_idx]) {
          healths[top_idx] -= 1;
          healths[cur_idx] = 0;    // * cur got destoryed
          st.push(top_idx);
        }
        else if(healths[top_idx] < healths[cur_idx]) {
          healths[cur_idx] -= 1;
          healths[top_idx] = 0;
        }
        else {
          // * both robots have same health
          healths[top_idx] = 0;
          healths[cur_idx] = 0;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i) {
    if (healths[i] > 0)
      ans.push_back(healths[i]);
  }

  return ans;
}

int main() {
  // vector<int> positions = {5,4,3,2,1}, healths = {2,17,9,15,10};
  // std::string directions = "RRRRR";

  // vector<int> positions = {1, 2, 5, 6}, healths = {10, 10, 11, 11};
  // std::string directions = "RLRL";

  // vector<int> positions = {3, 5, 2, 6}, healths = {10, 10, 15, 12};
  // std::string directions = "RLRL";

  // vector<int> positions = {3, 47}, healths = {46, 26};
  // std::string directions = "LR";

  vector<int> positions = {4, 37, 23}, healths = {50, 15, 49};
  std::string directions = "RLR";

  printf("Positions: ");
  printArr(positions);
  printf("Healths: ");
  printArr(healths);
  std::cout << "Direction: " << directions << std::endl;

  vector<int> ans = survivedRobotsHealths(positions, healths, directions);
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 02-robot-collisions.cpp -o output && ./output
