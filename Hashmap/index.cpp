#include<iostream>
#include<string>

int main() {
  std::vector<std::string> names = {"luffy", "zoro", "killua", "sakura", "sasuke", "zoro"};
  std::unordered_map<std::string, int> countMap;

  for (std::string& name: names) {
    if(countMap.count(name) == 0) {
      countMap[name] = 1;
    } else {
      countMap[name]++;
    }
  }

  // for(std::string it: countMap) {
  //   std::cout<<it<<std::endl;
  // }

  return 0;
}

/*
The above algorithm, when implemented using a hash map, is more efficient than using a tree map. With a tree map,
the insertion operation would cost O(log n) time and if n is the size of the array, it would total to O(n log n) time.
This only costs O(n) in the case of a hash map.
*/

// * Run the code
// * g++ --std=c++17 hashmap.cpp -o hashmap && ./hashmap