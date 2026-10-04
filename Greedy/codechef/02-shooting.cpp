/*
 * Leetcode -  
 * NAME
 * 
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 * 
 * 
*/

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

vector<int> bruteForce(vector<int> &moves) {
  int m = moves.size();

  // * Create moves array for each player
  vector<int> arsiMoves(m, 0);
  vector<int> kryptoMoves(m, 0);
  for (int i = 0; i < m; ++i) {
    if (moves[i] == 1) { // * Aarsi move
      arsiMoves[i] = 1; 
    } else if (moves[i] == 2) { // * Krypto move
      kryptoMoves[i] = 1; 
    } else if (moves[i] == 3) { // * Both move
      arsiMoves[i] = 1; 
      kryptoMoves[i] = 1; 
    }
  }

  // * [ 0, 1, 1, 0, 1 ]

  // * [ 0 1, 2, 2, 3 ]

  vector<int> arsiMovesPefix(m + 1, 0);
  for (int i = 0; i < m; ++i) {
    // arsiMovesPefix[i] = arsiMovesPefix[i-1]+
  }
  // printArr(arsiMoves);
  // printArr(kryptoMoves);

  int kryptoCount = 0, arsiCount = 0;
}

vector<int> shooting(vector<int> &moves) {

}

int main(void) {
  // * testcase 1
  vector<int> moves = {2, 1, 3, 0, 1};
  
  // * testcase 2
  // vector<int> moves = {1, 1, 3, 0, 2, 0, 3, 3};

  cout << "moves: ";
  printArr(moves);

  // vector<int> ans = bruteForce(moves);
  vector<int> ans = shooting(moves);

  cout << "Answer: ";
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-shooting.cpp -o output && ./output
