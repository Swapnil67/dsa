/*
 * Traffic Light
 * 
 * Description  : You are given a cyclic string s of length n representing the 
 *                sequence of traffic light colors ('r' for red, 'y' for yellow, 
 *                'g' for green). Given the current color c, find the minimum 
 *                number of seconds guaranteed to cross the road (reach a 'g') 
 *                in the worst-case scenario.
 * 
 * Constraints  : 1 <= t <= 10^4
 *                1 <= n <= 2 * 10^5, sum of n <= 2 * 10^5
 *                c is one of 'r', 'y', or 'g'
 * 
 * Example 1    :
 * Input        : n = 5, c = 'r', s = "rggry"
 * Output       : 3
 * Explanation  : If we are at the first 'r', the next 'g' is 1 second away. If we 
 *                are at the second 'r' (index 4), the light cycles back to index 1 
 *                yielding a distance of 3 seconds. The maximum worst-case is 3.
 * 
 * Example 2    :
 * Input        : n = 5, c = 'y', s = "yrrgy"
 * Output       : 4
 * Explanation  : If we are at the first 'y', the next 'g' is 3 seconds away. If we 
 *                are at the last 'y', the next 'g' is 4 seconds away. Worst-case is 4.
 *
 * https://codeforces.com/problemset/problem/1744/C
*/

// ! Observation

// * Track last green index while iterating backwards.
// * Double string 's'; track last 'g' index; compute max difference for color 'c'; output max_seconds.

#include<iostream>
using namespace std;

typedef long long ll;

ll solve() {
  int n;
  cin >> n;
  char color;
  cin >> color;
  string s;
  cin >> s;
  
  s = s + s;
  int N = s.length();
  
  // * Initialize variables to track the last seen green light index and 
  // * the maximum wait time
  ll last_green_idx = -1;
  ll max_seconds = INT_MIN;

  for (int i = N - 1; i >= 0; --i) {
    // * Update the last seen green light index
    if (s[i] == 'g') 
      last_green_idx = i;
    
    // * If the current color matches the given color, calculate the wait time
    if (s[i] == color) {
      ll diff = last_green_idx - i;
      max_seconds = max(max_seconds, diff);
    }
  }

  return max_seconds;
}

// ! String doubling Two Pointers
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 10-traffic-light.cpp -o output && ./output

// * testcases
/*
6
5 r
rggry
1 g
g
3 r
rrg
5 y
yrrgy
7 r
rgrgyrg
9 y
rrrgyyygy

*/

// * Output
/*
3
0
2
4
1
4
*/