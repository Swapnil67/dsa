/*
 * Jagged Swaps (Codeforces 1896A)
 * 
 * Description
 * You are given a permutation a of size n. You can perform the following operation:
 * Select an index i from 2 to n-1 such that a_i-1 < a_i and a_i > a_i+1. 
 * Then, swap a_i and a_i+1.
 * Determine whether it is possible to sort the permutation in increasing order 
 * after performing a finite number of operations.
 * 
 * Example 1    :
 * Input        : n = 3, a = [1, 2, 3]
 * Output       : YES
 * Explanation  : The array is already sorted, so 0 operations are needed.
 * 
 * Example 2    :
 * Input        : n = 5, a = [1, 2, 4, 5, 3]
 * Output       : YES
 * Explanation  : You can select index i = 4 (since a_3 < a_4 and a_4 > a_5, i.e., 2 < 5 and 5 > 3).
 *                Swapping a_4 and a_5 changes the array to [1, 2, 4, 3, 5].
 *                Then select index i = 3 (since 2 < 4 and 4 > 3) and swap to get [1, 2, 3, 4, 5].
 * 
 * Example 3    :
 * Input        : n = 4, a = [3, 2, 1, 4]
 * Output       : NO
 * Explanation  : Since operations can only be chosen from index 2 to n-1, the first element 
 *                a_1 can never be changed or swapped. Because a_1 = 3, it is impossible to 
 *                move it or make the array start with 1.
 * 
 * Example 4    :
 * Input        : n = 3, a = [2, 1, 3]
 * Output       : NO
 * Explanation  : The only valid index for an operation would be i = 2, but the condition 
 *                a_1 < a_2 (2 < 1) is false. Thus, no operations can be made, and the array 
 *                remains unsorted.
 * 
 * Example 5    :
 * Input        : n = 5, a = [5, 1, 2, 3, 4]
 * Output       : NO
 * Explanation  : The first element is 5, which cannot be moved because operations do not 
 *                alter the first index. The array cannot be sorted.
 * 
 * Example 6    :
 * Input        : n = 4, a = [1, 4, 2, 3]
 * Output       : YES
 * Explanation  : Select i = 2 (1 < 4 > 2), swap to get [1, 2, 4, 3].
 *                Then select i = 3 (2 < 4 > 3), swap to get [1, 2, 3, 4].
 * 
 * https://codeforces.com/problemset/problem/1896/A
 */

#include <vector>
#include <iostream>

using namespace std;

// ! Observation
// * If my first element is not 1 then its impossible to sort the array since we cannot swap that element.
// * Rest from 2 to n - 1 it is always possible to sort those elements.

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    if (a[0] != 1) 
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-jagged-swaps.cpp -o output && ./output

// * testcase
/*
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4
*/