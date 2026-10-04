/*
 * Don't Try to Count
 * 
 * Description
 * Given a string x of length n and a string s of length m, you can apply any number of 
 * operations to the string x. In one operation, you append the current value of x to the 
 * end of the string x (i.e., x = x + x). Note that the value of x changes after this.
 * 
 * Find the minimum number of operations after which s will appear in x as a substring. 
 * If it is impossible for s to ever become a substring of x, return -1.
 * 
 * Constraints:
 * 1 <= n, m <= 25
 * Strings x and s consist only of lowercase English letters.
 * 
 * Example 1    :
 * Input        : x = "a", s = "aaaaa"
 * Output       : 3
 * Explanation  : Operation 1: x becomes "aa"
 *                Operation 2: x becomes "aaaa"
 *                Operation 3: x becomes "aaaaaaaa"
 *                Now, s ("aaaaa") is a substring of x.
 * 
 * Example 2    :
 * Input        : x = "eforc", s = "force"
 * Output       : 1
 * Explanation  : Operation 1: x becomes "eforceforc".
 *                Now, s ("force") is a substring of x (starting from index 1).
 * 
 * Example 3    :
 * Input        : x = "aabb", s = "ba"
 * Output       : 1
 * Explanation  : Operation 1: x becomes "aabbaabb".
 *                Now, s ("ba") is a substring of x (starting from index 3).
 * 
 * https://codeforces.com/problemset/problem/1881/A
*/


#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
// * Just do the simulation
// * we are running only 5 times becoz we are exponentially increasing the size, also a, b <= 25

bool isSubstr(string s, string t) {
  ll n = s.length(), m = t.length();
  if (n < m)
    return false;
  for (int i = 0; i <= n - m; ++i) {
    if (s.substr(i, m) == t)
      return true;
  }
  return false;
}

ll solve() {
  ll n, m;
  cin >> n >> m;
  string x, s;
  cin >> x >> s;

  ll ops = 0;
  int i = 0;
  while (i <= 5) { // * You'll need max 5 ops
    if (isSubstr(x, s)) {
      return ops;
    }
    x += x;
    i++, ops++;
  }

  return -1;
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll min_ops = solve();
    cout << min_ops << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-dont-try-to-count.cpp -o output && ./output

// * testcase

/*
1
1 5
a
aaaaa

*/

/*
12
1 5
a
aaaaa
5 5
eforc
force
2 5
ab
ababa
3 5
aba
ababa
4 3
babb
bbb
5 1
aaaaa
a
4 2
aabb
ba
2 8
bk
kbkbkbkb
12 2
fjdgmujlcont
tf
2 2
aa
aa
3 5
abb
babba
1 19
m
mmmmmmmmmmmmmmmmmmm

*/


// * output
/*
3
1
2
-1
1
0
1
3
1
0
2
5
*/

