#include<iostream>

class HashMap {
  public:
    int n = 9999;
    int *const hashArr = new int[n];

    HashMap() {}

    void put(int key, int value) {
      int idx = key % n;
      hashArr[idx] = value;
    }
};

int main() {
  std::cout << "HashMap" << std::endl;
  HashMap* hashmap = new HashMap();
  hashmap->put(10);
  return 0;
}

// * Run the code
// * g++ --std=c++17 hashmap.cpp -o hashmap && ./hashmap