/*
 * Leetcode - 789
 * Escape The Ghosts
 * 
 * You are playing a simplified Pacman game on a 2D grid. You start at the point (0, 0), and you are 
 * attempting to reach a target point given by target = [x_target, y_target]. There are several ghosts 
 * on the grid, given as a 2D array ghosts, where ghosts[i] = [x_i, y_i] represents the starting position 
 * of the i-th ghost.
 * 
 * In each turn, you and all the ghosts can simultaneously move one unit in any of the four cardinal 
 * directions (north, east, south, or west). That is, from a point (x, y), a move can change the coordinates 
 * to (x + 1, y), (x - 1, y), (x, y + 1), or (x, y - 1). You or any ghost can also choose to stay still.
 * 
 * You escape successfully if you reach the target before any ghost can intercept you. If any ghost 
 * can reach the target at the exact same time or before you, they will trap you, and you cannot escape. 
 * Note that the ghosts know your target and will move optimally to intercept you.
 * 
 * Return true if it is possible to escape, otherwise return false.
 * 
 * Constraints:
 * 1 <= ghosts.length <= 100
 * ghosts[i].length == 2
 * -10^4 <= x_i, y_i, x_target, y_target <= 10^4
 * target.length == 2
 * 
 * Example 1    :
 * Input        : ghosts = [[1,0],[0,3]], target = [0,1]
 * Output       : true
 * Explanation  : You can reach the target at (0, 1) in 1 step. 
 *                The ghost at (1, 0) needs 1 step to reach (0, 1), but you reach it safely.
 *                The ghost at (0, 3) needs 2 steps. Since no ghost reaches before or at the same time, you escape.
 * 
 * Example 2    :
 * Input        : ghosts = [[1,0]], target = [2,0]
 * Output       : false
 * Explanation  : You need 2 steps to reach the target (2, 0). 
 *                The ghost at (1, 0) needs only 1 step to reach (2, 0). It will intercept you.
 *
 * https://leetcode.com/problems/escape-the-ghosts/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]
#define INPUT_VEC(type, name, size) \
    vector<type> name(static_cast<size_t>(size)); \
    for(size_t i = 0; i < name.size(); ++i) cin >> name[i]

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * You need to be closer to target than any ghost to escape.
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool escapeGhosts(vector<vi> &ghosts, vi &target) {
  int pac_dist = abs(0 - target[0]) + abs(0 - target[1]);
  for (auto &g : ghosts) {
    // * Dist of every ghost 'g' to target
    int ghost_dist = abs(g[0] - target[0]) + abs(g[1] - target[1]);
    if (pac_dist >= ghost_dist) // * Ghost can reach target early then pacman cannot escape
      return false;
  }
  return true;
}

int main(void) {
  // * testcase 1
  // vector<vi> ghosts = {{1,0},{0,3}};
  // vi target = {0, 1};

  // * testcase 2
  // vector<vi> ghosts = {{1, 0}};
  // vi target = {2, 0};

  // * testcase 3
  vector<vi> ghosts = {{2, 0}};
  vi target = {1, 0};

  cout << "Ghosts: \n";
  for (auto g : ghosts)
    printArr(g);
  cout << "target: ";
  printArr(target);

  bool escape = escapeGhosts(ghosts, target);
  cout << "Can escape: " << escape << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-escape-the-ghosts.cpp -o output && ./output
