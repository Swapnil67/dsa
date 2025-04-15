#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    printf("[");
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    printf("]");
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int numSubseq(std::vector<int> arr, int target) {
  int n = arr.size();
  int M = 1e9 - 7;
  std::sort(arr.begin(), arr.end());

  int power[n];
  power[0] = 1;
  for(int i = 1; i < n; ++i) {
    power[i] = (2 * power[i - 1]) % M;
  }

  int ans = 0;
  int i = 0, j = n - 1;
  while(i < j) {
    int cur_sum = arr[i] + arr[j];
    if (cur_sum <= target) {
      int diff = j - i;
      ans += power[diff];
      i += 1;
    }
    else {
      j -= 1;
    }
  }
  return ans;
}

int numRescueBoats(std::vector<int> &arr, int limit) {
  int n = arr.size();
  int boats_required = 0;
  std::sort(arr.begin(), arr.end());

  int i = 0, j = n - 1;
  while(i <= j) {
    printf("%d %d\n", arr[i], arr[j]);
    if (arr[i] + arr[j] <= limit) {
      i += 1;
      j -= 1;
    }
    else {
        j -= 1;
    }
    boats_required += 1;
  }
  return boats_required;
}

int kthGrammar(int n, int k) {
  int i = 1, j = pow(2, n - 1);
  int cur = 0;
  while (i < j) {
    int m = (i + j) / 2;
    if(m >= k) {
      j = m;
    }
    else {
      cur = 1 - cur;
      i = m + 1;
    }
  }
  return cur;
}

int bagOfTokensScore(std::vector<int> &tokens, int power) {
  int n = tokens.size();
  std::sort(tokens.begin(), tokens.end());
  int i = 0, j = n - 1;
  int points = 0, max_points = 0;
  while (i <= j) {
    if(tokens[i] <= power) {
      power -= tokens[i];
      points += 1;
      i += 1;
    }
    else {
      if (points >= 1) {
        power += tokens[j];
        points -= 1;
        j -= 1;
      } else {
        return max_points;
      }
    }
    max_points = std::max(max_points, points);
  }
  return max_points;
}

int main() {
  int power = 200;
  std::vector<int> tokens = {100, 200, 300, 400};
  // int power = 150;
  // std::vector<int> tokens = {200, 100};
  std::cout << "Power: " << power << std::endl;
  std::cout << "Tokens: ";
  printArr(tokens);
  int ans = bagOfTokensScore(tokens, power);
  std::cout << "Max Score " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

// * 0 1 2 3
// * 3 2 2 1
// *