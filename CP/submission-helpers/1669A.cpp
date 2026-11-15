#include <iostream>
using namespace std;

typedef long long ll;

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  
  while (t--) {
    ll rating;
    cin >> rating;
    
    if (rating >= 1900) {
      cout << "Division 1" << '\n';
    }
    else if (rating <= 1399) {
      cout << "Division 4" << '\n';
    }
    else if (rating >= 1600 && rating <= 1899) {
      cout << "Division 2" << '\n';
    }
    else if (rating >= 1400 && rating <= 1599) {
      cout << "Division 3" << '\n';
    }
  }
    
  return 0;
}

