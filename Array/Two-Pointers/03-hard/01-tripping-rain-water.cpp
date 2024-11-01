#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> getLeftMaxArray(std::vector<int> &height, int &n) {
  std::vector<int> left_max_i(n);
  left_max_i[0] = height[0];
  for (int i = 1; i < n; ++i) {
    left_max_i[i] = std::max(left_max_i[i - 1], height[i]);
  }
  return left_max_i;
}

std::vector<int> getRightMaxArray(std::vector<int> &height, int &n) {
  std::vector<int> right_max_i(n);
  right_max_i[n-1] = height[n-1];
  for (int i = n - 2; i >= 0; --i) {
    right_max_i[i] = std::max(right_max_i[i + 1], height[i]);
  }
  return right_max_i;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create Two array for left_max_i & right_max_i
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> height) {
  int water = 0, n = height.size();
  std::vector<int> left_max_i = getLeftMaxArray(height, n);
  std::vector<int> right_max_i = getRightMaxArray(height, n);
  printArr(left_max_i);
  printArr(right_max_i);
  for (int i = 0; i < n; ++i) {
    // std::cout << left_max_i[i] << " " << right_max_i[i] << std::endl;
    int h     = std::min(left_max_i[i], right_max_i[i]) - height[i];
    water += h;
  }
  return water;
}

int trap(std::vector<int> height) {
  int n = height.size();
  int l = 0, r = n - 1;
  int max_l = height[l], max_r = height[r];
  int trapped_water = 0;
  while(l <= r) {
    int min_height = std::min(max_l, max_r);
    if(max_l < max_r) {
      // * calculate trapped_water contained
      max_l = std::max(max_l, height[l]);
      trapped_water += max_l - height[l];
      // int val = min_height - height[l];
      // trapped_water += (val < 0) ? 0 : val;
      l++;
    }
    else {
      // * calculate trapped_water contained
      max_r = std::max(max_r, height[r]);
      trapped_water += max_r - height[r];
      // int val = min_height - height[r];
      // trapped_water += (val < 0) ? 0 : val;
      r--;
    }
  }

  return trapped_water;
}
 

int main() {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // std::vector<int> height = {4, 0, 6};     
  // std::vector<int> height = {4, 1, 6};
  printArr(height);
  // int amount = bruteForce(height);
  int amount = trap(height);
  std::cout << "maximum amount of water can trap : " << amount << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-tripping-rain-water.cpp -o output && ./output
