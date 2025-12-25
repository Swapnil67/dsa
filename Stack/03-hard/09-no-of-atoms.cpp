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
 * https://leetcode.com/problems/number-of-atoms/description/
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
    if (formula[i] == '(') { // * push new map to stack top
      st.push(std::unordered_map<std::string, int>());
      i++;
    }
    else if (formula[i] == ')') {
      std::unordered_map<std::string, int> cur = st.top(); 
      st.pop();  // * pop the map from top of stack

      i++; // * go to next character

      // * check number of atoms. Eg: (H2O)3
      int atoms = 0;
      while (i < n && isdigit(formula[i])) {
        atoms = (atoms * 10) + (formula[i] - '0');
        i++;
      }
      // * Add multipler to cur map. Eg: (H2O)3 => { H: 6, O: 3 }
      if (atoms > 0) {
        for (auto &[ele, cnt] : cur) {
          cur[ele] *= atoms;
        }
      }

      // * merge the cur map with map on stack top
      for (auto &[ele, cnt] : cur) {
        st.top()[ele] += cnt;
      }
    }
    else {
      // * start new chemical 
      std::string cur_chemical = "";
      cur_chemical.push_back(formula[i]);
      i++;

      // * check if next char is 'alphabet' and in lower case
      while (i < n && isalpha(formula[i]) && islower(formula[i])) {
        cur_chemical.push_back(formula[i]);
        i++;
      }

      // * Get the count of atoms 
      int atoms = 0;
      while (i < n && isdigit(formula[i])) {
        atoms = (atoms * 10) + (formula[i] - '0');
        i++;
      }
      atoms = (atoms == 0) ? 1 : atoms;
      // * push the element to the stack top map
      st.top()[cur_chemical] += atoms;
      // std::cout << cur_chemical << ":" << atoms << std::endl;
    }
  }

  // * Since the ans need to be in sorted order alphabetically
  std::string result = "";
  std::map<std::string, int> sortedMap(begin(st.top()), end(st.top()));

  for (auto &it : sortedMap) {
    result += it.first; // * Append the chemical component
    if (it.second > 1)
      result += std::to_string(it.second); // * Append the no. of atoms
  }

  return result;
}

int main() {
  // * testcase 1
  // std::string formula = "H2O";

  // * testcase 2
  // std::string formula = "Mg(OH)2";

  // * testcase 3
  // std::string formula = "K4(ON(SO3)2)2";

  // * testcase 4
  std::string formula = "H11He49NO35B7N46Li20";

  std::cout << "Input formula: " << formula << std::endl;

  std::string ans = countOfAtoms(formula);
  std::cout << ans << std::endl;
  return 0;
}


// * run the code
// * g++ --std=c++20 -g 09-no-of-atoms.cpp -o output && ./output
