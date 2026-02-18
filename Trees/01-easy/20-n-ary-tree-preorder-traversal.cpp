/*
 * Leetcode - 589
 * N-ary Tree Preorder Traversal
 * 
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal. Each group of children
 * is separated by the null value (See examples)
 * 
 * Example 1    :
 * Input        : root = [1,null,3,2,4,null,5,6]
 * Output       : [1,3,5,6,2,4]
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output       : [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 * Explanation  : 
 * 
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/
*/

// * Do this on leetcode

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
