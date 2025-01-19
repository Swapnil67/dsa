/*
* Asteroid Collision
 * We are given an array asteroids of integers representing asteroids in a row. 
 * The indices of the asteriod in the array represent their relative position in space.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction 
 * (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
 * If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 * * Example 1
 * * Input  : asteroids = [5,10,-5]
 * * Output : [5,10]
 * * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
 * 
 * * Example 2
 * * Input  : asteroids = [8,-8]
 * * Output : []
 * * Explanation: The 8 and -8 collide exploding each other.
 * 
 * * Example 1
 * * Input  : asteroids = [10,2,-5]
 * * Output : [10]
 * * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 * 
* https://leetcode.com/problems/asteroid-collision/description/
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * Using Stack
std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
  std::stack<int> st;
  int n = asteroids.size();
  for (int i = 0; i < n; ++i) {
    int cur_asteroid = asteroids[i];
    // * Asteroid Collision 
    while (!st.empty() && cur_asteroid < 0 && st.top() > 0) {
      int sum = st.top() + cur_asteroid;
      if (sum == 0) {
        // * Both asteroids got destoryed
        st.pop();
        cur_asteroid = 0;
      } else if (sum > 0) {
        // * Left asteroids is bigger
        cur_asteroid = 0;
        break;
      } else {
        // * right asteroids is bigger
        st.pop();
      }
    }

    if (cur_asteroid != 0) {
      // * both moving same direction
      st.push(cur_asteroid);
    }
  }

  std::vector<int> ans;
  while(!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

// * Using only vector
std::vector<int> asteroidCollision2(std::vector<int> &asteroids) {
  std::vector<int> ans;
  int n = asteroids.size();
  for (int i = 0; i < n; ++i) {
    int cur_asteroid = asteroids[i];
    // * Asteroid Collision
    while (!ans.empty() && cur_asteroid < 0 && ans[ans.size() - 1] > 0) {
      int sum = ans[ans.size() - 1] + cur_asteroid;
      if (sum == 0) {
        // * Both asteroids got destoryed
        ans.pop_back();
        cur_asteroid = 0;
      } else if (sum > 0) {
        // * Left asteroids is bigger
        cur_asteroid = 0;
        break;
      } else {
        // * right asteroids is bigger
        ans.pop_back();
      }
    }

    if (cur_asteroid != 0) {
      // * both moving same direction
      ans.push_back(cur_asteroid);
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  std::vector<int> asteroids = {5, 10, -5};

  // * testcase 2
  // std::vector<int> asteroids = {8, -8};

  // * testcase 3
  // std::vector<int> asteroids = {10, 2, -5};

  // * testcase 4
  // std::vector<int> asteroids = {-2, -1, 1, 2};

  // * testcase 5
  // std::vector<int> asteroids = {-2, -2, 1, -1};

  // * testcase 6
  // std::vector<int> asteroids = {1, -2, -2, -2};

  printf("Asteroids Before Collision: ");
  printArr(asteroids);

  printf("Asteroids After Collision: ");
  // std::vector<int> ans = asteroidCollision(asteroids);
  std::vector<int> ans = asteroidCollision2(asteroids);
  printArr(ans);

  // printf("Minimum Number of Operations to Make Array Continuous: %d\n", ans);
  // printArr(ans);

  return 0;
}

// * Run the code
// * $CXX --std=c++20 05-asteroid-collision.cpp -o output && ./output