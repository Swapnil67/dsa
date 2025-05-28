// TODO 

#include <iostream>
#include <stack>
#include <vector>
#include <string>

void printVectorString(std::vector<std::string>& strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << " ";
  }
  std::cout << "]" << std::endl;
}

void dump_stack(std::stack<int> st) {
  while(!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

int calPoints(std::vector<std::string> operations) {
  std::stack<int> st;
  int n = operations.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    std::string ops = operations[i];
    if(ops == "C") {
      sum -= st.top();
      st.pop();
    } else if(ops == "D") {
      int num = st.top();
      sum += (num * 2);
      st.push(num * 2);
    } else if(ops == "+") {
      int n1 = st.top();
      st.pop();
      int n2 = st.top();
      st.pop();
      int n3 = n1 + n2;
      st.push(n2);
      st.push(n1);
      st.push(n3);
      sum += n3;
    } else {
      // * String to Integer
      int n = std::stoi(ops);
      st.push(n);
      sum += n;
    }
  }

  // * For Debugging
  // dump_stack(st);
  return sum;
}

int main() {
  // std::vector<std::string> operations = {"5", "2", "+"};
  // std::vector<std::string> operations = {"5", "2", "C", "D", "+"};
  std::vector<std::string> operations = {"5", "-2", "4", "C", "D", "9", "+", "+"};

  printVectorString(operations);
  int ans = calPoints(operations);
  printf("sum of all the scores: %d\n", ans);
  return 0;
}

// * Run the code
// * $CXX 10-baseball-game.cpp -o output && ./output