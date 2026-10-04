/*
 * DANCING PENGUINS
 * 
 * Description
 * There are N male penguins and N female penguins attending a grand dance party. 
 * In choosing their dance partners (always from the opposite gender), penguins 
 * give the utmost importance to their partner's height. 
 * 
 * Some penguins will only dance with a partner who is taller, while others will 
 * only dance with a partner who is shorter. No penguin will dance with a partner 
 * who is of the exact same height. 
 * 
 * To indicate this preference, a penguin's height is represented as:
 * - A positive value (+) if they want a partner who is TALLER than themselves.
 * - A negative value (-) if they want a partner who is SHORTER than themselves.
 * 
 * Find the maximum number of dancing pairs that can be formed while fulfilling 
 * everyone's height preferences. Each penguin can have at most one partner.
 * 
 * Constraints:
 * 1 <= N <= 100000
 * 1500 <= Absolute value of height <= 2500
 * 
 * Example 1    :
 * Input        : male = [-2000, 1500], female = [1800, -1900]
 * Output       : 2
 * Explanation  : There are 2 pairs that satisfy the conditions:
 *                1. Male (-2000) pairs with Female (1800) -> Male wants someone shorter (1800 < 2000) and Female wants someone taller (2000 > 1800).
 *                2. Male (1500) pairs with Female (-1900) -> Male wants someone taller (1900 > 1500) and Female wants someone shorter (1500 < 1900).
 * 
 * Example 2    :
 * Input        : male = [1600, 1700], female = [1800, 1900]
 * Output       : 0
 * Explanation  : All penguins in this pool want partners who are strictly taller than themselves, meaning no mutually agreeable pairs can be formed.
 * 
 * Example 3    :
 * Input        : male = [-1900, -2000, -2500, 1500, 1600, 2500, -2500], female = [1800, -1550, 2200, -1550, 2100, -2500, -1700]
 * Output       : 5
 * 
 * https://www.desiqna.in/18756/goldman-sachs-oa-2025-set-3-dancing-penguins
 * https://docs.google.com/document/d/12q07uL4qI9Uhdw11WVbMVcXIBtCgzUgLeUg1rxCT8HA/edit?tab=t.0
 * https://drive.google.com/file/d/1NxZYLtzjHnWXvCbqRCPrg4Vyd1siF0l0/view
 * 
*/

// ! OA
// ! Goldman Sachs

// ! Greedy + Two Pointer

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(N)
ll getMaxCouples(int n, vector<ll> M, vector<ll> F) {
  vector<ll> M1; // * Male wanting someone taller (+ve)
  vector<ll> M2; // * Male wanting someone shorter (-ve absolute)
  vector<ll> F1; // * Female wanting someone taller (+ve)
  vector<ll> F2; // * Female wanting someone shorter (-ve absolute)

  for (int i = 0; i < n; ++i) {
    if (M[i] < 0)
      if (M[i] < 0) M2.push_back(abs(M[i]));
      else M1.push_back(M[i]);

      if (F[i] < 0) F2.push_back(abs(F[i]));
      else F1.push_back(F[i]);
    }

  // * Sort all preference pools
  if (M1.size()) sort(all(M1));
  if (M2.size()) sort(all(M2));
  if (F1.size()) sort(all(F1));
  if (F2.size()) sort(all(F2));

  // * For Debug
  // printArr(M1);
  // printArr(M2);
  // printArr(F1);
  // printArr(F2);

  ll c = 0;
  ll i = 0, j = 0;

  // * 1. Match: Shorter-seeking Males (M2) + Taller-seeking Females (F1)
  // * Condition: Male height must be strictly greater than Female height
  while (i < M2.size() && j < F1.size()) {
    if (M2[i] > F1[j]) {
      cout << M2[i] << " " << F1[j] << endl;
      c++, i++, j++; 
    } else {
      i++; // * Current male is too short for this female; try a taller male
    }
  }

  // * 2. Match: Taller-seeking Males (M1) + Shorter-seeking Females (F2)
  // * Condition: Female height must be strictly greater than Male height
  i = 0, j = 0;
  while (i < M1.size() && j < F2.size()) {
    if (F2[j] > M1[i]) {
      // cout << M1[i] << " " << F2[j] << endl;
      c++, i++, j++;
    } else {
      j++; // * Current female is too short for this male; try a taller female
    }
  }

  return c;
}

int main(void) {
  // * testcase 1
  // int n = 2;
  // vector<ll> M = {-2000, 1500};
  // vector<ll> F = {1800, -1900};

  // * testcase 2
  int n = 7;
  vector<ll> M = {-1900, -2000, -2500, 1500, 1600, 2500, -2500};
  vector<ll> F = {1800, -1550, 2200, -1550, 2100, -2500, -1700};

  cout << "Male Penguins: ";
  printArr(M);
  cout << "Female Penguins: ";
  printArr(F);

  ll ans = getMaxCouples(n, M, F);
  cout << "Max Couples: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 05-dancing-penguins-goldman-sachs-oa.cpp -o output && ./output
