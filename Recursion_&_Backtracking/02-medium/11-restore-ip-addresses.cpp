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

// ! Amazon, Google, Meta, Microsoft, Apple, Adobe, Oracle

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

bool isvalid(string s) {
  return (s[0] != '0') && (stoi(s) <= 255);
}

void solve(int idx, int parts,
           string &s, string ip,
           vector<string> &ans)
{
  // cout << ip << endl;
  if (idx == s.length() && parts == 4) {
    ip.pop_back(); // * removing the extra decimal from end
    ans.push_back(ip);
    return;
  }

  int n = s.length();
  // * take 1 digit
  if (idx + 1 <= n)
    solve(idx + 1, parts + 1, s, ip + (s.substr(idx, 1) + "."), ans);
  
  // * take 2 digits
  if (idx + 2 <= n && isvalid(s.substr(idx, 2)))
    solve(idx + 2, parts + 1, s, ip + (s.substr(idx, 2) + "."), ans);

  // * take 3 digits
  if (idx + 3 <= n && isvalid(s.substr(idx, 3)))
    solve(idx + 3, parts + 1, s, ip + (s.substr(idx, 3) + "."), ans);
}

// * ------------------------- Approach : Optimal Approach -------------------------`
// * Where m = 3 as there are at most three digits in a valid segment
// * n = 4 as there are four segments in a valid IP.
// * TIME COMPLEXITY O(m^n * n) ~ O(1)
// * SPACE COMPLEXITY O(m * n)  ~ O(1)
vector<string> restoreIpAddresses(string s) {
  vector<string> ans;
  int n = s.size();
  if (n > 12 || n < 4) // * Cannot form IP
    return ans;

  int parts = 0;
  solve(0, parts, s, "", ans);
  return ans;
}

int main(void) {
  // * testcase 1
  // string s = "25525511135";

  // * testcase 2
  // string s = "0000";

  // * testcase 3
  string s = "101023";

  cout << "Input IP: " << s << endl;

  vector<string> ans = restoreIpAddresses(s);
  cout << "Restored IP Addresses" << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-restore-ip-addresses.cpp -o output && ./output