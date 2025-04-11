#include <iostream>
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

void calculatePowers(std::vector<int> &powers, int n) {
  powers[0] = 1;
  int i = 1;
  while(n > 0) {
    powers[i] = powers[i - 1] * 2;
    i += 1;
    n -= 1;
  }
}

int numSubseq(std::vector<int> arr, int target) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  std::vector<int> powers(n);
  calculatePowers(powers, n);

  int ans = 0;
  int M = 1e9 + 7; // * 10^9 + 7

  int i = 0, j = n - 1;
  while (i <= j) {
    long long cur_sum = arr[i] + arr[j];
    if(cur_sum <= target) {
      int diff = j - i;
      ans = ans % M + powers[diff] % M;
      i += 1;
    }
    else {
      j -= 1;
    }
  }
  return ans;
}

int numRescueBoats(std::vector<int> weights, int limit) {
  int n = weights.size();
  int boats_required = 0;

  std::sort(weights.begin(), weights.end());
  
  int i = 0, j = n - 1;
  while(i <= j) {
    int cur_weight = weights[i] + weights[j];
    if (cur_weight <= limit) {
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

}

int main() {
  int n = 4, k = 8;
  int ans = kthGrammar(n, k);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output