#include <vector>
#include <deque>
#include <iostream>
#include <numeric>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int bruteForce(std::vector<int> arr, int k, int threshold) {
  int n = arr.size();
  int ans = 0;
  for(int i = 0; i <= n - k; ++i) {
    int cur_sum = 0;
    for (int j = i; j < i + k; ++j) {
      cur_sum += arr[j];
    }
    if (cur_sum / k >= threshold)
      ans += 1;
  }
  return ans;
}

int numOfSubarrays(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size();
  int ans = 0, i = 0, j = 0;
  long long cur_sum = 0;
  while (j < n) {
    cur_sum += arr[j];

    if(j - i + 1 > k) {
      cur_sum -= arr[i];
      i += 1;
    }
    
    if(j - i + 1 == k) {
      if ((cur_sum / k) >= threshold)
        ans += 1;
    }

    j += 1;
  }
  return ans;
}

int numOfSubarrays2(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size();
  int ans = 0, i = 0, j = 0;
  long long cur_sum = 0;
  long long target_sum = k * threshold;
  for(int i = 0; i < n; ++i) {
    cur_sum += arr[i];
    if (i < k - 1)
      continue;

    if(i > k - 1) {
      cur_sum -= arr[i - k];
    }
    if (cur_sum >= target_sum)
      ans += 1;
  }
  return ans;
}

int numberOfAlternatingGroupsBrute(std::vector<int> &arr, int k) {
  int temp = k;
  while (temp - 1 > 0) {
    arr.push_back(arr[k - temp]);
    temp -= 1;
  }
  printArr(arr);

  int result = 0;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // * if prev element is same then break
      if(arr[j] == arr[j - 1]) {
        break;
      }
      // * if window reached incr the result and break
      if(j - i + 1 == k) {
        result += 1;
        break;
      }
    }
  }

  return result;
}

int numberOfAlternatingGroups(std::vector<int> &arr, int k) {
  int temp = k;
  while (temp - 1 > 0) {
    arr.push_back(arr[k - temp]);
    temp -= 1;
  }
  printArr(arr);

  int result = 0;
  int i = 0 , j = 0;
  int n = arr.size();
  while (j < n) {
    if(j > 0 && arr[j] == arr[j - 1]) {
      i = j;
    }
    if (j - i + 1 == k) {
      i += 1;
      result += 1;
    }

    j += 1;
  }

  return result;
}

int characterReplacement(std::string s, int k) {
  int n = s.size();
  int max_len = 0, max_freq = 0;
  
  int i = 0, j = 0;
  std::vector<int> char_hash(26, 0);
  while(j < n) {
    char_hash[s[j] - 'A']++;
    max_freq = std::max(max_freq, char_hash[s[j] - 'A']);

    if(j - i + 1 - max_freq > k) {
      char_hash[s[i] - 'A']--;
      max_freq = 0;
      i += 1;
    }


    if ((j - i + 1) - max_freq <= k) {
      max_len = std::max(max_len, j - i + 1);
    }
    j += 1;
  }

  return max_len;
}

int main() {
  int k = 1;
  std::string s = "AAAABBA";
  std::cout << "Input String: " << s << std::endl;
  int ans = characterReplacement(s, k);
  std::cout << "Longest Repeating Character Replacement: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output