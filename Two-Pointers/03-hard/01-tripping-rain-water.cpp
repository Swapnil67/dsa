#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

vector<int> getLeftMaxArray(vector<int> &height, int &n) {
  vector<int> left_max_i(n);
  left_max_i[0] = height[0];
  for (int i = 1; i < n; ++i) {
    left_max_i[i] = max(left_max_i[i - 1], height[i]);
  }
  return left_max_i;
}

vector<int> getRightMaxArray(vector<int> &height, int &n) {
  vector<int> right_max_i(n);
  right_max_i[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    right_max_i[i] = max(right_max_i[i + 1], height[i]);
  }
  return right_max_i;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Create Two array for left_max_i & right_max_i
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> height) {
  int water = 0, n = height.size();
  vector<int> left_max_i = getLeftMaxArray(height, n);
  vector<int> right_max_i = getRightMaxArray(height, n);
  // printArr(left_max_i);
  // printArr(right_max_i);
  for (int i = 0; i < n; ++i) {
    // cout << left_max_i[i] << " " << right_max_i[i] << endl;
    int h = min(left_max_i[i], right_max_i[i]) - height[i];
    water += h;
  }
  return water;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Create Two array for left_max_i & right_max_i
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int trap(vector<int> height) {
  int n = height.size();
  int l = 0, r = n - 1;
  int trapped_water = 0;
  int max_l = height[l], max_r = height[r];
  while (l <= r) {
    if (max_l < max_r) {
      // * calculate trapped_water contained
      max_l = max(max_l, height[l]);
      trapped_water += max_l - height[l];
      l++;
    }
    else {
      // * calculate trapped_water contained
      max_r = max(max_r, height[r]);
      trapped_water += max_r - height[r];
      r--;
    }
  }
  return trapped_water;
}
 

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> height = {4, 0, 6};     
  // vector<int> height = {4, 1, 6};
  std::cout << "Height: ";
  printArr(height);

  // int amount = bruteForce(height);
  int amount = trap(height);

  cout << "maximum amount of water can trap : " << amount << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 01-tripping-rain-water.cpp -o output && ./output
