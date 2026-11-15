#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
typedef long long ll;

// * That means all the no. from 1 to i-1 divide N.
// * I can take LCM of all the no. from 1 to i - 1


// * TC = O(60) ~ O(logn)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // * Value of 'a' goes beyond 10^18 in just 60 operations.
  // ll a = 1;
  // for (ll i = 2; i <= 60; ++i) {
  //   a = lcm(a, i);
  //   cout << a << '\n';
  // }
    
  // * The above code will proves that modulo will not run till 10^18 
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    ll i = 1;
    while (n % i == 0)
      i++;

    cout << i - 1 << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-longest-divisors-interval.cpp -o output && ./output

// * testcases
/*
10
1
40
990990
4204474560
169958913706572972
365988220345828080
387701719537826430
620196883578129853
864802341280805662
1000000000000000000

*/


// * Output
/*
1
2
3
6
4
22
3
1
2
2

*/