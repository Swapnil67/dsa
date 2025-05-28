/**
 * * Leetcode - 1598
 * * Crawler Log Folder
 * 
 * * Example 1
 * * Input  : logs = ["d1/","d2/","../","d21/","./"]
 * * Output : 2
 * * Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
 * 
 * * Example 2
 * * Input  : logs = ["d1/","d2/","./","d3/","../","d31/"]
 * * Output : 0
 * 
 * * https://leetcode.com/problems/crawler-log-folder/description/
*/

#include <stack>
#include <vector>
#include <iostream>

void printVectorString(std::vector<std::string>& strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << '"' << s << '"' << ", ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minOperations(std::vector<std::string> logs) {
  int n = logs.size();
  std::stack<std::string> st;
  for(std::string &s : logs) {
    if(s == "../") {
      if (st.size())
        st.pop();
    }
    else if(s == "./") {
    }
    else {
      st.push(s);
    }
  }
  return st.size();
}

int main() {
  // * testcase 1
  // std::vector<std::string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  // * testcase 2
  std::vector<std::string> logs = {"d1/","d2/","./","d3/","../","d31/"};

  printVectorString(logs);

  int operations = minOperations(logs);
  std::cout << "Minimum operations required are: " << operations << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 13-crawler-log-folder.cpp -o output && ./output