/*
 * Coin Piles
 * 
 * https://cses.fi/problemset/task/1754
*/

#include <iostream>

using namespace std;
typedef long long ll;

void bruteForce() {
  ll a, b;
  cin >> a >> b;
  while (a > 0 && b > 0) {
    if (a > b) {
      a -= 2;
      b -= 1;
    } else {
      a -= 1;
      b -= 2;
    }
  }

  if (a == 0 && b == 0) {
    cout << "YES\n";
    return;
  }
  
  cout << "NO\n";
}

// * We are always subtracting 3 from total piles thats why we checked if sum is divisible by 3.
// * 'a' should be less than 2*b and 'b' should be less than 2*a
void coinPiles() {
  ll a, b;
  cin >> a >> b;
  if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    // bruteForce();
    coinPiles();
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-coin-piles.cpp -o output && ./output

/*
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/