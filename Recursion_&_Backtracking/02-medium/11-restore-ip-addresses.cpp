/*
 * Leetcode - 93
 * Restore IP Addresses
 * 
 * A valid IP address consists of exactly four integers separated by single dots. 
 * Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
 * 
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1"
 * are invalid IP addresses.
 * 
 * Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
 * You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 * Example 1
 * input       : s = "25525511135"
 * output      : ["255.255.11.135","255.255.111.35"]]

 * Example 2
 * input       : s = "0000"
 * output      : ["0.0.0.0"]

 * Example 3
 * input       : s = "101023"
 * output      : ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * https://leetcode.com/problems/restore-ip-addresses/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<std::string> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

bool isvalid(std::string s) {
  if (s[0] == '0')
    return false;
  int val = std::stoi(s);
  return val <= 255;
}

void solve(std::string &s, int idx,
           int parts, std::string ip,
           std::vector<std::string> &ans)
{
  // std::cout << ip << std::endl;
  if (idx == s.length() && parts == 4) {
    ip.pop_back(); // * removing the extra decimal from end
    ans.push_back(ip);
    return;
  }

  if (idx + 1 <= s.length())
  solve(s, idx + 1, parts + 1, ip + (s.substr(idx, 1) + "."), ans);

  if (idx + 2 <= s.length() && isvalid(s.substr(idx, 2)))
    solve(s, idx + 2, parts + 1, ip + (s.substr(idx, 2) + "."), ans);

  if (idx + 3 <= s.length() && isvalid(s.substr(idx, 3)))
    solve(s, idx + 3, parts + 1, ip + (s.substr(idx, 3) + "."), ans);
}

// * ------------------------- Approach : Optimal Approach -------------------------`
// * Where m = 3 as there are at most three digits in a valid segment
// * n = 4 as there are four segments in a valid IP.
// * TIME COMPLEXITY O(m^n * n)
// * SPACE COMPLEXITY O(m * n)
std::vector<std::string> restoreIpAddresses(std::string s) {
  std::vector<std::string> ans;
  int n = s.size();
  if (n > 12 || n < 4) // * Cannot form IP
    return ans;

  solve(s, 0, 0, "", ans);
  return ans;
}

int main(void) {
  std::string s = "25525511135";
  // std::string s = "0000";
  std::cout << "Input IP: " << s << std::endl;

  std::vector<std::string> ans = restoreIpAddresses(s);
  std::cout << "Restored IP Addresses" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-restore-ip-addresses.cpp -o output && ./output