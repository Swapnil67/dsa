/*
 * Leetcode - 726
 * Number of Atoms

 * Example 1
 * * Input       : formula = "H2O"
 * * Output      : "H2O"
 * * Explanation : The count of elements are {'H': 2, 'O': 1}.
 * 
 * Example 2
 * * Input       : formula = "Mg(OH)2"
 * * Output      : "H2MgO2"
 * * Explanation : The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
 * 
 * Example 3
 * * Input       : formula = "K4(ON(SO3)2)2"
 * * Output      : "K4N2O14S4"
 * * Explanation : The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 * 
 * https://leetcode.com/problems/parsing-a-boolean-expression/description/
*/


#include <map>
#include <stack>
#include <iostream>
#include <unordered_map>

std::string countOfAtoms(std::string formula) {
  int n = formula.size();

  std::stack<std::unordered_map<std::string, int>> st;
  st.push(std::unordered_map<std::string, int>());

  int i = 0;
  while (i < n) {
    if(formula[i] == '(') {
      // * push new map to stack top
      st.push(std::unordered_map<std::string, int>());
      i++;
    }
    else if (formula[i] == ')') {
      std::unordered_map<std::string, int> cur = st.top(); 
      st.pop();  // * pop the map from top of stack

      i++;

      // * check number of atoms
      std::string multiplerStr = "";
      while (i < n && isdigit(formula[i])) {
        multiplerStr += formula[i];
        i++;
      }

      // * Add multipler to cur map
      if(!multiplerStr.empty()) {
        int multipler = std::stoi(multiplerStr);

        for(auto &it: cur) {
          std::string element = it.first;
          int count = it.second;
          cur[element] *= multipler;
        }
      }

      // * merge the cur map with map on stack top
      for (auto &it : cur) {
        std::string element = it.first;
        int count = it.second;
        st.top()[element] += count;
      }
    }
    else {
      std::string curChemical = "";
      curChemical.push_back(formula[i]);
      i++;

      // * check if next char is 'alphabet' and in lower case
      while (i < n && isalpha(formula[i]) && islower(formula[i])) {
        curChemical.push_back(formula[i]);
        i++;
      }


      // * Get the count of atoms 
      std::string curCountStr = "";
      while (i < n && isdigit(formula[i])) {
        curCountStr.push_back(formula[i]);
        i++;
      }

      int curCountInteger = 1;
      if (curCountStr.length()) {
        curCountInteger = std::stoi(curCountStr);
      }

      // std::cout << curChemical << ":" << curCountInteger << std::endl;

      // * push the element to the stack top map
      st.top()[curChemical] += curCountInteger;
    }
  }

  std::map<std::string, int> sortedMap(begin(st.top()), end(st.top()));
  std::string result = "";

  for(auto &it: sortedMap) {
    std::string element = it.first;
    int count = it.second;

    result += element;
    if (count > 1)
      result += std::to_string(count);
  }

  return result;
}

int main() {
  // std::string formula = "H2O";
  // std::string formula = "Mg(OH)2";
  std::string formula = "K4(ON(SO3)2)2";
  std::cout << "Input formula: " << formula << std::endl;

  std::string ans = countOfAtoms(formula);
  std::cout << ans << std::endl;
  return 0;
}


// * run the code
// * g++ --std=c++20 -g 09-no-of-atoms.cpp -o output && ./output
