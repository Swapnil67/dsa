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

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
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

bool bruteForceStringEqual(std::vector<std::string> word1, std::vector<std::string> word2){
  int n1 = word1.size(), n2 = word2.size();
  std::string str1 = "", str2 = "";
  for (std::string str :  word1) {
    str1 += str;
  }
  for (std::string str :  word2) {
    str2 += str;
  }
  return str1 == str2;
}

bool arrayStringsAreEqual(std::vector<std::string> word1, std::vector<std::string> word2){
  int n1 = word1.size(), n2 = word2.size();
  int i = 0, j = 0;
  int ii = 0, jj = 0;
  while(i < n1 && j < n2) {
    // printf("%d %d & %d %d\n", i, ii, j, jj);
    if(word1[i][ii] != word2[j][jj]) {
      return false;
    }
    ii += 1;
    jj += 1;

    if (ii >= word1[i].size() && i < n1) {
      i += 1;
      ii = 0;
    }
    if (jj >= word2[j].size() && j < n2) {
      j += 1;
      jj = 0;
    }
  }

  if (i != n1 || j != n2)
    return false;

  return true;
}

void reverseString(std::string &s, int l, int r) {
  while (isspace(s[r]))
    r -= 1;
  while(l < r) {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    l += 1;
    r -= 1;
  }
}

std::string reverseWords(std::string s) {
  int n = s.size();
  int l = 0, r = n - 1;
  reverseString(s, l, r);

  std::cout << s << std::endl;
  int i = 0;
  l = 0, r = 0;

  while(i < n) {
    // * move i till you hit space character
    if (!isspace(s[i])) {
      i += 1;
    }
    else {
      // printf("%d %d %d\n", i, l, r);
      r = i;
      reverseString(s, l, r);
      r += 1;
      l = r;
      // * move i to first character of next word
      while (isspace(s[i]))
        i += 1;
    }
  }
  return s;
}

int minTimeToMakeRopeColorful(std::string s, std::vector<int> neededTime) {
  int prev_max = 0;
  int n = s.size();
  int time = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && s[i] != s[i - 1]) {
      prev_max = 0;
    }

    time = time + min(prev_max, neededTime[i]);
    prev_max = max(prev_max, neededTime[i]);
  }
  return time;
}

int minimumLength(std::string s) {
  int n = s.size();
  int i = 0, j = n - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      break;
    }

    i += 1;
    j -= 1;

    while (i > 0 && i < j && s[i] == s[i - 1]) {
      i += 1;
    }

    while (j >= i && s[j] == s[j + 1]) {
      j -= 1;
    }
  }

  return j - i + 1;
}

std::vector<int> rearrangeNumbySign(std::vector<int> arr) {
  int n = arr.size();
  int p_index = 0, n_index = 1;
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if(arr[i] < 0) {  
      ans[n_index] = arr[i];
      n_index += 2;
    }
    else {
      ans[p_index] = arr[i];
      p_index += 2;
    }
  }
  return ans;
}

int main() {
  std::vector<int> arr = {1, 2, -4, -5};
  std::cout<<"Before Rearranging"<<std::endl;
  printArr(arr);

  std::cout<<"After Rearranging"<<std::endl;
  std::vector<int> ans = rearrangeNumbySign(arr);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output