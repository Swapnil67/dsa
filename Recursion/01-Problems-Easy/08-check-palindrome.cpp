#include<iostream>
using namespace std;

// * T(N) = O(N/2)
bool checkPalindrome(string s, int n, int i) {
  if(i >= n/2) return true;
  
  // cout<<"s[i] "<<s[i]<<" s[n-i-1] "<<s[n-i-1]<<endl;

  if(s[i] != s[n-i-1]) return false;
  return checkPalindrome(s, n, i+1);
}

int main() {
  string str = "mam";
  // string str = "mama";
  int n = str.size();
  bool isPalindrome = checkPalindrome(str, n, 0);
  cout<<"isPalindrome: "<<isPalindrome<<endl;
  return 0;
}