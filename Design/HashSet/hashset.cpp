#include<iostream>

class HashSet {
  public: 
    std::vector<int> hashSet;
    HashSet() {
    }

    void add(int key) {
      if(!contains(key)) {
        hashSet.push_back(key);
      }
    } 

    void remove(int key) {
      auto k = std::find(hashSet.begin(), hashSet.end(), key);
      if(k != hashSet.end()) {
        hashSet.erase(k);
      }
    }

    bool contains(int key) {
      return (std::find(hashSet.begin(), hashSet.end(), key) != hashSet.end());
    }
};

int main() {
  HashSet* HS1 = new HashSet();
  HS1->add(1);
  HS1->add(2);
  std::cout << "1 is in hashset: " << HS1->contains(1) << std::endl;
  std::cout << "3 is in hashset: " << HS1->contains(3) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 hashset.cpp -o hashset && ./hashset