#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::string bruteForce(std::string num) {
  std::string ans = "";
  int n = num.size();
  if(n < 3) return ans;

  for (int i = 0; i < n; i++) {
    ans = num[i];
    for (int j = i + 1; j < n; j++) {
      if(num[i] == num[j]) {
        ans += num[j];
        // std::cout << "ans: " << ans << std::endl;
        if(ans.size() == 3) {
          return ans;
        }
      }
      else {
        break;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string betterApproach(std::string num) {
  int n = num.size();
  std::string ans = "";
  if (n < 3)
    return ans;
  int c = 1;
  ans = num[0];
  for (int i = 0; i < n; i++) {
    if (num[i] == num[i + 1]) {
      c++;
      ans += num[i];
    }
    else {
      // std::cout << num[i] << " -> " << c << std::endl;
      if(c == 3) {
        return ans;
      }
      c = 1;
      ans = num[i + 1];
    }
    if(c == 3) {
      return ans;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * num[i] == num[i-1] && num[i] == num[i+1]
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string optimalApproach(std::string num) {
  int n = num.size();
  std::string ans = "";
  if(n < 3) return ans;

  for (int i = 0; i < n; i++) {
    bool found = false;
    if(i == 0) {
      // * Start
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
        found = true;
      }
    }
    else if (i == n - 1) {
      // * End
      if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
        found = true;
      }
    }
    else {
      // * Middle
      if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
        // std::cout << "i: " << i << " -> " << (int)num[i] << std::endl;
        found = true;
      }
    }
    if(found) {
      // * good string
      std::string temp = "";
      temp = num[i];
      temp += num[i];
      temp += num[i];
      ans = std::max(ans, temp);
    }
  }
  return ans;
}

int main() {
  std::string num = "6777133339";
  std::cout << num << std::endl;

  // std::string ans = bruteForce(num);
  std::string ans = optimalApproach(num);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-3-same-digit-no-str.cpp -o 11-3-same-digit-no-str && ./11-3-same-digit-no-str