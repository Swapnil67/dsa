/*
 * Minimize Max Distance to Gas Station 
*/

#include<iostream>
using namespace std;

int main() {
  vector<int> gasStations = { 1, 13, 17, 23 };
  int k = 5; // * add 5 more gas stations

  int n = gasStations.size();
  vector<int> howMany(n-1, 0);

  for(int newGasStation = 1; newGasStation <= k; newGasStation++) {
    long double maxSection = -1;
    int maxInd = -1;
    for(int i=0; i<n; i++) {
      long double diff = gasStations[i+1] - gasStations[i];
      long double sectionLength = diff / (long double)(howMany[i]+1);
      cout<<"maxSection "<<maxSection<<endl;
      cout<<"sectionLength "<<sectionLength<<endl;
      if(sectionLength > maxSection) {
        maxSection = sectionLength;
        maxInd = i;
      }
    }
    cout<<"maxInd "<<maxInd<<endl;
    howMany[maxInd]++;
  }

  long double maxAns = -1;
  for(int i=0; i<n; i++) {
    long double diff = gasStations[i+1] - gasStations[i];
    long double sectionLength = diff / (long double)(howMany[i]+1);
    maxAns = max(sectionLength, maxAns);
  }

  cout<<"maxAns "<<maxAns<<endl;
  return 0;
}