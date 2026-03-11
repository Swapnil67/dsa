/*
 * Leetcode - ?
 * Divide Chocolate
 * 
 * You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.
 * 
 * You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 
 * pieces using k cuts, each piece consists of some consecutive chunks.
 * 
 * Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.
 * 
 * Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.
 * 
 * 
 * Example 1    :
 * Input        : nums = [1, -3, 2, 3, -4]
 * Output       : 5
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : nums = [1, -3, 2, 3, -4]
 * Output       : 5
 * Explanation  : 
 * 
*/

#include <vector>
#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

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
